#pragma comment(lib, "winmm.lib")

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

#include "rlutil.h"
#include "color.h"
#include "musica.h"
#include "dados.h"
#include "interfaz.h"
#include "menu_principal.h"
#include "jugar_partida.h"


int main(){
    int const CANTIDAD_JUGADORES=4, TOP=10;
    int opcion, opcionRondas, vRankingPuntos[TOP],maxRondas, ronda, tiradasTotales, jugador, jugadores, validarGanador, cQuinientos, cEscalera;
    int mPuntajeRondaJugador[CANTIDAD_JUGADORES][20], vTiradasTotales[CANTIDAD_JUGADORES], vAcuPuntajeJugador[CANTIDAD_JUGADORES], vDados[6], mPuntajesTiradas[CANTIDAD_JUGADORES][3], mTiradaMinimaQuinientos[CANTIDAD_JUGADORES][2];
    char mJugadores[CANTIDAD_JUGADORES][8], mRanking[TOP][8];
    bool escalera, quinientos, mute, desempate, iniciarPartida, volverInicio, animacionInicial=false;
    bool vGanadorEscalera[CANTIDAD_JUGADORES], vGanadorQuinientos[CANTIDAD_JUGADORES];


    defaultRanking(vRankingPuntos, mRanking);
    ordenarRanking(vRankingPuntos, mRanking);

    inicializarSemilla();
    colorFondo();
    rlutil::hidecursor();

    opcion = menuMusica();
    switch(opcion){
        case 1:
            mute=false;
            break;
        case 2:
            mute=true;
            break;
    }

    while(true){
        if(!mute)musicaMenuPrincipal(); /// MUSICA
        rlutil::cls();
        opcion = menuPrincipal(animacionInicial); /// MENU PRINCIPAL
        animacionInicial = true;
        switch(opcion){
            case 1:
                /// UN JUGADOR
                iniciarPartida=true;
                rlutil::cls();
                opcionRondas = menuMaxRondas();
                switch(opcionRondas){
                    case 1:
                        maxRondas=1;
                        break;
                    case 2:
                        maxRondas=10;
                        break;
                    case 3:
                        maxRondas=20;
                        break;
                    case 0:
                        iniciarPartida=false;
                        break;
                }
                while(iniciarPartida){
                    /// INICIALIZACION DE JUEGO
                    ronda=0, tiradasTotales=0, jugador=0, jugadores=1, escalera=false, quinientos=false;
                    reiniciarPartida(mTiradaMinimaQuinientos, mPuntajeRondaJugador, mPuntajesTiradas, vAcuPuntajeJugador, vTiradasTotales, vGanadorEscalera, vGanadorQuinientos, CANTIDAD_JUGADORES);
                    /// SE SOLICITA EL NOMBRE DEL JUGADOR
                    cargarNombre(mJugadores, 7, jugador);
                    /// MUSICA PARTIDA LUEGO DE ELEGIR NOMBRE
                    if(!mute)playMusicaPartida();
                    /// SE JUEGAN LA CANTIDAD MAXIMA DE RONDAS INDICADAS
                    while(ronda<maxRondas && !escalera && !quinientos){
                        /// SE JUEGA UNA RONDA DE TRES TIRADAS
                        ronda++;
                        jugarRonda(vDados, mPuntajesTiradas, mPuntajeRondaJugador, vGanadorEscalera, vTiradasTotales, mJugadores, ronda, jugadores, vAcuPuntajeJugador, mTiradaMinimaQuinientos, vGanadorQuinientos);
                        /// SE EVALUA SI UN JUGADOR OBTUVO ESCALERA
                        if(!vGanadorEscalera[jugador]){
                            /// SI NO HAY ESCALERA
                            /// SE CARGA EL PUNTAJE Y SE MUESTRA EL MAXIMO PUNTAJE DE LAS TRES TIRADAS EN LA RONDA
                            cargarPuntajes(mPuntajeRondaJugador, mPuntajesTiradas, vAcuPuntajeJugador, ronda-1, jugador);
                            mostrarPuntajeRonda(mPuntajeRondaJugador[jugador][ronda-1], jugador);
                            /// SE EVALUA SI EL JUGADOR LOGRO QUINIENTOS
                            if(vAcuPuntajeJugador[jugador]>=500){
                                /// FINALIZA JUEGO POR SUMAR QUINIENTOS PUNTOS
                                quinientos=true;
                                terminarPartidaPorQuinientos(mJugadores, vGanadorQuinientos, jugador, vTiradasTotales, ronda, vAcuPuntajeJugador[jugador], jugadores, mTiradaMinimaQuinientos, false);
                                /// ACTUALIZAR RANKING
                                actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, jugador, CANTIDAD_JUGADORES);
                            }
                            else{
                                /// SE MUESTRA EL PUNTAJE ACUMULADO
                                mostrarPuntajeAcumulado(tiradasTotales, ronda, vAcuPuntajeJugador[jugador], jugador);
                            }
                        }
                        else{
                            /// FINALIZA JUEGO POR OBTENER ESCALERA
                            escalera=true;
                            terminarPartidaPorEscalera(mJugadores, vGanadorEscalera, vAcuPuntajeJugador, vTiradasTotales, ronda, validarGanador, jugadores, false);
                            /// ACTUALIZAR RANKING
                            actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, jugador, CANTIDAD_JUGADORES);
                        }
                        /// FINALIZAR PARTIDA POR MAXIMO DE RONDAS
                        if(ronda==maxRondas){
                            terminarPartidaPorRondasMaximas(mJugadores, jugador, ronda, vAcuPuntajeJugador, jugadores);
                            /// ACTUALIZAR RANKING
                            actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, jugador, CANTIDAD_JUGADORES);
                        }
                        /// SE MUESTRA EL RESULTADO DE LA RONDA
                        else {
                            resultadosRonda(mJugadores, vAcuPuntajeJugador, ronda, jugadores);
                        }
                    }
                    if(!mute)musicaMenuPrincipal();
                    iniciarPartida=false;
                    opcion=0;
                }
                opcion=0;
                break;
            case 2:
                /// MENU MULTIJUGADOR
                while(opcion != 0){
                rlutil::cls();
                opcion = menuMultijugador();
                    switch(opcion){
                        case 1:
                            /// DOS JUGADORES
                            /// SE SELECCIONAN LA CANTIDAD DE RONDAS A JUGAR
                            iniciarPartida=true;
                            volverInicio=false;
                            rlutil::cls();
                            opcionRondas = menuMaxRondas();
                            switch(opcionRondas){
                                case 1:
                                    maxRondas=1;
                                    break;
                                case 2:
                                    maxRondas=10;
                                    break;
                                case 3:
                                    maxRondas=20;
                                    break;
                                case 0:
                                    iniciarPartida=false;
                                    break;
                            }
                            while(iniciarPartida){
                                /// INICIALIZACION DE JUEGO
                                ronda=0, tiradasTotales=0, jugadores=2, cQuinientos=0, cEscalera=0, escalera=false, quinientos=false;
                                reiniciarPartida(mTiradaMinimaQuinientos, mPuntajeRondaJugador, mPuntajesTiradas, vAcuPuntajeJugador, vTiradasTotales, vGanadorEscalera, vGanadorQuinientos, CANTIDAD_JUGADORES);
                                /// SE SOLICITAN LOS NOMBRES DE LOS JUGADORES
                                cargarNombre(mJugadores, 7, jugadores-1);
                                /// MUSICA PARTIDA LUEGO DE ELEGIR LOS NOMBRES
                                if(!mute)playMusicaPartida();
                                /// SE JUEGAN LA CANTIDAD MAXIMA DE RONDAS INDICADAS
                                while(ronda<maxRondas && !escalera && !quinientos){
                                    /// SE JUEGA UNA RONDA DE TRES TIRADAS POR JUGADOR
                                    ronda++;
                                    jugarRonda(vDados, mPuntajesTiradas, mPuntajeRondaJugador, vGanadorEscalera, vTiradasTotales, mJugadores, ronda, jugadores, vAcuPuntajeJugador, mTiradaMinimaQuinientos, vGanadorQuinientos);
                                    /// SE PROCESAN LOS DATOS OBTENIDOS DE LA RONDA PARA CADA JUGADOR
                                    for(jugador=0;jugador<jugadores;jugador++){
                                        /// SE EVALUA SI UN JUGADOR OBTUVO ESCALERA
                                        if(!vGanadorEscalera[jugador]){
                                            /// SI NO HAY ESCALERA
                                            /// SE CARGA EL PUNTAJE Y SE MUESTRA EL MAXIMO PUNTAJE DE LAS TRES TIRADAS EN LA RONDA
                                            cargarPuntajes(mPuntajeRondaJugador, mPuntajesTiradas, vAcuPuntajeJugador, ronda-1, jugador);
                                            mostrarPuntajeRonda(mPuntajeRondaJugador[jugador][ronda-1], jugador);
                                            /// SE EVALUA SI EL JUGADOR LOGRO QUINIENTOS
                                            if(vGanadorQuinientos[jugador]){
                                                /// SE ESPERA QUE TODOS LOS JUGADORES JUEGUEN
                                                /// FINALIZA JUEGO POR SUMAR QUINIENTOS PUNTOS
                                                cQuinientos++;
                                                quinientos=true;
                                            }
                                            else{
                                                /// SE MUESTRA EL PUNTAJE ACUMULADO
                                                mostrarPuntajeAcumulado(vTiradasTotales[jugador], ronda, vAcuPuntajeJugador[jugador], jugador);
                                            }
                                        }
                                        else{
                                            /// SE ESPERA QUE TODOS LOS JUGADORES JUEGUEN
                                            /// LUEGO FINALIZA JUEGO POR OBTENER ESCALERA
                                            cEscalera++;
                                            escalera=true;
                                        }
                                    }
                                    /// FINALIZAR PARTIDA POR ESCALERA Y VALIDACION PARA DESEMPATE
                                    if(escalera){
                                        /// SE EVALUA SI HUBO MAS DE UNA ESCALERA EN LA MISMA RONDA
                                        if(cEscalera>1){
                                            /// SE DESEMPATA POR MAYOR CANTIDAD DE PUNTOS Y LUEGO POR MINIMO CANTIDAD DE TIRADAS
                                            /// Y LUEGO SE MUESTRA AL GANADOR DEL DESEMPATE O SI HUBO EMPATE TOTAL
                                            desempate=true;
                                            validarGanador = desempateEscalera(vGanadorEscalera, vAcuPuntajeJugador, vTiradasTotales, jugadores);
                                            terminarPartidaPorEscalera(mJugadores, vGanadorEscalera, vAcuPuntajeJugador, vTiradasTotales, ronda, validarGanador, jugadores, desempate);
                                            /// ACTUALIZAR RANKING
                                            actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, validarGanador, CANTIDAD_JUGADORES);
                                        }
                                        else{
                                            /// SE MUESTRA AL GANADOR POR ESCALERA
                                            desempate=false;
                                            for(validarGanador=0;validarGanador<jugadores;validarGanador++){
                                                if(vGanadorEscalera[validarGanador]){
                                                    terminarPartidaPorEscalera(mJugadores, vGanadorEscalera, vAcuPuntajeJugador, vTiradasTotales, ronda, validarGanador, jugadores, desempate);
                                                    /// ACTUALIZAR RANKING
                                                    actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, validarGanador, CANTIDAD_JUGADORES);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    /// FINALIZAR PARTIDA POR QUINIENTOS Y VALIDACION PARA DESEMPATE
                                    else if(quinientos){
                                        if(cQuinientos>1){
                                            desempate=true;
                                            validarGanador = desempateQuinientos(vGanadorQuinientos, vAcuPuntajeJugador, mTiradaMinimaQuinientos, jugadores);
                                            terminarPartidaPorQuinientos(mJugadores, vGanadorQuinientos, validarGanador, vTiradasTotales, ronda, vAcuPuntajeJugador[jugador], jugadores, mTiradaMinimaQuinientos, desempate);
                                            /// ACTUALIZAR RANKING
                                            actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, validarGanador, CANTIDAD_JUGADORES);
                                        }
                                        else{
                                            /// SE MUESTRA AL GANADOR POR QUINIENTOS
                                            desempate=false;
                                            for(validarGanador=0;validarGanador<jugadores;validarGanador++){
                                                if(vGanadorQuinientos[validarGanador]){
                                                    terminarPartidaPorQuinientos(mJugadores, vGanadorQuinientos, validarGanador, vTiradasTotales, ronda, vAcuPuntajeJugador[validarGanador], jugadores, mTiradaMinimaQuinientos, desempate);
                                                    /// ACTUALIZAR RANKING
                                                    actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, validarGanador, CANTIDAD_JUGADORES);
                                                }
                                            }
                                        }
                                    }
                                    /// FINALIZAR PARTIDA POR MAXIMO DE RONDAS
                                    else if(ronda==maxRondas){
                                        validarGanador = ganadorMaximasRondas(vAcuPuntajeJugador, jugadores);
                                        terminarPartidaPorRondasMaximas(mJugadores, validarGanador, ronda, vAcuPuntajeJugador, jugadores);
                                        /// ACTUALIZAR RANKING
                                        actualizarRanking(vRankingPuntos, mRanking, mJugadores, vAcuPuntajeJugador, validarGanador, CANTIDAD_JUGADORES);
                                    }
                                    /// SE MUESTRA EL RESULTADO DE LA RONDA
                                    else {
                                        resultadosRonda(mJugadores, vAcuPuntajeJugador, ronda, jugadores);
                                    }
                                }
                                /// TERMINA LA PARTIDA Y SE VUELVE AL MENU PRINCIPAL
                                if(!mute)musicaMenuPrincipal();
                                iniciarPartida=false;
                                volverInicio=true;
                                opcion=0;
                            }
                            /// SE CAMBIA OPCION A -1 PARA VOLVER AL MENU MULTIJUGADOR SI NO SE JUEGA UNA PARTIDA
                            if(!volverInicio){
                                opcion=-1;
                            }
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
                    }
                }
                break;
            case 3:
                /// RANKING
                mostrarRanking(vRankingPuntos, mRanking);
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
                                }
                            }
                            /// SE CAMBIA OPCION A -1 PARA NO CERRAR EL WHILE DE MENU OPCIONES
                            opcion = -1;
                            break;
                        case 0:
                            /// VOLVER
                            break;
                    }
                }
                break;
            case 0:
                /// CERRAR JUEGO
                return 0;
        }
    }
}
