#ifndef JUGAR_PARTIDA_H_INCLUDED
#define JUGAR_PARTIDA_H_INCLUDED

void cargarNombre(char pal[][8], int tam, int jug){
    rlutil::cls();
    int i;
    for(int j=0; j<=jug; j++){
        solicitarNombreJugador(j+1);
        fflush(stdin);
        for(i=0; i<tam; i++)
        {
            pal[j][i]=cin.get();
            if(pal[j][i]=='\n') break;
        }
        rlutil::cls();
        pal[j][i]='\0';
        fflush(stdin);
    }
    rlutil::cls();
}

void hacerTirada(int *v){
    for(int i=0; i<6; i++ ){
        v[i]=(rand()%6)+1;
    }
}

void inicializarSemilla() {
    srand(time(NULL));
}

/// COMBINACIONES JUGADAS

bool escalera(int *v){
    for(int j=1;j<=6;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j){
                contador++;
            }
        }
        // Si no se encuentra un numero o se repite no hay escalera
        if(contador==0 || contador>1){
            return false;
        }
    }
    return true;
}

bool sextetoSeis(int *v){
    int contador=0;
    for(int i=0;i<6;i++){
        if(v[i]==6) {
            contador++;
        }
    }
    // Si se encuentra seis veces el 6 hay sexteto
    if (contador==6){
        return true;
    }
    return false;
}

int sexteto(int *v){
    int num=0;
    for(int j=1;j<=5;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j) {
                contador++;
            }
        }
        // Si se encuentra seis veces algun valor de j hay sexteto
        if(contador==6){
            num=j;
            return num*50;
        }
    }
    return 0;
}

int trio(int *v){
    int num=0;
    for(int j=1;j<=6;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j) {
                contador++;
            }
        }
        // SI SE encuentra una terna se guarda en num, si se encuentra otra
        // terna, se retorna la terna si es mayor
        if(contador>=3){
            if(num==0){
                num=j;
            }
            else if(j>num){
                return j*10;
            }
        }
    }
    // Si no se encontro terna, se devuelve 0, caso contrario el puntaje
    if(num!=0){
        return num*10;
    }
    return 0;
}

int sumaDeDados(int *v){
    int acumulador=0;
    for(int i=0;i<6;i++){
        acumulador+=v[i];
    }
    return acumulador;
}

/// PUNTAJES

void reiniciarPuntajeJugador(int *vAcuPuntajeJugador, int v[][20], int jugador){
    for(int i=0;i<20;i++){
        v[jugador][i]=0;
    }
    vAcuPuntajeJugador[jugador]=0;
}

int maximoPuntajeTiradas(int v[][3], int jugador){
    int maximo;
    for(int i=0;i<3;i++){
        if(i==0){
            maximo=v[jugador][i];
        }
        else if(v[jugador][i]>maximo){
            maximo=v[jugador][i];
        }
    }
    return maximo;
}

void cargarPuntajes(int mPuntajeRondaJugador[][20], int mPuntajesTiradas[][3], int *vAcuPuntajeJugador, int ronda, int jugador){
    mPuntajeRondaJugador[jugador][ronda]=maximoPuntajeTiradas(mPuntajesTiradas, jugador);
    vAcuPuntajeJugador[jugador]+=mPuntajeRondaJugador[jugador][ronda];
}

/// REINICIAR PARTIDA

void reiniciarPartida(int mTiradaMinimaQuinientos[][2], int mPuntajeRondaJugador[][20], int mPuntajesTiradas[][3], int *vAcuPuntajeJugador, int *vTiradasTotales, bool *vGanadorEscalera, bool *vGanadorQuinientos, int jugadores){
    int i;
    for(int j=0;j<jugadores;j++){
        vAcuPuntajeJugador[j]=0;
        vTiradasTotales[j]=0;
        vGanadorEscalera[j]=false;
        vGanadorQuinientos[j]=false;
        for(i=0;i<20;i++){
            mPuntajeRondaJugador[j][i]=0;
        }
        for(i=0;i<3;i++){
            mPuntajesTiradas[j][i]=0;
        }
        for(i=0;i<2;i++){
            mTiradaMinimaQuinientos[j][i]=0;
        }
    }
}

/// JUGAR RONDA

int ganadorMaximasRondas(int *vAcuPuntajeJugador, int jugadores){
    int maximoPuntaje, jugador, jugadorGanador;
    bool primerMaximo=false, empatePuntaje=false;
    for(jugador=0;jugador<jugadores;jugador++){
        if(!primerMaximo){
            primerMaximo=true;
            maximoPuntaje=vAcuPuntajeJugador[jugador];
            jugadorGanador=jugador;
        }
        else if(vAcuPuntajeJugador[jugador]==maximoPuntaje){
            empatePuntaje=true;
        }
        else if(vAcuPuntajeJugador[jugador]>maximoPuntaje){
            empatePuntaje=false;
            maximoPuntaje=vAcuPuntajeJugador[jugador];
            jugadorGanador=jugador;
        }
    }
    if(empatePuntaje){
        return maximoPuntaje;
    }
    return jugadorGanador;
}

int desempateQuinientos(bool *vGanadorQuinientos, int *vAcuPuntajeJugador, int mTiradaMinimaQuinientos[][2], int jugadores){
    int jugador, jugadorGanador, minimoTiradas, maximoPuntaje;
    bool primerMinimo=false, empateTiradas=false, primerMaximo=false, empatePuntaje=false;
    for(jugador=0;jugador<jugadores;jugador++){
        if(!primerMinimo){
            if(vGanadorQuinientos[jugador]){
                primerMinimo=true;
                minimoTiradas = mTiradaMinimaQuinientos[jugador][0];
                jugadorGanador = jugador;
            }
        }
        else if(vGanadorQuinientos[jugador]){
            if(mTiradaMinimaQuinientos[jugador][0]==minimoTiradas){
                empateTiradas=true;
            }
            else if(mTiradaMinimaQuinientos[jugador][0]<minimoTiradas){
                empateTiradas=false;
                minimoTiradas = mTiradaMinimaQuinientos[jugador][0];
                jugadorGanador = jugador;
            }
        }
    }
    if(empateTiradas){
        for(jugador=0;jugador<jugadores;jugador++){
            if(!primerMaximo){
                if(mTiradaMinimaQuinientos[jugador][0]==minimoTiradas){
                    primerMaximo=true;
                    maximoPuntaje = mTiradaMinimaQuinientos[jugador][1];
                    jugadorGanador = jugador;
                }
            }
            else if(mTiradaMinimaQuinientos[jugador][0]==minimoTiradas){
                if(mTiradaMinimaQuinientos[jugador][1]==maximoPuntaje){
                    empatePuntaje=true;
                }
                else if(mTiradaMinimaQuinientos[jugador][1]>maximoPuntaje){
                    empatePuntaje=false;
                    maximoPuntaje = mTiradaMinimaQuinientos[jugador][1];
                    jugadorGanador = jugador;
                }
            }
        }
    }
    if(empatePuntaje){
        return maximoPuntaje;
    }
    return jugadorGanador;
}

int desempateEscalera(bool *vGanadorEscalera, int *vAcuPuntajeJugador, int *vTiradasTotales, int jugadores){
    int jugador, jugadorGanador, maximoPuntos, minimoTiradas;
    bool primerMaximo=false, primerMinimo=false, empatePuntos=false, empateTiradas=false;
    for(jugador=0;jugador<jugadores;jugador++){
        if(!primerMaximo){
            if(vGanadorEscalera[jugador]){
                primerMaximo=true;
                maximoPuntos = vAcuPuntajeJugador[jugador];
                jugadorGanador = jugador;
            }
        }
        else if(vGanadorEscalera[jugador]){
            if(vAcuPuntajeJugador[jugador]==maximoPuntos){
                empatePuntos=true;
            }
            else if(vAcuPuntajeJugador[jugador]>maximoPuntos){
                empatePuntos=false;
                maximoPuntos = vAcuPuntajeJugador[jugador];
                jugadorGanador = jugador;
            }
        }
    }
    if(empatePuntos){
        for(jugador=0;jugador<jugadores;jugador++){
            if(!primerMinimo){
                if(vGanadorEscalera[jugador]){
                    primerMinimo=true;
                    minimoTiradas = vTiradasTotales[jugador];
                    jugadorGanador = jugador;
                }
            }
            else if(vGanadorEscalera[jugador]){
                if(vTiradasTotales[jugador]==minimoTiradas){
                    empateTiradas=true;
                }
                else if(vTiradasTotales[jugador]<minimoTiradas){
                    empateTiradas=false;
                    minimoTiradas = vTiradasTotales[jugador];
                    jugadorGanador = jugador;
                }
            }
        }
    }
    if(empateTiradas){
        if(maximoPuntos==0){
            return -1;
        }
        else{
            return maximoPuntos;
        }
    }
    return jugadorGanador;
}

void jugarRonda(int *vDados, int mPuntajesTiradas[][3], int mPuntajeRondaJugador[][20], bool *vGanadorEscalera, int *vTiradasTotales, char mJugadores[][8], int ronda, int jugadores, int *vAcuPuntajeJugador, int mTiradaMinimaQuinientos[][2], bool *vGanadorQuinientos){
    int jugador, tirada;
    switch(jugadores){
        case 1:
            jugador=0;
            for(tirada=0;tirada<3;tirada++){
                hacerTirada(vDados);
                datosPartidaJugador(mJugadores, mPuntajeRondaJugador, tirada, ronda, jugador, maximoPuntajeTiradas(mPuntajesTiradas, jugador), mPuntajesTiradas,vAcuPuntajeJugador);
                mostrarDados(vDados, jugador);
                vTiradasTotales[jugador]+=1;
                if(escalera(vDados)){
                    vGanadorEscalera[jugador]=true;
                    nombreJugada(4, jugador, 0);
                    return;
                }
                else if(sextetoSeis(vDados)){
                    reiniciarPuntajeJugador(vAcuPuntajeJugador, mPuntajeRondaJugador, jugador);
                    nombreJugada(5, jugador, 0);
                }
                else if(sexteto(vDados)){
                    mPuntajesTiradas[jugador][tirada]=sexteto(vDados);
                    nombreJugada(3, jugador, sexteto(vDados)/50);
                }
                else if(trio(vDados)){
                    mPuntajesTiradas[jugador][tirada]=trio(vDados);
                    nombreJugada(2, jugador, trio(vDados)/10);
                }
                else{
                    mPuntajesTiradas[jugador][tirada]=sumaDeDados(vDados);
                    nombreJugada(1, jugador, 0);
                }
                    mostrarPuntaje(mPuntajesTiradas[jugador][tirada], jugador);
                rlutil::anykey();
                rlutil::cls();
            }
            return;
        default:
            for(tirada=0;tirada<3;tirada++){
                for(jugador=0;jugador<jugadores;jugador++){
                    if(!vGanadorEscalera[jugador]){
                        hacerTirada(vDados);
                        datosPartidaJugador(mJugadores, mPuntajeRondaJugador, tirada, ronda, jugador, maximoPuntajeTiradas(mPuntajesTiradas, jugador), mPuntajesTiradas,vAcuPuntajeJugador);
                        mostrarDados(vDados, jugador);
                        vTiradasTotales[jugador]+=1;
                        if(escalera(vDados)){
                            vGanadorEscalera[jugador]=true;
                            nombreJugada(4, jugador, 0);
                        }
                        else if(sextetoSeis(vDados)){
                            reiniciarPuntajeJugador(vAcuPuntajeJugador, mPuntajeRondaJugador, jugador);
                            nombreJugada(5, jugador, 0);
                        }
                        else if(sexteto(vDados)){
                            mPuntajesTiradas[jugador][tirada]=sexteto(vDados);
                            nombreJugada(3, jugador, sexteto(vDados)/50);
                        }
                        else if(trio(vDados)){
                            mPuntajesTiradas[jugador][tirada]=trio(vDados);
                            nombreJugada(2, jugador, trio(vDados)/10);
                        }
                        else{
                            mPuntajesTiradas[jugador][tirada]=sumaDeDados(vDados);
                            nombreJugada(1, jugador, 0);
                        }
                        if((vAcuPuntajeJugador[jugador]+mPuntajesTiradas[jugador][tirada])>=500 && !vGanadorQuinientos[jugador]){
                            vGanadorQuinientos[jugador]=true;
                            mTiradaMinimaQuinientos[jugador][0]=vTiradasTotales[jugador];
                            mTiradaMinimaQuinientos[jugador][1]=vAcuPuntajeJugador[jugador]+mPuntajesTiradas[jugador][tirada];
                        }
                        mostrarPuntaje(mPuntajesTiradas[jugador][tirada],jugador);
                        rlutil::anykey();
                    }
                }
                rlutil::cls();
            }
            return;
    }
}

/// RANKING

void defaultRanking(int *vRankingPuntos, char mRanking[][8]){
    for(int i=0;i<10;i++){
        vRankingPuntos[i]=0;
        strcpy(mRanking[i], "AAA-AAA");
    }
    vRankingPuntos[2]=500;
    strcpy(mRanking[2], "KLT-LAB");
    vRankingPuntos[4]=500;
    strcpy(mRanking[4], "BRN-LAB");
    vRankingPuntos[6]=300;
    strcpy(mRanking[6], "ERN-RIV");
    vRankingPuntos[9]=310;
    strcpy(mRanking[9], "LUC-JKV");
    vRankingPuntos[3]=320;
    strcpy(mRanking[3], "FAC-CHE");
}

void ordenarRanking(int *vRankingPuntos, char mRanking[][8]){
    int puntosAux;
    char nombreAux[8];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(vRankingPuntos[i]>vRankingPuntos[j]){
                puntosAux=vRankingPuntos[j];
                vRankingPuntos[j]=vRankingPuntos[i];
                vRankingPuntos[i]=puntosAux;
                strcpy(nombreAux, mRanking[j]);
                strcpy(mRanking[j], mRanking[i]);
                strcpy(mRanking[i], nombreAux);
            }
        }
    }
}

void actualizarRanking(int *vRankingPuntos, char mRanking[][8], char mJugadores[][8], int *vAcuPuntajeJugador, int jugador, int jugadores){
    if(jugador!=-1 && jugador<jugadores){
        if(vAcuPuntajeJugador[jugador]>vRankingPuntos[9]){
            vRankingPuntos[9]=vAcuPuntajeJugador[jugador];
            strcpy(mRanking[9], mJugadores[jugador]);
            ordenarRanking(vRankingPuntos, mRanking);
        }
    }
}
#endif // JUGAR_PARTIDA_H_INCLUDED
