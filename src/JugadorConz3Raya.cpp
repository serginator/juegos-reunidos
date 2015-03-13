//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorConz3Raya.h"
//---------------------------------------------------------------------------
JugadorConz3Raya::JugadorConz3Raya(int n, FunHeuristica3Raya FH)
{
        nivel = n;
        heuristica = FH;
};
//---------------------------------------------------------------------------
JugadorConz3Raya::~JugadorConz3Raya()
{

};
//---------------------------------------------------------------------------
Casilla JugadorConz3Raya::juega(const Juego2JTab &EJ)const
{
        if(!EJ.final())
        {
                Arbol2JTab arbol(EJ, nivel,(FunHeuristica2JTab) heuristica);
                return arbol.buscaMejorJugada();
        }
};
//---------------------------------------------------------------------------
int JugadorConz3Raya::HeuristicaDef(const Juego2JTab &EJ)
{
        int propio = 0;
        int contrario = 0;
        int contContrario = 0;
        int contPropio = 0;
        int raya = 0;
        Turno auxT;
        Turno turno = EJ.dameTurno();
        //horizontal
        for(int j = 0; j < 3; j++)
        {
                contContrario = 0;
                contPropio = 0;
                raya = 0;
                for(int i = 0; i < 3; i++)
                {
                        auxT = EJ.valorCasilla(i, j);
                        if(auxT == turno)
                        {
                                if(contContrario != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contPropio++;
                                raya++;
                                if(raya == 3)
                                {
                                        propio += pow(10, contPropio);
                                        raya = 0;
                                        contPropio = 0;
                                }
                        }
                        else if(auxT != Jn)
                        {
                                if(contPropio != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contContrario++;
                                raya++;
                                if(raya == 3)
                                {
                                        contrario += pow(10, contContrario);
                                        raya = 0;
                                        contContrario = 0;
                                }
                        }
                        else
                        {
                                raya++;
                                if(raya == 3)
                                {
                                        if(contContrario != 0)contrario += pow(10, contContrario);
                                        if(contPropio != 0)propio += pow(10, contPropio);
                                        raya = 0;
                                        contContrario = 0;
                                        contPropio = 0;
                                }
                        }
                }
        }

        //vertical
        for(int i = 0; i < 3; i++)
        {
                contContrario = 0;
                contPropio = 0;
                raya = 0;
                for(int j = 0; j < 3; j++)
                {
                        auxT = EJ.valorCasilla(i, j);
                        if(auxT == turno)
                        {
                                if(contContrario != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contPropio++;
                                raya++;
                                if(raya == 3)
                                {
                                        propio += pow(10, contPropio);
                                        raya = 0;
                                        contPropio = 0;
                                }
                        }
                        else if(auxT != Jn)
                        {
                                if(contPropio != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contContrario++;
                                raya++;
                                if(raya == 3)
                                {
                                        contrario += pow(10, contContrario);
                                        raya = 0;
                                        contContrario = 0;
                                }
                        }
                        else
                        {
                                raya++;
                                if(raya == 3)
                                {
                                        if(contContrario != 0)contrario += pow(10, contContrario);
                                        if(contPropio != 0)propio += pow(10, contPropio);
                                        raya = 0;
                                        contContrario = 0;
                                        contPropio = 0;
                                }
                        }
                }
        }

        //diagonal arribaizq derabajo

        int j = 0;
        contContrario = 0;
        contPropio = 0;
        raya = 0;
        for(int i = 0; i < 3; i++)
        {
                        auxT = EJ.valorCasilla(i, j);
                        if(auxT == turno)
                        {
                                if(contContrario != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contPropio++;
                                raya++;
                                if(raya == 3)
                                {
                                        propio += pow(10, contPropio);
                                        raya = 0;
                                        contPropio = 0;
                                }
                        }
                        else if(auxT != Jn)
                        {
                                if(contPropio != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contContrario++;
                                raya++;
                                if(raya == 3)
                                {
                                        contrario += pow(10, contContrario);
                                        raya = 0;
                                        contContrario = 0;
                                }
                        }
                        else
                        {
                                raya++;
                                if(raya == 3)
                                {
                                        if(contContrario != 0)contrario += pow(10, contContrario);
                                        if(contPropio != 0)propio += pow(10, contPropio);
                                        raya = 0;
                                        contContrario = 0;
                                        contPropio = 0;
                                }
                        }
                        j++;
        }

        //diagonal derarriba izqabajo
        contContrario = 0;
        contPropio = 0;
        raya = 0;
        j = 0;
        for(int i = 2; i >= 0; i--)
        {
                        auxT = EJ.valorCasilla(i, j);
                        if(auxT == turno)
                        {
                                if(contContrario != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contPropio++;
                                raya++;
                                if(raya == 3)
                                {
                                        propio += pow(10, contPropio);
                                        raya = 0;
                                        contPropio = 0;
                                }
                        }
                        else if(auxT != Jn)
                        {
                                if(contPropio != 0)
                                {
                                        contPropio = 0;
                                        contContrario = 0;
                                        raya = 0;
                                }
                                contContrario++;
                                raya++;
                                if(raya == 3)
                                {
                                        contrario += pow(10, contContrario);
                                        raya = 0;
                                        contContrario = 0;
                                }
                        }
                        else
                        {
                                raya++;
                                if(raya == 3)
                                {
                                        if(contContrario != 0)contrario += pow(10, contContrario);
                                        if(contPropio != 0)propio += pow(10, contPropio);
                                        raya = 0;
                                        contContrario = 0;
                                        contPropio = 0;
                                }
                        }
                        j++;
        }
        return (contrario - propio);
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
