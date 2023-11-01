#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

/// INTERFAZ MENU PRINCIPAL

void bordeHorizontal(int x, int y, int limite) {
    for(int i=0; i<limite; i++) {
        rlutil::locate(x + i, y);
        cout<<(char)177;
    }

    for(int i=0; i<limite; i++) {
        rlutil::locate(x + i, y);
        cout<<(char)178;
        Sleep(5);
    }
}

void bordeVertical(int x, int y, int limite) {
    for(int i=0; i<limite; i++) {
        rlutil::locate(x, y + i);
        cout<<(char)177;

    }
    for(int i=0; i<limite; i++) {
        rlutil::locate(x, y + i);
        cout<<(char)178;
        Sleep(20);
    }
}

void lineaPunteadaHorizontal(int limite){
    for(int i=0; i<limite; i++) {
        cout<< "-";
    }
}




/// INTERFAZ UN JUGADOR

/// INTERFAZ DOS JUGADORES

void mostrarDados(int *v, int jugador){
    switch(jugador){
        case 0:
            dibujarDado(v[0],1,9);

            dibujarDado(v[1],10,9);

            dibujarDado(v[2],20,9);

            dibujarDado(v[3],30,9);

            dibujarDado(v[4],40,9);

            dibujarDado(v[5],50,9);

            return;
        case 1:
            dibujarDado(v[0],1,25);
            dibujarDado(v[1],10,25);
            dibujarDado(v[2],20,25);
            dibujarDado(v[3],30,25);
            dibujarDado(v[4],40,25);
            dibujarDado(v[5],50,25);
            return;
    }
}

void mostrarSalioEscalera(){
    cout<<endl;
    cout<<"ESCALERA!"<<endl;
    cout<<endl;
}

void mostrarPuntaje(int puntaje){
    cout<<endl;
    cout<<"PUNTAJE: "<<puntaje<<endl;
    cout<<endl;
}

void datosPartidaJugador(char mJugadores[][8], int mPuntajeJugadores[][10], int tirada, int ronda, int jugador, int maximoPuntajeTirada, int mPuntajesTiradas[][3]){
    switch(jugador){
        case 0:
            rlutil::locate(35, 13);
            lineaPunteadaHorizontal(57);
            rlutil::locate(40, 15);
            cout<<"TIRADA DE "<<mJugadores[jugador]<< " | "<< "RONDA NUMERO "<<ronda<< " | "<< "TIRADA NUMERO "<<tirada+1<<endl;
            rlutil::locate(52, 18);
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            rlutil::locate(52, 19);
            if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            rlutil::locate(52,20);
            cout<<"PUNTAJE: "<<mPuntajesTiradas[0][tirada]<<endl;
            rlutil::locate(35,22);
            lineaPunteadaHorizontal(57);
            return;
        case 1:
            cout<<"TIRADA DE: "<<mJugadores[jugador]<<endl;
            cout<<"RONDA NUMERO "<<ronda<<endl;
            cout<<"TIRADA NUMERO "<<tirada+1<<endl;
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            return;
    }
}

void mostrarTiradasYRondas(int tiradasTotales, int ronda){
    cout<<"TIRADAS: "<<tiradasTotales<<endl;
    cout<<"RONDAS JUGADAS: "<<ronda<<endl;
}

void solicitarNombreJugador(){
    cout<<"INGRESE SU NOMBRE [AAA-AAA]: ";
}

void terminarPartidaPorQuinientos(int tiradasTotales, int ronda, int puntaje){
    cout<<endl;
    cout<<"QUINIENTOS - GANASTE! "<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE OBTENIDO: "<<puntaje<<endl;
    cout<<endl;
}

void terminarPartidaPorEscalera(int tiradasTotales, int ronda){
    cout<<endl;
    cout<<"ESCALERA - GANASTE! "<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<endl;
}

void terminarPartidaPorRondasMaximas(int tiradasTotales, int ronda, int puntaje){
    cout<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE TOTAL: "<<puntaje<<endl;
    cout<<endl;
}



void mostrarPuntajeRonda(int puntajeRonda){
    cout<<endl;
    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<puntajeRonda<<endl;
}

void mostrarPuntajeAcumulado(int tiradasTotales, int ronda, int puntaje){
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE ACTUAL: "<<puntaje<<endl;
    cout<<endl;
}

#endif // INTERFAZ_H_INCLUDED
