#ifndef JUGAR_PARTIDA_H_INCLUDED
#define JUGAR_PARTIDA_H_INCLUDED

void cargarNombre(char pal[][8], int tam, int jug){
    rlutil::cls();
    int i;
    for(int j=0; j<=jug; j++){
        solicitarNombreJugador();
        fflush(stdin);
        for(i=0; i<tam; i++)
        {
            pal[j][i]=cin.get();
            if(pal[j][i]=='\n') break;
        }
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

void reiniciarPuntajeJugador(int v[][20], int jugador){
    for(int i=0;i<20;i++){
        v[jugador][i]=0;
    }
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

void reiniciarPartida(int mPuntajeRondaJugador[][20], int mPuntajesTiradas[][3], int *vAcuPuntajeJugador, int *vTiradasTotales, bool *vGanadorEscalera, bool *vGanadorQuinientos, int jugadores){
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
    }
}

/// JUGAR RONDA

int desempateQuinientos(bool *vGanadorQuinientos, int *vAcuPuntajeJugador, int mTiradaMinimaQuinientos[][2], int jugadores){
    int i, jugadorGanador, minimoTiradas, maximoPuntaje;
    bool primerMinimo=false, empateTiradas=false, primerMaximo=false, empatePuntaje=false;
    for(i=0;i<jugadores;i++){
        if(!primerMinimo){
            if(vGanadorQuinientos[i]){
                primerMinimo=true;
                minimoTiradas = mTiradaMinimaQuinientos[i][0];
                jugadorGanador = i;
            }
        }
        else if(vGanadorQuinientos[i]){
            if(mTiradaMinimaQuinientos[i][0]==minimoTiradas){
                empateTiradas=true;
            }
            else if(mTiradaMinimaQuinientos[i][0]<minimoTiradas){
                empateTiradas=false;
                minimoTiradas = mTiradaMinimaQuinientos[i][0];
                jugadorGanador = i;
            }
        }
    }
    if(empateTiradas){
        for(i=0;i<jugadores;i++){
            if(!primerMaximo){
                if(mTiradaMinimaQuinientos[i][0]==minimoTiradas){
                    primerMaximo=true;
                    maximoPuntaje=mTiradaMinimaQuinientos[i][1];
                    jugadorGanador = i;
                }
            }
            else if(mTiradaMinimaQuinientos[i][0]==minimoTiradas){
                if(mTiradaMinimaQuinientos[i][1]==maximoPuntaje){
                    empatePuntaje=true;
                }
                else if(mTiradaMinimaQuinientos[i][1]>maximoPuntaje){
                    empatePuntaje=false;
                    maximoPuntaje=mTiradaMinimaQuinientos[i][1];
                    jugadorGanador = i;
                }
            }
        }
    }
    if(empatePuntaje){
        return -1;
    }
    return jugadorGanador;
}

int desempateEscalera(bool *vGanadorEscalera, int *vAcuPuntajeJugador, int *vTiradasTotales, int jugadores){
    int i, jugadorGanador, maximoPuntos, minimoTiradas;
    bool primerMaximo=false, primerMinimo=false, empatePuntos=false, empateTiradas=false;
    for(i=0;i<jugadores;i++){
        if(!primerMaximo){
            if(vGanadorEscalera[i]){
                primerMaximo=true;
                maximoPuntos = vAcuPuntajeJugador[i];
                jugadorGanador = i;
            }
        }
        else if(vGanadorEscalera[i]){
            if(vAcuPuntajeJugador[i]==maximoPuntos){
                empatePuntos=true;
            }
            else if(vAcuPuntajeJugador[i]>maximoPuntos){
                empatePuntos=false;
                maximoPuntos = vAcuPuntajeJugador[i];
                jugadorGanador = i;
            }
        }
    }
    if(empatePuntos){
        for(i=0;i<jugadores;i++){
            if(!primerMinimo){
                if(vGanadorEscalera[i]){
                    primerMinimo=true;
                    minimoTiradas = vTiradasTotales[i];
                    jugadorGanador = i;
                }
            }
            else if(vGanadorEscalera[i]){
                if(vTiradasTotales[i]==minimoTiradas){
                    empateTiradas=true;
                }
                else if(vTiradasTotales[i]<minimoTiradas){
                    empateTiradas=false;
                    minimoTiradas = vTiradasTotales[i];
                    jugadorGanador = i;
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
    int jugador;
    switch(jugadores){
        case 1:
            jugador=0;
            for(int tirada=0;tirada<3;tirada++){
                hacerTirada(vDados);
                datosPartidaJugador(mJugadores, mPuntajeRondaJugador, tirada, ronda, jugador, maximoPuntajeTiradas(mPuntajesTiradas, jugador), mPuntajesTiradas);
                mostrarDados(vDados, jugador);
                vTiradasTotales[jugador]+=1;
                if(escalera(vDados)){
                    vGanadorEscalera[jugador]=true;
                    return;
                }
                else if(sextetoSeis(vDados)){
                    reiniciarPuntajeJugador(mPuntajeRondaJugador, jugador);
                }
                else if(sexteto(vDados)){
                    mPuntajesTiradas[jugador][tirada]=sexteto(vDados);
                }
                else if(trio(vDados)){
                    mPuntajesTiradas[jugador][tirada]=trio(vDados);
                }
                else{
                    mPuntajesTiradas[jugador][tirada]=sumaDeDados(vDados);
                }
                mostrarPuntaje(mPuntajesTiradas[jugador][tirada]);
                rlutil::anykey();
            }
            return;
        default:
            for(int tirada=0;tirada<3;tirada++){
                for(jugador=0;jugador<jugadores;jugador++){
                    if(!vGanadorEscalera[jugador]){
                        hacerTirada(vDados);
                        datosPartidaJugador(mJugadores, mPuntajeRondaJugador, tirada, ronda, jugador, maximoPuntajeTiradas(mPuntajesTiradas, jugador), mPuntajesTiradas);
                        mostrarDados(vDados, jugador);
                        vTiradasTotales[jugador]+=1;
                        if(escalera(vDados)){
                            vGanadorEscalera[jugador]=true;
                            cout<<"ESCALERA";
                            tirada=3;
                        }
                        else if(sextetoSeis(vDados)){
                            reiniciarPuntajeJugador(mPuntajeRondaJugador, jugador);
                        }
                        else if(sexteto(vDados)){
                            mPuntajesTiradas[jugador][tirada]=sexteto(vDados);
                        }
                        else if(trio(vDados)){
                            mPuntajesTiradas[jugador][tirada]=trio(vDados);
                        }
                        else{
                            mPuntajesTiradas[jugador][tirada]=sumaDeDados(vDados);
                        }
                        if((vAcuPuntajeJugador[jugador]+mPuntajesTiradas[jugador][tirada])>=500 && !vGanadorQuinientos[jugador]){
                            vGanadorQuinientos[jugador]=true;
                            mTiradaMinimaQuinientos[jugador][0]=tirada;
                            mTiradaMinimaQuinientos[jugador][1]=vAcuPuntajeJugador[jugador]+mPuntajesTiradas[jugador][tirada];
                        }
                    }
                mostrarPuntaje(mPuntajesTiradas[jugador][tirada]);
                }
                rlutil::anykey();
                }
                rlutil::anykey();
            }
            return;
    }

#endif // JUGAR_PARTIDA_H_INCLUDED
