#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

#include "rlutil.h"
#pragma comment(lib, "winmm.lib") /// VER .h
#include "menu_principal.h"
#include "jugar_partida.h"
#include "musica.h"
#include "color.h"

int main(){
    int const CANTIDAD_JUGADORES=4, TOP=10;
    int opcion, maxRondas, ronda, tiradasTotales, jugador, jugadores;
    int mPuntajeRondaJugador[CANTIDAD_JUGADORES][10], vTiradasTotales[CANTIDAD_JUGADORES], vAcuPuntajeJugador[CANTIDAD_JUGADORES], vDados[6], mPuntajesTiradas[CANTIDAD_JUGADORES][3];
    char mJugadores[CANTIDAD_JUGADORES][8], mRanking[TOP][8];
    bool escalera, quinientos, mute=false;
    bool vGanadorEscalera[CANTIDAD_JUGADORES];

    inicializarSemilla();

    colorFondo();

    while(true){
        rlutil::cls();
        if(!mute)musicaMenuPrincipal(); /// MUSICA
        opcion = menuPrincipal(); /// MENU PRINCIPAL
        switch(opcion){

            case 1:
                /// UN JUGADOR
                /// INICIALIZACION DE JUEGO
                // ELEGIR LA CANTIDAD DE RONDAS A JUGAR maxRondas ######-------#########
                maxRondas=10, ronda=0, tiradasTotales=0, jugador=1, jugadores=1;
                escalera=false, quinientos=false;

                if(!mute)playMusicaPartida(); /// MUSICA PARTIDA

                reiniciarPartida(mPuntajeRondaJugador, vAcuPuntajeJugador, vGanadorEscalera, vTiradasTotales, mPuntajesTiradas, CANTIDAD_JUGADORES);

                cargarNombre(mJugadores, 7, jugador-1);

                /// SE JUEGAN LA CANTIDAD MAXIMA DE RONDAS INDICADAS
                while(ronda<maxRondas && !escalera && !quinientos){
                    jugarRonda(vDados, mPuntajesTiradas, mPuntajeRondaJugador, vGanadorEscalera, vTiradasTotales, mJugadores, ronda+1, jugadores);

                    if(!vGanadorEscalera[jugador-1]){
                        /// GUARDAR MAXIMO PUNTAJE DE LAS TRES TIRADAS EN LA RONDA CORRESPONDIENTE
                        mPuntajeRondaJugador[jugador-1][ronda]=maximoPuntajeTiradas(mPuntajesTiradas, jugador-1);
                        mostrarPuntajeRonda(mPuntajeRondaJugador[jugador-1][ronda]);
                        vAcuPuntajeJugador[jugador-1]+=mPuntajeRondaJugador[jugador-1][ronda];
                        ronda++;

                        if(vAcuPuntajeJugador[jugador-1]>=500){
                            /// FINALIZA JUEGO POR SUMAR QUINIENTOS PUNTOS
                            quinientos=true;
                            terminarPartidaPorQuinientos(tiradasTotales, ronda, vAcuPuntajeJugador[jugador-1]);
                            cout<<mJugadores[jugador-1]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                        }
                        else{
                            mostrarPuntajeAcumulado(tiradasTotales, ronda, vAcuPuntajeJugador[jugador-1]);
                        }
                    }
                    else{
                        /// FINALIZA JUEGO POR SUMAR OBTENER ESCALERA
                        escalera=true;
                        ronda++;
                        terminarPartidaPorEscalera(tiradasTotales, ronda);
                        cout<<mJugadores[0]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                    }
                }
                if(ronda==maxRondas){
                    /// SE MUESTRA EL RESULTADO FINAL SI SE LLEGO AL MAXIMO DE RONDAS
                    terminarPartidaPorRondasMaximas(tiradasTotales, ronda, vAcuPuntajeJugador[jugador-1]);
                    cout<<mJugadores[0]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                }
                rlutil::anykey();
                break;
            case 2:
                /// MENU MULTIJUGADOR
                while(opcion != 0){
                rlutil::cls();
                opcion = menuMultijugador();
                    switch(opcion){
                        case 1:
                            /// DOS JUGADORES
                            /// INICIALIZACION DE JUEGO
                            // ELEGIR LA CANTIDAD DE RONDAS A JUGAR maxRondas ######-------#########
                            maxRondas=10, ronda=0, tiradasTotales=0, jugadores=2;
                            escalera=false, quinientos=false;

                            if(!mute)playMusicaPartida(); /// MUSICA PARTIDA

                            reiniciarPartida(mPuntajeRondaJugador, vAcuPuntajeJugador, vGanadorEscalera, vTiradasTotales, mPuntajesTiradas, CANTIDAD_JUGADORES);

                            cargarNombre(mJugadores, 7, jugadores-1); /// SE SOLICITAN DOS NOMBRES
                            cout<<"\n";
                            /// SE JUEGAN LA CANTIDAD MAXIMA DE RONDAS INDICADAS
                            while(ronda<maxRondas && !escalera && !quinientos){
                                jugarRonda(vDados, mPuntajesTiradas, mPuntajeRondaJugador, vGanadorEscalera, vTiradasTotales, mJugadores, ronda+1, jugadores);
                                ronda++;
                                for(int jugador=0;jugador<jugadores;jugador++){
                                    if(!vGanadorEscalera[jugador]){
                                        /// GUARDAR MAXIMO PUNTAJE DE LAS TRES TIRADAS EN LA RONDA CORRESPONDIENTE
                                        mPuntajeRondaJugador[jugador][ronda]=maximoPuntajeTiradas(mPuntajesTiradas, jugador);
                                        mostrarPuntajeRonda(mPuntajeRondaJugador[jugador][ronda]);
                                        vAcuPuntajeJugador[jugador]+=mPuntajeRondaJugador[jugador][ronda];
                                        if(vAcuPuntajeJugador[jugador]>=500){
                                            /// FINALIZA JUEGO POR SUMAR QUINIENTOS PUNTOS
                                            quinientos=true;
                                            terminarPartidaPorQuinientos(vTiradasTotales[jugador], ronda, vAcuPuntajeJugador[jugador]);
                                            cout<<mJugadores[jugador]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                                        }
                                        else{
                                            mostrarPuntajeAcumulado(vTiradasTotales[jugador], ronda, vAcuPuntajeJugador[jugador]);
                                        }
                                    }
                                    else{
                                        /// FINALIZA JUEGO POR SUMAR OBTENER ESCALERA
                                        escalera=true;
                                        terminarPartidaPorEscalera(vTiradasTotales[jugador], ronda);
                                        cout<<mJugadores[jugador]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                                    }
                                    if(ronda==maxRondas){
                                        /// SE MUESTRA EL RESULTADO FINAL SI SE LLEGO AL MAXIMO DE RONDAS
                                        terminarPartidaPorRondasMaximas(vTiradasTotales[jugador], ronda, vAcuPuntajeJugador[jugador]);
                                        cout<<mJugadores[jugador]<<endl; //ACOMODAR SALIDA DE NOMBRE ######-------#########
                                    }
                                }
                                rlutil::anykey();
                            }
                            rlutil::anykey();
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
                    rlutil::cls();
                    opcion = menuOpciones();
                    switch(opcion){
                        case 1:
                            /// SONIDO
                            while(opcion != 0){
                                rlutil::cls();
                                opcion = menuSonido();
                                switch(opcion){
                                    case 1:
                                        /// QUITAR SONIDO
                                        mute=true;
                                        stopMusica();
                                        break;
                                    case 2:
                                        /// PONER MUSICA
                                        mute=false;
                                        musicaMenuPrincipal();
                                        break;
                                    case 3:
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
                                rlutil::cls();
                                opcion = menuColor();
                                switch(opcion){
                                    case 1:
                                        ///COLOR AZUL
                                        cambiarColor();
                                        break;
                                    case 2:
                                        ///COLOR VIOLETA
                                        cambiarColor2();
                                        break;
                                    case 3:
                                        ///COLOR NEGRO
                                        cambiarColor3();
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
