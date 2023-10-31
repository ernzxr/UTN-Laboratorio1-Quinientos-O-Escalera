#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED



void colorMenuPrincipal(int numero){
        if(numero>4 || numero<0){
        rlutil::setColor(rlutil::RED);
         rlutil::locate(50, 17);
        cout<<"OPCION INCORRECTA ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();

    }
}
void colorMenuMultijugador(int numero){
        if(numero>3 || numero<0){
        rlutil::setColor(rlutil::RED);
        cout<<"OPCION INCORRECTA ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
     }
}
void menuOpciones(int numero){
        if(numero>2 || numero<0){
        rlutil::setColor(rlutil::RED);
        cout<<"OPCION INCORRECTA ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
     }
}
void menuColor(int numero){
        if(numero>3 || numero<0){
        rlutil::setColor(rlutil::RED);
        cout<<"OPCION INCORRECTA ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
     }
}
void menuSonido(int numero){
        if(numero>3 || numero<0){
        rlutil::setColor(rlutil::RED);
        cout<<"OPCION INCORRECTA ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
     }
}

void cambiarColor(){

    rlutil::setBackgroundColor(rlutil::BLUE);
}
void cambiarColor2(){

    rlutil::setBackgroundColor(rlutil::MAGENTA);
}
void cambiarColor3(){

    rlutil::setBackgroundColor(rlutil::BLACK);
}
void colorFondo(){
    rlutil::setBackgroundColor(rlutil::BLACK);
}

#endif // COLOR_H_INCLUDED
