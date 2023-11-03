#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int menuPrincipal(bool animacionInicial){
    int opcion = 1, maxOpciones = 5;
    if(!animacionInicial) {
        bordeHorizontalAnimado(35, 9, 50);
        bordeHorizontalAnimado(35, 17, 50);
        bordeVerticalAnimado(35, 10, 7);
        bordeVerticalAnimado(84, 10, 7);
        bordeVerticalAnimado(36, 10, 7);
        bordeVerticalAnimado(83, 10, 7);
    }
    else {
        bordeHorizontal(35, 9, 50, 178);
        bordeHorizontal(35, 17, 50, 178);
        bordeVertical(35, 10, 7, 178);
        bordeVertical(84, 10, 7, 178);
        bordeVertical(36, 10, 7, 178);
        bordeVertical(83, 10, 7, 178);
    }
    while(true) {
        for(int i=1; i<=maxOpciones; i++) {
            if(i == opcion) {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(48,10 + i);
                std::cout << (char)62 << std::endl;

            }
            else {
                rlutil::setColor(rlutil::WHITE);

            }
            rlutil::locate(50, 10 + i);
            switch (i) {
                case 1:
                    cout << "UN JUGADOR";
                    break;
                case 2:
                    cout << "MULTIJUGADOR";
                    break;
                case 3:
                    cout << "RANKING";
                    break;
                case 4:
                    cout << "OPCIONES";
                    break;
                case 5:
                    cout << "SALIR";
                    break;
            }
        }
       char tecla = rlutil::getkey();
        switch (tecla) {
            case 14:
                rlutil::locate(48,10 + opcion);
                std::cout <<" "<< std::endl;
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                rlutil::locate(48,10 + opcion);
                std::cout <<" "<< std::endl;
                opcion++;
                if (opcion > 5) {
                    opcion = 5;
                }
                break;
            case 1:
                if(opcion == 5) {
                    opcion = 0;
                }
                return opcion;
            default:
                break;
        }
    }
}

int menuMaxRondas(){
    int opcion = 1, maxOpciones = 4;
    bordeHorizontal(43, 10, 30, 196);
    bordeHorizontal(43, 17, 30, 196);
    bordeVertical(43, 11, 6, 24);
    bordeVertical(71, 11, 6, 25);
    while(true) {
        for(int i=1; i<=maxOpciones; i++) {
            if(i == opcion) {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(48,11 + i);
                std::cout << (char)62 << std::endl;
            }
            else {
                rlutil::setColor(rlutil::WHITE);
            }
            rlutil::locate(50, 11 + i);
            switch (i) {
                case 1:
                cout<<"1 RONDA "<<endl;
                break;
                case 2:
                cout<<"10 RONDAS "<<endl;
                break;
                case 3:
                cout<<"20 RONDAS "<<endl;
                break;
                case 4:
                cout<<"VOLVER "<<endl;
                default:
                break;
            }
        }
        char tecla = rlutil::getkey();
        switch (tecla) {
            case 14:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion++;
                if (opcion > 4) {
                    opcion = 4;
                }
                break;
            case 1:
                if(opcion == 4) {
                    opcion = 0;
                    rlutil::setColor(rlutil::WHITE);
                }
                return opcion;
            default:
                break;
        }
    }
}

int menuMultijugador(){
    int opcion = 1, maxOpciones = 4;
    bordeHorizontal(43, 10, 30, 196);
    bordeHorizontal(43, 17, 30, 196);
    bordeVertical(43, 11, 6, 24);
    bordeVertical(71, 11, 6, 25);
    while(true) {
        for(int i=1; i<=maxOpciones; i++) {
            if(i == opcion) {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(48,11 + i);
                std::cout << (char)62 << std::endl;
            }
            else {
                rlutil::setColor(rlutil::WHITE);
            }

            rlutil::locate(50, 11 + i);
            switch (i) {
                case 1:
                cout<<"DOS JUGADORES "<<endl;
                break;
                case 2:
                cout<<"TRES JUGADORES "<<endl;
                break;
                case 3:
                cout<<"CUATRO JUGADORES "<<endl;
                break;
                case 4:
                cout<<"VOLVER "<<endl;
                default:
                break;
            }
        }
        char tecla = rlutil::getkey();
        switch (tecla) {
            case 14:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion++;
                if (opcion > 4) {
                    opcion = 4;
                }
                break;
            case 1:
                if(opcion == 4) {
                    opcion = 0;
                    rlutil::setColor(rlutil::WHITE);
                }
                return opcion;
            default:
                break;
        }
    }
}

void mostrarRanking(int *vRankingPuntos, char mRanking[][8]){
    rlutil::cls();
    bordeHorizontal(40, 6, 29, 205);
    bordeHorizontal(40, 21, 29, 205);
    bordeVertical(40, 7, 14, 186);
    bordeVertical(68, 7, 14, 186);
    rlutil::locate(40,6);
    cout<<(char)201<<endl;
    rlutil::locate(40,21);
    cout<<(char)200<<endl;
    rlutil::locate(68,6);
    cout<<(char)187<<endl;
    rlutil::locate(68,21);
    cout<<(char)188<<endl;

    rlutil::locate(44, 8);
    cout<< "TOP";
    rlutil::locate(51, 8);
    cout<< "JUGADOR";
    rlutil::locate(62, 8);
    cout<< "PTS";
    for(int i=0;i<10;i++){
        rlutil::locate(45, 10 + i);
        cout<<i+1;
        rlutil::locate(51, 10 + i);
        cout<<mRanking[i];
        rlutil::locate(62, 10 + i);
        cout<<vRankingPuntos[i];
    }
    rlutil::anykey();
}

int menuMusica(){
    int opcion = 1, maxOpciones = 2;
     bordeHorizontal(40, 10, 30, 196);
     bordeHorizontal(40, 15, 30, 196);
     bordeVertical(40, 11, 4, 24);
     bordeVertical(70, 11, 4, 25);
        while(true) {
            for(int i=1; i<=maxOpciones; i++) {
                if(i == opcion) {
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(48,11 + i);
                    std::cout << (char)14 << std::endl;
                }
                else {
                    rlutil::setColor(rlutil::WHITE);
                }
                rlutil::locate(50, 11 + i);
                switch (i) {
                    case 1:
                    cout<<"MUSICA ON "<<endl;
                    break;
                    case 2:
                    cout<<"MUSICA OFF "<<endl;
                    break;
                    default:
                    break;
                }
            }
            char tecla = rlutil::getkey();
            switch (tecla) {
                case 14:
                    rlutil::locate(48,11 + opcion);
                    std::cout << " " << std::endl;
                    opcion--;
                    if (opcion < 1) {
                        opcion = 1;
                    }
                    break;
                case 15:
                    rlutil::locate(48,11 + opcion);
                    std::cout << " " << std::endl;
                    opcion++;
                    if (opcion > 2) {
                        opcion = 2;
                    }
                    break;
                case 1:
                    if(opcion == 2) {
                        opcion = 2;
                        rlutil::setColor(rlutil::WHITE);
                    }
                    return opcion;
                default:
                    break;
            }
        }
}

int menuOpciones(){
    int opcion = 1, maxOpciones = 3;
    bordeHorizontal(43, 10, 29, 196);
    bordeHorizontal(43, 16, 29, 196);
    bordeVertical(43, 11, 5, 24);
    bordeVertical(71, 11, 5, 25);
    while(true) {
        for(int i=1; i<=maxOpciones; i++) {
            if(i == opcion) {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(48,11 + i);
                std::cout << (char)62 << std::endl;
            }
            else {
                rlutil::setColor(rlutil::WHITE);
            }

            rlutil::locate(50, 11 + i);
            switch (i) {
                case 1:
                cout<<"MENU SONIDO "<<endl;
                break;
                case 2:
                cout<<"MENU COLOR "<<endl;
                break;
                case 3:
                cout<<"VOLVER AL INICIO "<<endl;
                break;
                default:
                break;
            }
        }
        char tecla = rlutil::getkey();
        switch (tecla) {
            case 14:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion++;
                if (opcion > 3) {
                    opcion = 3;
                }
                break;
            case 1:
                if(opcion == 3) {
                    opcion = 0;
                    rlutil::setColor(rlutil::WHITE);
                }
                return opcion;
            default:
                break;
        }
    }
}

int menuSonido(bool mute){
    int opcion = 1, maxOpciones = 4;
    bordeHorizontal(43, 10, 30, 196);
    bordeHorizontal(43, 16, 30, 196);
    bordeVertical(43, 11, 5, 24);
    bordeVertical(71, 11, 5, 25);
        while(true) {
            for(int i=1; i<=maxOpciones; i++) {
                if(i == opcion) {
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::locate(48,11 + i);
                    std::cout << (char)62 << std::endl;
                }
                else {
                    rlutil::setColor(rlutil::WHITE);
                }

                rlutil::locate(50, 11 + i);
                if(!mute) {
                    switch (i) {
                    case 1:
                    cout<<"QUITAR SONIDO"<<endl;
                    break;
                    case 2:
                    cout<<"CAMBIAR MUSICA"<<endl;
                    break;
                    case 3:
                    cout<<"VOLVER"<<endl;
                    break;
                    }
                }
                else {
                    switch (i) {
                    case 1:
                    cout<<"PONER SONIDO"<<endl;
                    break;
                    case 2:
                    cout<<"CAMBIAR MUSICA"<<endl;
                    break;
                    case 3:
                    cout<<"VOLVER"<<endl;
                    break;
                    }
                }
            }
            char tecla = rlutil::getkey();
            switch (tecla) {
                case 14:
                    rlutil::locate(48,11 + opcion);
                    std::cout << " " << std::endl;
                    opcion--;
                    if (opcion < 1) {
                        opcion = 1;
                    }
                    break;
                case 15:
                    rlutil::locate(48,11 + opcion);
                    std::cout << " " << std::endl;
                    opcion++;
                    if (opcion > 3) {
                        opcion = 3;
                    }
                    break;
                case 1:
                    if(opcion == 3) {
                        opcion = 0;
                        rlutil::setColor(rlutil::WHITE);
                    }
                    return opcion;
                default:
                    break;
            }
        }
}

int menuColor(){
    int opcion = 1, maxOpciones = 4;
    bordeHorizontal(43, 10, 30, 196);
    bordeHorizontal(43, 17, 30, 196);
    bordeVertical(43, 11, 6, 24);
    bordeVertical(71, 11, 6, 25);
    while(true) {
        for(int i=1; i<=maxOpciones; i++) {
            if(i == opcion) {
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(48,11 + i);
                std::cout << (char)62 << std::endl;
            }
            else {
                rlutil::setColor(rlutil::WHITE);
            }

            rlutil::locate(50, 11 + i);
            switch (i) {
                case 1:
                cout<<"COLOR AZUL "<<endl;
                break;
                case 2:
                cout<<"COLOR VIOLETA "<<endl;
                break;
                case 3:
                cout<<"POR DEFECTO "<<endl;
                break;
                case 4:
                cout<<"VOLVER "<<endl;
                break;
                default:
                break;
            }
        }
        char tecla = rlutil::getkey();
        switch (tecla) {
            case 14:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                rlutil::locate(48,11 + opcion);
                std::cout << " " << std::endl;
                opcion++;
                if (opcion > 4) {
                    opcion = 4;
                }
                break;
            case 1:
                if(opcion == 4) {
                    opcion = 0;
                    rlutil::setColor(rlutil::WHITE);
                }
                return opcion;
            default:
                break;
        }
    }
}
#endif // MENU_PRINCIPAL_H_INCLUDED
