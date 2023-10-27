#ifndef JUGAR_PARTIDA_H_INCLUDED
#define JUGAR_PARTIDA_H_INCLUDED

void cargarNombre(char pal[][8], int tam, int jug){
    int i;
    for(int j=0; j<jug; j++){
        fflush(stdin);
        for(i=0; i<tam; i++)
        {
            pal[j][i]=cin.get();
            if(pal[j][i]=='\n') break;
        }
        pal[j][i]='\0';
        fflush(stdin);
    }
}

void hacerTirada(int *v, int tam, int limite){
    srand(time(NULL));
    for(int i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
    }
}

int escalera(int *v, int numero, int tam){
    int cant=0;
    for(int i=0;i<tam;i++){
        if(v[i]==numero) cant++;
    }
    return cant;
}

int sexteto(int *v){
    int num=0;
    for(int j=1;j<=5;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j) {
                contador++;
            }
        }
        // Si se encuentra seis veces algun valor de j hay sexteto
        if(contador==6){
            num=j;
            return num*50;
        }
    }
    return 0;
}

bool escalera(int *v){
    for(int j=1;j<=6;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j){
                contador++;
            }
        }
        // Si no se encuentra un numero o se repite no hay escalera
        if(contador==0 || contador>1){
            return false;
        }
    }
    return true;
}

bool sextetoSeis(int *v){
    int contador=0;
    for(int i=0;i<6;i++){
        if(v[i]==6) {
            contador++;
        }
    }
    // Si se encuentra seis veces el 6 hay sexteto
    if (contador==6){
        return true;
    }
    return false;
}


int puntajeTirada(int *v, int tam){

}

void reiniciarPuntaje(int v[][10], int tam){
    for(int j=0;j<4;j++){
        for(int i=0;i<tam;i++){
            v[j][i]=0;
        }
    }
}



#endif // JUGAR_PARTIDA_H_INCLUDED
