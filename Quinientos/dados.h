#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

void dibujarCuadrado(int posx, int posy){
    rlutil::setColor(rlutil::WHITE);
    for(int x=0; x<7; x++){
        for(int y=0; y<3; y++){
            rlutil::locate(x+posx,y+posy);
            cout<<char(219)<<endl;
        }
    }
}

void dibujarPuntos(int numero, int posx, int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    switch(numero){
    case 1:
        rlutil::locate(posx+3, posy+1);
        cout<< (char) 254;
        break;

    case 2:
        rlutil::locate(posx+5, posy);
        cout<< (char) 220;

        rlutil::locate(posx+1, posy+2);
        cout<< (char) 223;

        break;
    case 3:
        rlutil::locate(posx+3, posy+1);
        cout<< (char) 254;

        rlutil::locate(posx+5, posy);
        cout<< (char) 220;

        rlutil::locate(posx+1, posy+2);
        cout<< (char) 223;

        break;
    case 4:
        rlutil::locate(posx+1, posy);
        cout<< (char) 220;

        rlutil::locate(posx+5, posy);
        cout<< (char) 220;

        rlutil::locate(posx+1, posy+2);
        cout<< (char) 223;

         rlutil::locate(posx+5, posy+2);
        cout<< (char) 223;

        break;
    case 5:
        rlutil::locate(posx+1, posy);
        cout<< (char) 220;

        rlutil::locate(posx+5, posy);
        cout<< (char) 220;

        rlutil::locate(posx+3, posy+1);
        cout<< (char) 254;

        rlutil::locate(posx+1, posy+2);
        cout<< (char) 223;

         rlutil::locate(posx+5, posy+2);
        cout<< (char) 223;

        break;
    case 6:
        rlutil::locate(posx+1, posy);
        cout<< (char) 220;

        rlutil::locate(posx+5, posy);
        cout<< (char) 220;

        rlutil::locate(posx+3, posy);
        cout<< (char) 220;

        rlutil::locate(posx+3, posy+2);
        cout<< (char) 223;

        rlutil::locate(posx+1, posy+2);
        cout<< (char) 223;

         rlutil::locate(posx+5, posy+2);
        cout<< (char) 223;

        break;
    }
}

void dibujarBorde(int posx,int posy){
    rlutil::setColor(rlutil::GREY);
    rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y=0; y<3; y++){
        rlutil::locate(posx+7, y+posy+1);
        cout<< (char)219 << endl;
    }
    for(int x=0; x<7; x++){
        rlutil::locate(x+posx+1, posy+3);
        cout<< (char)223 <<endl;

      }
        rlutil::locate(posx+7, posy);
        cout<< (char)220 <<endl;
}

void dibujarDado(int numero, int posx, int posy){
    dibujarCuadrado(posx,posy);
    dibujarPuntos(numero, posx, posy);
    dibujarBorde(posx,posy);
}

#endif // DADOS_H_INCLUDED
