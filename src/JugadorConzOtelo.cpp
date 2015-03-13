//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorConzOtelo.h"
//---------------------------------------------------------------------------
JugadorConzOtelo::JugadorConzOtelo(int n, FunHeuristicaOtelo FH)
{
        heuristica = FH;
        nivel = n;
};
//---------------------------------------------------------------------------
JugadorConzOtelo::~JugadorConzOtelo()
{

};
//---------------------------------------------------------------------------
Casilla JugadorConzOtelo::juega(const Juego2JTab &EJ)const
{
        if(!EJ.final())
        {
                Casilla cAux;
                if(!EJ.sePuedeAlguna(cAux))return Casilla(8,0);
                else
                {
                        Arbol2JTab arbol(EJ, nivel,(FunHeuristica2JTab) heuristica);
                        return arbol.buscaMejorJugada();
                }
        }
};
//---------------------------------------------------------------------------
int JugadorConzOtelo::HeuristicaDef(const Juego2JTab &EJ)
{
        int pesos[8][8]=
        {
                {50, -1,5,2,2,5, -1,50},
                {-1,-10,1,1,1,1,-10,-1},
                { 5, 1,1,1,1,1, 1, 5},
                { 2, 1,1,0,0,1, 1, 2},
                { 2, 1,1,0,0,1, 1, 2},
                { 5, 1,1,1,1,1, 1, 5},
                {-1,-10,1,1,1,1,-10,-1},
                {50, -1,5,2,2,5, -1,50}
        };
        int propio = 0;
        int contrario = 0;
        Turno aux;
        for(int i = 0; i < 8; i++)
        {
                for(int j = 0; j < 8; j++)
                {
                        aux = EJ.valorCasilla(i,j);
                        if(aux == EJ.dameTurno())
                        {
                                propio += pesos[i][j];
                        }
                        else if(aux != Jn)
                        {
                                contrario += pesos[i][j];
                        }
                }
        }
        return (propio - contrario);
};
//---------------------------------------------------------------------------
#pragma package(smart_init)

 