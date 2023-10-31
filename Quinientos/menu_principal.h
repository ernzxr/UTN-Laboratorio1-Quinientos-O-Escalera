#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED
#include "color.h"
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
    colorMenuPrincipal(num);

}

int menuMultijugador(){
    int num;
    cout<<"DOS JUGADORES [1]"<<endl;
    cout<<"TRES JUGADORES [2]"<<endl;
    cout<<"CUATRO JUGADORES [3]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    colorMenuMultijugador(num);
}

int menuOpciones(){
    int num;
    cout<<"SONIDO [1]"<<endl;
    cout<<"CAMBIAR COLOR [2]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    menuOpciones(num);
}

int menuColor(){
    int num;
    cout<<"COLOR AZUL [1]"<<endl;
    cout<<"COLOR VERDE [2]"<<endl;
    cout<<"POR DEFECTO[3]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    menuColor(num);
}

int menuSonido(){
    int num;
    cout<<"QUITAR SONIDO [1]"<<endl;
    cout<<"PONER SONIDO [2]"<<endl;
    cout<<"CAMBIAR MUSICA [3]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    menuSonido(num);
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
