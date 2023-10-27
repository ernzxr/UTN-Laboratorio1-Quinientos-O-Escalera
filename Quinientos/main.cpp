#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "menu_principal.h"
#include "jugar_partida.h"

int main(){
    int opcion;
    char mJugadores[4][8], mRanking[10][8];
    int mPuntaje[4][10], vDados[6];

    /// MENU PRINCIPAL
    while(true){
        system("cls");
        opcion = menuPrincipal();
        switch(opcion){
            case 1:
                /// UN JUGADOR
                reiniciarPuntaje(mPuntaje, 10);
                cout<<"INGRESE SU NOMBRE [AAA AAA]: ";
                cargarNombre(mJugadores, 7, 1);
                //hacerTirada()
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
                            // se cambia opcion a -1 para no cerrar el while de MENU OPCIONES
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
                            // se cambia opcion a -1 para no cerrar el while de MENU OPCIONES
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
