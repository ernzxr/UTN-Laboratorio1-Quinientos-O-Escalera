#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int menuPrincipal(){
    int opcion = 1, maxOpciones = 5;
    bordeHorizontal(35, 9, 50);
    bordeHorizontal(35, 17, 50);
    bordeVertical(35, 10, 7);
    bordeVertical(84, 10, 7);
    bordeVertical(36, 10, 7);
    bordeVertical(83, 10, 7);
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
                default:
                    cout << "OPCION INVALIDA";
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
            bordeHorizontal(43, 10, 30, 196);
            bordeHorizontal(43, 17, 30, 196);
            bordeVertical(43, 11, 6, 24);
            bordeVertical(71, 11, 6, 25);
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
            bordeHorizontal(43, 10, 30, 196);
            bordeHorizontal(43, 17, 30, 196);
            bordeVertical(43, 11, 6, 24);
            bordeVertical(71, 11, 6, 25);
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
    for(int i=0;i<10;i++){
        cout<<"TOP "<<i+1<<"  "<<vRankingPuntos[i]<<"  "<<mRanking[i]<<endl;
    }
    rlutil::anykey();
}

int menuMusica(){
    int opcion = 1, maxOpciones = 2;
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
                    bordeHorizontal(43, 10, 30, 196);
                    bordeHorizontal(43, 17, 30, 196);
                    bordeVertical(43, 11, 6, 24);
                    bordeVertical(71, 11, 6, 25);
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
            bordeHorizontal(43, 10, 30, 196);
            bordeHorizontal(43, 17, 30, 196);
            bordeVertical(43, 11, 6, 24);
            bordeVertical(71, 11, 6, 25);
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

int menuSonido(){
    int opcion = 1, maxOpciones = 4;
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
                bordeHorizontal(43, 10, 30, 196);
                bordeHorizontal(43, 17, 30, 196);
                bordeVertical(43, 11, 6, 24);
                bordeVertical(71, 11, 6, 25);
                rlutil::locate(50, 11 + i);
                switch (i) {
                    case 1:
                    cout<<"QUITAR SONIDO "<<endl;
                    break;
                    case 2:
                    cout<<"PONER SONIDO "<<endl;
                    break;
                    case 3:
                    cout<<"CAMBIAR MUSICA "<<endl;
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

int menuColor(){
    int opcion = 1, maxOpciones = 4;
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
            bordeHorizontal(43, 10, 30, 196);
            bordeHorizontal(43, 17, 30, 196);
            bordeVertical(43, 11, 6, 24);
            bordeVertical(71, 11, 6, 25);
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
