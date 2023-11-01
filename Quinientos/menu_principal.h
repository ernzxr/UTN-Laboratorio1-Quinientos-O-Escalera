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
            }
            else {
                rlutil::setColor(rlutil::WHITE);
            }

            rlutil::locate(50, 10 + i);
            cout<< i<< " - ";
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

        rlutil::resetColor();

        char tecla = rlutil::getkey();

        switch (tecla) {
            case 14:
                opcion--;
                if (opcion < 1) {
                    opcion = 1;
                }
                break;
            case 15:
                opcion++;
                if (opcion > 5) {
                    opcion = 5;
                }
                break;
            case 1:
                if(opcion == 5) {
                    opcion = 0;
                }
                rlutil::cls();
                return opcion;
            default:
                break;
        }
    }
}


int menuMultijugador(){
    int num;
    rlutil::locate(50, 9);
    cout<<"MULTIJUGADOR"<<endl;
    rlutil::locate(50, 11);
    cout<<"DOS JUGADORES [1]"<<endl;
    rlutil::locate(50, 12);
    cout<<"TRES JUGADORES [2]"<<endl;
    rlutil::locate(50, 13);
    cout<<"CUATRO JUGADORES [3]"<<endl;
    rlutil::locate(50, 14);
    cout<<"VOLVER [0]"<<endl;
    rlutil::locate(50, 15);
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}
int menuOpciones(){
    int num;
    rlutil::locate(50, 9);
    cout<<"MENU OPCIONES"<<endl;
    rlutil::locate(50, 11);
    cout<<"SONIDO [1]"<<endl;
    rlutil::locate(50, 12);
    cout<<"CAMBIAR COLOR [2]"<<endl;
    rlutil::locate(50, 13);
    cout<<"VOLVER [0]"<<endl;
    rlutil::locate(50, 14);
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}
int menuSonido(){
    int num;
    rlutil::locate(50, 9);
    cout<<"MENU SONIDO"<<endl;
    rlutil::locate(50, 11);
    cout<<"QUITAR SONIDO [1]"<<endl;
    rlutil::locate(50, 12);
    cout<<"PONER SONIDO [2]"<<endl;
    rlutil::locate(50, 13);
    cout<<"CAMBIAR MUSICA [3]"<<endl;
    rlutil::locate(50, 14);
    cout<<"VOLVER [0]"<<endl;
    rlutil::locate(50, 15);
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}
int menuColor(){
    int num;
    rlutil::locate(50, 9);
    cout<<"MENU COLOR"<<endl;
    rlutil::locate(50, 11);
    cout<<"COLOR AZUL [1]"<<endl;
    rlutil::locate(50, 12);
    cout<<"COLOR VIOLETA [2]"<<endl;
    rlutil::locate(50, 13);
    cout<<"POR DEFECTO[3]"<<endl;
    rlutil::locate(50, 14);
    cout<<"VOLVER [0]"<<endl;
    rlutil::locate(50, 15);
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}



#endif // MENU_PRINCIPAL_H_INCLUDED
