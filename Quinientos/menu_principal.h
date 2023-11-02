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
                }
                return opcion;
            default:
                break;
        }
    }

}



#endif // MENU_PRINCIPAL_H_INCLUDED
