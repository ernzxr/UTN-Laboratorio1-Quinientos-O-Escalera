#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int menuPrincipal(){
    int num;
    cout<<"BIENVENIDOS"<<endl;
    cout<<"UN JUGADOR [1]"<<endl;
    cout<<"MULTIJUGADOR [2]"<<endl;
    cout<<"RANKING [3]"<<endl;
    cout<<"OPCIONES [4]"<<endl;
    cout<<"SALIR [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}

int menuMultijugador(){
    int num;
    cout<<"DOS JUGADORES [1]"<<endl;
    cout<<"TRES JUGADORES [2]"<<endl;
    cout<<"CUATRO JUGADORES [3]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}

int menuOpciones(){
    int num;
    cout<<"SONIDO [1]"<<endl;
    cout<<"CAMBIAR COLOR [2]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}

int menuColor(){
    int num;
    cout<<"COLOR 1 [1]"<<endl;
    cout<<"COLOR 2 [2]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}

int menuSonido(){
    int num;
    cout<<"QUITAR SONIDO [1]"<<endl;
    cout<<"CAMBIAR MUSICA [2]"<<endl;
    cout<<"VOLVER [0]"<<endl;
    cout<<"ELIJA UNA OPCION: ";
    cin>>num;
    return num;
}

#endif // MENU_PRINCIPAL_H_INCLUDED
