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

void resultadosRonda(char mJugadores[][8], int *vAcuPuntajeJugador, int ronda, int jugadores){
    rlutil::cls();
    cout<<"RONDA N: "<<ronda<<endl;
    cout<<"PROXIMO TURNO: "<<mJugadores[0]<<endl;
    cout<<"PUNTAJE "<<mJugadores[0]<<": "<<vAcuPuntajeJugador[0]<<" PUNTOS"<<endl;
    cout<<"PUNTAJE "<<mJugadores[1]<<": "<<vAcuPuntajeJugador[1]<<" PUNTOS"<<endl;
    rlutil::anykey();
    rlutil::cls();
}

void mostrarDados(int *v, int jugador){
    switch(jugador){
        case 0:
            dibujarDado(v[0],8,7);
            dibujarDado(v[1],17,7);
            dibujarDado(v[2],26,7);
            dibujarDado(v[3],8,13);
            dibujarDado(v[4],17,13);
            dibujarDado(v[5],26,13);
            return;
        case 1:
            dibujarDado(v[0],104,7);
            dibujarDado(v[1],95,7);
            dibujarDado(v[2],86,7);
            dibujarDado(v[3],104,13);
            dibujarDado(v[4],95,13);
            dibujarDado(v[5],86,13);
            return;
    }
}

void mostrarSalioEscalera(){
    rlutil::locate(52,13);
    cout<<"ESCALERA!"<<endl;
}


/// ESTE MOSTRAR PUNTAJE VA A DESAPARECER EN EL MOMENTO QUE PONGAMOS TODO EN EL datosPartidaJugador()

void mostrarPuntaje(int puntaje){

    cout<<"PUNTAJE: "<<puntaje<<endl;

}

void datosPartidaJugador(char mJugadores[][8], int mPuntajeJugadores[][20], int tirada, int ronda, int jugador, int maximoPuntajeTirada, int mPuntajesTiradas[][3]){
    switch(jugador){
        case 0:
            rlutil::locate(2,1);
            cout<<"TIRADA DE: "<<mJugadores[jugador]<<endl;
            rlutil::locate(52,11);
            cout<<"RONDA NUMERO "<<(char)167<<ronda<<endl;
            rlutil::locate(2,5);
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            rlutil::locate(2,3);
            cout<<"LANZAMIENTO N"<<(char)167<<tirada+1<<endl;
            rlutil::locate(8,21);
            if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            return;
        case 1:
            rlutil::locate(86,1);
            cout<<"TIRADA DE: "<<mJugadores[jugador]<<endl;
           /* rlutil::locate(31,26);
            cout<<"RONDA NUMERO "<<(char)167<<ronda<<endl;*/
            rlutil::locate(86,5);
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            rlutil::locate(86,3);
            cout<<"LANZAMIENTO N"<<(char)167<<tirada+1<<endl;
            rlutil::locate(86,21);
            if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            return;
        /*case 2:

            rlutil::locate(4,33);
            cout<<"TIRADA DE: "<<mJugadores[jugador]<<endl;
            rlutil::locate(45,45);
            cout<<"RONDA NUMERO "<<(char)167<<ronda<<endl;
            rlutil::locate(56,67);
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            rlutil::locate(4,24);
            cout<<"LANZAMIENTO N"<<(char)167<<tirada+1<<endl;
            //if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            return;
        case 3:
            rlutil::locate(2,26);
            cout<<"TIRADA DE: "<<mJugadores[jugador]<<endl;
            rlutil::locate(31,26);
            cout<<"RONDA NUMERO "<<(char)167<<ronda<<endl;
            rlutil::locate(62,26);
            cout<<"PUNTAJE TOTAL ACTUAL "<<mPuntajeJugadores[jugador][ronda-1]<<endl;
            rlutil::locate(2,24);
            cout<<"LANZAMIENTO N"<<(char)167<<tirada+1<<endl;
            //if(tirada>0)cout<<"PUNTAJE PROVISORIO "<<maximoPuntajeTirada<<endl;
            return;
            */
    }
}

void mostrarTiradasYRondas(int tiradasTotales, int ronda){
   // cout<<"TIRADAS: "<<tiradasTotales<<endl;
   // cout<<"RONDAS JUGADAS: "<<ronda<<endl;
}
void solicitarNombreJugador(){

    cout<<"INGRESE SU NOMBRE [AAA-AAA]: ";
}

void terminarPartidaPorQuinientos(char mJugadores[][8], bool *vGanadorQuinientos, int validarGanador, int *vTiradasTotales, int ronda, int puntaje, int jugadores, int mTiradaMinimaQuinientos[][2], bool desempate){
    if(desempate){
            if(validarGanador<jugadores){
                rlutil::locate(48,7);
                cout<<"JUGADOR "<<mJugadores[validarGanador]<<endl;
                rlutil::locate(48,8);
                cout<<"GANO POR LLEGAR A QUINIENTOS!"<<endl;
                rlutil::locate(48,9);
                cout<<"PUNTAJE OBTENIDO: "<<puntaje<<endl;
                // mostrarTiradasYRondas(vTiradasTotales[validarGanador], ronda);
                rlutil::locate(48,10);
                cout<<"RONDAS JUGADAS: "<<ronda<<endl;
                rlutil::anykey();
        }
        else{
            int tiradasGanadores,x=8;
            rlutil::locate(48,7);
            cout<<"INSOLITO EMPATE POR QUINIENTOS ENTRE"<<endl;
            for(int jugador=0;jugador<jugadores;jugador++){
                if(vGanadorQuinientos[jugador] && mTiradaMinimaQuinientos[jugador][1]==validarGanador){
                    tiradasGanadores=jugador;
                    rlutil::locate(48,x);
                    cout<<"JUGADOR "<<mJugadores[jugador]<<endl;
                    x++;
                }
                }
                rlutil::locate(48,x);
                cout<<"RONDAS JUGADAS: "<<ronda<<endl;
                rlutil::anykey();
                //mostrarTiradasYRondas(vTiradasTotales[tiradasGanadores], ronda);
            }
            }
    else{
        rlutil::locate(48,7);
        cout<<"JUGADOR "<<mJugadores[validarGanador]<<endl;
        rlutil::locate(48,8);
        cout<<"GANO POR LLEGAR A QUINIENTOS!"<<endl;
        rlutil::locate(48,9);
        cout<<"PUNTAJE OBTENIDO: "<<puntaje<<endl;
        //mostrarTiradasYRondas(vTiradasTotales[validarGanador], ronda);
        rlutil::locate(48,10);
        cout<<"RONDAS JUGADAS: "<<ronda<<endl;
        rlutil::anykey();
    }
}

void terminarPartidaPorEscalera(char mJugadores[][8], bool *vGanadorEscalera, int *vAcuPuntajeJugador, int *vTiradasTotales, int ronda, int validarGanador, int jugadores, bool desempate){
    rlutil::cls();
    int jugador;
    if(desempate){
        if(validarGanador==-1){
            int x=8;
            rlutil::locate(48,7);
            cout<<"INSOLITO EMPATE POR ESCALERA ENTRE"<<endl;
            for(jugador=0;jugador<jugadores;jugador++){
                if(vGanadorEscalera[jugador] && vAcuPuntajeJugador[jugador]==0){
                    rlutil::locate(48,x);
                    cout<<"JUGADOR "<<mJugadores[jugador]<<endl;
                }
                    x++;
            }
                rlutil::locate(48,x);
                cout<<"RONDAS JUGADAS: "<<ronda<<endl;
                rlutil::anykey();
                //mostrarTiradasYRondas(1, ronda);

        }
        else if(validarGanador<jugadores){
            rlutil::locate(48,7);
            cout<<"EL GANADOR DEL DESEMPATE POR ESCALERA FUE"<<endl;
            rlutil::locate(48,8);
            cout<<"JUGADOR "<<mJugadores[validarGanador]<<endl;
            rlutil::locate(48,9);
            cout<<"RONDAS JUGADAS: "<<ronda<<endl;
            rlutil::anykey();
            //mostrarTiradasYRondas(vTiradasTotales[validarGanador], ronda);

        }
        else{
            int tiradasGanadores,x=8;
            rlutil::locate(48,7);
            cout<<"INSOLITO EMPATE POR ESCALERA ENTRE"<<endl;
            for(jugador=0;jugador<jugadores;jugador++){
                if(vGanadorEscalera[jugador] && vAcuPuntajeJugador[jugador]==validarGanador){
                    tiradasGanadores=jugador;
                    rlutil::locate(48,x);
                    cout<<"JUGADOR "<<mJugadores[jugador]<<endl;
                }
                    x++;
            }
                rlutil::locate(48,x);
                cout<<"RONDAS JUGADAS: "<<ronda<<endl;
                rlutil::anykey();
                //mostrarTiradasYRondas(vTiradasTotales[tiradasGanadores], ronda);
        }
    }
    else{
        rlutil::locate(48,7);
        cout<<"JUGADOR "<<mJugadores[validarGanador]<<endl;
        rlutil::locate(48,8);
        cout<<"GANO POR SACAR ESCALERA!"<<endl;
        rlutil::locate(48,9);
        cout<<"RONDAS JUGADAS: "<<ronda<<endl;
        rlutil::anykey();
        //mostrarTiradasYRondas(vTiradasTotales[validarGanador], ronda);

    }
}

void terminarPartidaPorRondasMaximas(char mJugadores[][8], int validarGanador, int ronda, int *vAcuPuntajeJugador, int jugadores){
    if(validarGanador<jugadores){
        rlutil::locate(48,7);
        cout<<"EL GANADOR LA PARTIDA FUE "<<mJugadores[validarGanador]<<endl;
        rlutil::locate(48,8);
        cout<<"CON UN TOTAL DE "<<vAcuPuntajeJugador[validarGanador]<<" PUNTOS"<<endl;
        rlutil::locate(48,9);
        cout<<"RONDAS JUGADAS: "<<ronda<<endl;
        rlutil::anykey();
    }
    else{
        int puntosGanadores,x=8;
        puntosGanadores = validarGanador;
        rlutil::locate(48,7);
        cout<<"INSOLITO EMPATE CON "<<puntosGanadores<<" PUNTOS"<<endl;
        for(int jugador=0;jugador<jugadores;jugador++){
            if(vAcuPuntajeJugador[jugador]==puntosGanadores){
                rlutil::locate(48,x);
                cout<<"JUGADOR "<<mJugadores[jugador]<<endl;
            }
            x++;
        }
        rlutil::locate(48,x);
        cout<<"RONDAS JUGADAS: "<<ronda<<endl;
        rlutil::anykey();
        //mostrarTiradasYRondas(vTiradasTotales[puntosGanadores], ronda);
    }
}

void mostrarPuntaje(int puntaje,int jugador){
    if(jugador==0){
        rlutil::locate(15,18);
        cout<<"PUNTAJE: "<<puntaje<<endl;
    }
    else{
        rlutil::locate(94,18);
        cout<<"PUNTAJE: "<<puntaje<<endl;

    }
}

void mostrarPuntajeRonda(int puntajeRonda, int jugador){
    if(jugador==0){

    rlutil::locate(8,19);
    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<puntajeRonda<<endl;
    }
    else {
        rlutil::locate(86,19);
    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<puntajeRonda<<endl;
    }
}

void mostrarPuntajeAcumulado(int tiradasTotales, int ronda, int puntaje, int jugador){
    if(jugador==0){
    mostrarTiradasYRondas(tiradasTotales, ronda);
    rlutil::locate(24,7);
    cout<<"PUNTAJE ACTUAL: "<<puntaje<<endl;
    }
    else {
    mostrarTiradasYRondas(tiradasTotales, ronda);
    rlutil::locate(86,23);
    cout<<"PUNTAJE ACTUAL: "<<puntaje<<endl;
    }
}

#endif // INTERFAZ_H_INCLUDED
