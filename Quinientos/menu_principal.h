#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int menuPrincipal(){
    int num, y=0;
    rlutil::locate(48, 11 + y);
    cout<< char(175)<<endl;
    rlutil::locate(50, 9);
    cout<<"BIENVENIDOS"<<endl;
    rlutil::locate(50, 11);
    cout<<"UN JUGADOR [1]"<<endl;
    rlutil::locate(50, 12);
    cout<<"MULTIJUGADOR [2]"<<endl;
    rlutil::locate(50, 13);
    cout<<"RANKING [3]"<<endl;
    rlutil::locate(50, 14);
    cout<<"OPCIONES [4]"<<endl;
    rlutil::locate(50, 15);
    cout<<"SALIR [0]"<<endl;
    rlutil::locate(50, 16);
    cin>>num;
    digitoErroneoMenu(num);

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
    DigitoErroneoMulti(num);
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
    DigitoErroneoOpc(num);
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
    DigitoErroneoMenuSonido(num);
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
    DigitoErroneoMenucolor(num);
}

void scrollMenu(int key, int y) {
    switch(key) {
        case 14:
            y--;
        break;
        case 15:
            y++;
        break;
        case 1:
        break;
    }
}

#endif // MENU_PRINCIPAL_H_INCLUDED
