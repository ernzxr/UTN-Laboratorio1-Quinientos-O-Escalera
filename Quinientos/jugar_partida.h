#ifndef JUGAR_PARTIDA_H_INCLUDED
#define JUGAR_PARTIDA_H_INCLUDED

void cargarNombre(char pal[][8], int tam, int jug){
    int i;
    for(int j=0; j<=jug; j++){
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

void solicitarNombreJugador(char nombre[][8], int tam, int jugador){
        cout<<"INGRESE SU NOMBRE [AAA-AAA]: ";
        cargarNombre(nombre, tam, jugador);
}

void hacerTirada(int *v){
    srand(time(NULL));
    for(int i=0; i<6; i++ ){
        v[i]=(rand()%6)+1;
    }
}

/// JUGADAS

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

int trio(int *v){
    int num=0;
    for(int j=1;j<=6;j++){
        int contador=0;
        for(int i=0;i<6;i++){
            if(v[i]==j) {
                contador++;
            }
        }
        // SI SE encuentra una terna se guarda en num, si se encuentra otra
        // terna, se retorna la terna si es mayor
        if(contador>=3){
            if(num==0){
                num=j;
            }
            else if(j>num){
                return j*10;
            }
        }
    }
    // Si no se encontro terna, se devuelve 0, caso contrario el puntaje
    if(num!=0){
        return num*10;
    }
    return 0;
}

int sumaDeDados(int *v){
    int acumulador=0;
    for(int i=0;i<6;i++){
        acumulador+=v[i];
    }
    return acumulador;
}

/// JUGAR RONDA

int maximoPuntajeTiradas(int *v){
    int maximo;
    for(int i=0;i<3;i++){
        if(i==0){
            maximo=v[i];
        }
        else if(v[i]>maximo){
            maximo=v[i];
        }
    }
    return maximo;
}

void reiniciarPuntajeJugador(int v[][10], int jugador){
    for(int i=0;i<10;i++){
        v[jugador][i]=0;
    }
}

void reiniciarResultados(int *v, int jugadores){
    for(int i=0;i<jugadores;i++){
        v[i]=0;
    }
}

void reiniciarPuntajes(int v[][10], int jugadores){
    for(int j=0;j<jugadores;j++){
        for(int i=0;i<10;i++){
            v[j][i]=0;
        }
    }
}

void mostrarTiradasYRondas(int tiradasTotales, int ronda){
    cout<<"TIRADAS: "<<tiradasTotales<<endl;
    cout<<"RONDAS JUGADAS: "<<ronda<<endl;
}

bool terminarPartidaPorQuinientos(int tiradasTotales, int ronda, int puntaje){
    cout<<endl;
    cout<<"QUINIENTOS - GANASTE! "<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE OBTENIDO: "<<puntaje<<endl;
    cout<<endl;
    return true;
}

void terminarPartidaPorEscalera(int tiradasTotales, int ronda){
    cout<<endl;
    cout<<"ESCALERA - GANASTE! "<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<endl;
}

void terminarPartidaPorRondasMaximas(int tiradasTotales, int ronda, int puntaje){
    cout<<endl;
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE TOTAL: "<<puntaje<<endl;
    cout<<endl;
}

void mostrarPuntajeAcumulado(int tiradasTotales, int ronda, int puntaje){
    mostrarTiradasYRondas(tiradasTotales, ronda);
    cout<<"PUNTAJE ACTUAL: "<<puntaje<<endl;
    cout<<endl;
}

void mostrarDados(int *v){
    for(int i=0;i<6;i++){
        cout<<v[i]<<" ";
    }
}

void mostrarPuntaje(int puntaje){
    cout<<endl;
    cout<<"PUNTAJE: "<<puntaje;
    cout<<endl;
}

void mostrarPuntajeRonda(int puntajeRonda){
    cout<<endl;
    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<puntajeRonda<<endl;
}

bool jugarRonda(int *vDados, int *vPuntajesTiradas, int mPuntajeJugadores[][10], int *tiradasTotales, int jugador){
    for(int tirada=0;tirada<3;tirada++){
        hacerTirada(vDados);
        mostrarDados(vDados);
        *tiradasTotales+=1;
        if(escalera(vDados)){
            return true;
        }
        else if(sextetoSeis(vDados)){
            reiniciarPuntajeJugador(mPuntajeJugadores, jugador);
            vPuntajesTiradas[tirada]=0;
        }
        else if(sexteto(vDados)){
            vPuntajesTiradas[tirada]=sexteto(vDados);
        }
        else if(trio(vDados)){
            vPuntajesTiradas[tirada]=trio(vDados);
        }
        else{
            vPuntajesTiradas[tirada]=sumaDeDados(vDados);
        }
        mostrarPuntaje(vPuntajesTiradas[tirada]);
        system("pause");
    }
    return false;
}

#endif // JUGAR_PARTIDA_H_INCLUDED
