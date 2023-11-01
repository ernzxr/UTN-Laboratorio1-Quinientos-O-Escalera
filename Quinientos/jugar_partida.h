#ifndef JUGAR_PARTIDA_H_INCLUDED
#define JUGAR_PARTIDA_H_INCLUDED

void cargarNombre(char pal[][8], int tam, int jug){
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

void reiniciarPuntajeJugador(int v[][10], int jugador){
    for(int i=0;i<10;i++){
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

/// REINICIAR PARTIDA

void reiniciarPartida(int v[][10], int *v2, bool *v3, int *v4, int v5[][3], int jugadores){
    for(int j=0;j<jugadores;j++){
        v2[j]=0;
        v3[j]=false;
        v4[j]=0;
        for(int i=0;i<10;i++){
            v[j][i]=0;
        }
        for(int i=0;i<3;i++){
            v5[j][i]=0;
        }
    }
}

/// JUGAR RONDA

void jugarRonda(int *vDados, int mPuntajesTiradas[][3], int mPuntajeJugadores[][10], bool *vGanadorEscalera, int *vTiradasTotales, char mJugadores[][8], int ronda, int jugadores){
    switch(jugadores){
        case 1:
            for(int tirada=0;tirada<3;tirada++){
                hacerTirada(vDados);
                datosPartidaJugador(mJugadores, mPuntajeJugadores, tirada, ronda, 0, maximoPuntajeTiradas(mPuntajesTiradas, 0));
                mostrarDados(vDados, 0);
                vTiradasTotales[0]+=1;
                if(escalera(vDados)){
                    vGanadorEscalera[0]=true;
                    return;
                }
                else if(sextetoSeis(vDados)){
                    reiniciarPuntajeJugador(mPuntajeJugadores, 0);
                    mPuntajesTiradas[0][tirada]=0; /// LA MATRIZ DE TIRADA TIENE QUE TENER UN VALOR YA QUE SE CALCULA UN MAXIMO
                }
                else if(sexteto(vDados)){
                    mPuntajesTiradas[0][tirada]=sexteto(vDados);
                }
                else if(trio(vDados)){
                    mPuntajesTiradas[0][tirada]=trio(vDados);
                }
                else{
                    mPuntajesTiradas[0][tirada]=sumaDeDados(vDados);
                }
                mostrarPuntaje(mPuntajesTiradas[0][tirada]);
                rlutil::anykey();
            }
            return;
        case 2:
            for(int tirada=0;tirada<3;tirada++){
                for(int jugador=0;jugador<2;jugador++){
                    if(!vGanadorEscalera[jugador]){
                        hacerTirada(vDados);
                        datosPartidaJugador(mJugadores, mPuntajeJugadores, tirada, ronda, jugador, maximoPuntajeTiradas(mPuntajesTiradas, jugador));
                        mostrarDados(vDados, jugador);
                        vTiradasTotales[jugador]+=1;
                        if(escalera(vDados)){
                            vGanadorEscalera[jugador]=true;
                        }
                        else if(sextetoSeis(vDados)){
                            reiniciarPuntajeJugador(mPuntajeJugadores, jugador);
                            mPuntajesTiradas[jugador][tirada]=0; /// LA MATRIZ DE TIRADA TIENE QUE TENER UN VALOR YA QUE SE CALCULA UN MAXIMO
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
                        if(!vGanadorEscalera[jugador]){
                            mostrarPuntaje(mPuntajesTiradas[jugador][tirada]);
                        }
                        else{
                            mostrarSalioEscalera();
                        }
                    }
                }
                rlutil::anykey();
            }
            return;
        case 3:
            return;
        case 4:
            return;
    }
}

#endif // JUGAR_PARTIDA_H_INCLUDED
