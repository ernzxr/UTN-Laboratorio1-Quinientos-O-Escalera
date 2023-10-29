#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "menu_principal.h"
#include "jugar_partida.h"

int main(){
    int const CANTIDAD_JUGADORES=4, TOP=10;
    int opcion, maxRondas, ronda, tiradasTotales, jugador;
    int mPuntajeJugadores[CANTIDAD_JUGADORES][10], vAcuPuntajesTotales[CANTIDAD_JUGADORES], vDados[6], vPuntajesTiradas[3];
    char mJugadores[CANTIDAD_JUGADORES][8], mRanking[TOP][8];
    bool escalera, quinientos;

    /// MENU PRINCIPAL
    while(true){

        system("cls");
        opcion = menuPrincipal();
        switch(opcion){
            case 1:
                /// UN JUGADOR
                /// INICIALIZACION DE JUEGO
                // ELEGIR LA CANTIDAD DE RONDAS A JUGAR maxRondas ######-------#########
                reiniciarPuntajes(mPuntajeJugadores, CANTIDAD_JUGADORES);
                reiniciarResultados(vAcuPuntajesTotales, CANTIDAD_JUGADORES);
                maxRondas=10, ronda=0, tiradasTotales=0, jugador=1;
                escalera=false, quinientos=false;

                solicitarNombreJugador(mJugadores, 7, jugador-1);

                /// SE JUEGAN LA CANTIDAD MAXIMA DE RONDAS INDICADAS
                while(ronda<maxRondas && !escalera && !quinientos){
                    /// EN FUNCION jugarRonda EL ULTIMO PARAMETRO ES EL NUMERO DE JUGADOR
                    escalera = jugarRonda(vDados, vPuntajesTiradas, mPuntajeJugadores, &tiradasTotales, jugador-1);
                    if(!escalera){
                        /// GUARDAR MAXIMO PUNTAJE DE LAS TRES TIRADAS EN LA RONDA CORRESPONDIENTE
                        mPuntajeJugadores[jugador-1][ronda]=maximoPuntajeTiradas(vPuntajesTiradas);
                        mostrarPuntajeRonda(mPuntajeJugadores[jugador-1][ronda]);
                        vAcuPuntajesTotales[jugador-1]+=mPuntajeJugadores[jugador-1][ronda];
                        ronda++;
                        if(vAcuPuntajesTotales[jugador-1]>=500){
                            /// FINALIZA JUEGO POR SUMAR QUINIENTOS PUNTOS
                            quinientos=terminarPartidaPorQuinientos(tiradasTotales, ronda, vAcuPuntajesTotales[jugador-1]);
                            cout<<mJugadores[0]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                        }
                        else{
                            mostrarPuntajeAcumulado(tiradasTotales, ronda, vAcuPuntajesTotales[jugador-1]);
                        }
                    }
                    else{
                        /// FINALIZA JUEGO POR SUMAR OBTENER ESCALERA
                        ronda++;
                        terminarPartidaPorEscalera(tiradasTotales, ronda);
                        cout<<mJugadores[0]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                    }
                }
                if(ronda==maxRondas){
                    /// SE MUESTRA EL RESULTADO FINAL SI SE LLEGO AL MAXIMO DE RONDAS
                    terminarPartidaPorRondasMaximas(tiradasTotales, ronda, vAcuPuntajesTotales[jugador-1]);
                    cout<<mJugadores[0]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                }
                system("pause");
                break;
            case 2:
                /// MENU MULTIJUGADOR
                while(opcion != 0){
                system("cls");
                opcion = menuMultijugador();
                    switch(opcion){
                        case 1:
                            /// DOS JUGADORES
                            break;
                        case 2:
                            /// TRES JUGADORES
                            break;
                        case 3:
                            /// CUATRO JUGADORES
                            break;
                        case 0:
                            /// VOLVER
                            break;
                        default:
                            cout<<"OPCION INVALIDA"<<endl;
                            break;
                    }
                }
                break;
            case 3:
                /// RANKING
                break;
            case 4:
                /// MENU OPCIONES
                while(opcion != 0){
                    system("cls");
                    opcion = menuOpciones();
                    switch(opcion){
                        case 1:
                            /// SONIDO
                            while(opcion != 0){
                                system("cls");
                                opcion = menuSonido();
                                switch(opcion){
                                    case 1:
                                        /// QUITAR SONIDO
                                        break;
                                    case 2:
                                        /// CAMBIAR MUSICA
                                        break;
                                    case 0:
                                        /// VOLVER
                                        break;
                                    default:
                                        cout<<"OPCION INVALIDA"<<endl;
                                        break;
                                }
                            }
                            /// SE CAMBIA OPCION A -1 PARA NO CERRAR EL WHILE DE MENU OPCIONES
                            opcion = -1;
                            break;
                        case 2:
                            /// CAMBIAR COLOR
                            while(opcion != 0){
                                system("cls");
                                opcion = menuColor();
                                switch(opcion){
                                    case 1:
                                        /// COLOR 1
                                        break;
                                    case 2:
                                        /// COLOR 2
                                        break;
                                    case 0:
                                        /// VOLVER
                                        break;
                                    default:
                                        cout<<"OPCION INVALIDA"<<endl;
                                        break;
                                }
                            }
                            /// SE CAMBIA OPCION A -1 PARA NO CERRAR EL WHILE DE MENU OPCIONES
                            opcion = -1;
                            break;
                        case 0:
                            /// VOLVER
                            break;
                        default:
                            cout<<"OPCION INVALIDA"<<endl;
                            break;
                    }
                }
                break;
            case 0:
                /// CERRAR JUEGO
                return 0;
            default:
                cout<<"OPCION INVALIDA"<<endl;
                break;
        }
    }
}
