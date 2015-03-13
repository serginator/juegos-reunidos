//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorConzC4.h"
//---------------------------------------------------------------------------
JugadorConzC4::JugadorConzC4(int n, FunHeuristicaC4 FH) //implementar y declarar HeuristicaDef
{
        nivel = n;
        heuristica = FH;
};
//---------------------------------------------------------------------------
JugadorConzC4::~JugadorConzC4()
{

};
//---------------------------------------------------------------------------
Casilla JugadorConzC4::juega(const Juego2JTab &EJ)const
{
        if(!EJ.final())
        {
                Arbol2JTab arbol(EJ, nivel,(FunHeuristica2JTab) heuristica);
                return arbol.buscaMejorJugada();
        }
};
//---------------------------------------------------------------------------
int JugadorConzC4::HeuristicaDef(const Juego2JTab &EJ)
{
        Turno auxT, turno;
        int contPropio = 0;
        int contContrario = 0;
        int linea4 = 0;
        int propio = 0;
        int contrario = 0;
        turno = EJ.dameTurno();

        //horizontal capado
        for(int j = 5; j >= 0;j--)
        {
                for(int i = 0;i <= 3;i++)
                {
                        linea4 = 0;
                        contContrario = 0;
                        contPropio = 0;
                        int y = j;
                        for(int x = i; x <= i+3; x++)
                        {
                                auxT = EJ.valorCasilla(x, y);
                                //**********************************************
                                //valorJugada(propio, contrario, auxT, turno, linea4, contPropio, contContrario);
                                if(auxT == turno)
                                {
                                        if(contContrario != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contPropio++;
                                        linea4++;
                                        /*if(linea4 == 4)
                                        {
                                                propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contPropio = 0;
                                        }  */
                                        if(linea4 == 4)
                                        {
                                                if(contPropio == 4)propio += pow(10, contPropio++);
                                                else propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contPropio = 0;
                                        }
                                }
                                else if(auxT != Jn)
                                {
                                        if(contPropio != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contContrario++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                if(contContrario == 4)contrario += pow(10, contContrario++);
                                                else contrario += pow(10, contContrario);
                                                linea4 = 0;
                                                contContrario = 0;
                                        }
                                }
                                else
                                {
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                if(contContrario != 0)contrario += pow(10, contContrario);
                                                if(contPropio != 0)propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contContrario = 0;
                                                contPropio = 0;
                                        }
                                }
                                //**********************************************
                        }
                }
        }

        //vertical capado
        for(int i = 0; i <= 6;i++)
        {
                for(int j = 5;j >= 3;j--)
                {
                        linea4 = 0;
                        contContrario = 0;
                        contPropio = 0;
                        int x = i;
                        for(int y = j; y >= j-3; y--)
                        {
                                auxT = EJ.valorCasilla(x, y);
                                //**********************************************
                                //valorJugada(propio, contrario, auxT, turno, linea4, contPropio, contContrario);
                                if(auxT == turno)
                                {
                                        if(contContrario != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contPropio++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contPropio = 0;
                                        }
                                }
                                else if(auxT != Jn)
                                {
                                        if(contPropio != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contContrario++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                contrario += pow(10, contContrario);
                                                linea4 = 0;
                                                contContrario = 0;
                                        }
                                }
                                else
                                {
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                if(contContrario != 0)contrario += pow(10, contContrario);
                                                if(contPropio != 0)propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contContrario = 0;
                                                contPropio = 0;
                                        }
                                }
                                //**********************************************
                        }
                }
        }

        //diagonal izq arriba
        for(int j = 5; j >= 3;j--)
        {
                linea4 = 0;
                contContrario = 0;
                contPropio = 0;
                for(int i = 3; i <= 6; i++)
                {
                        int y = j;
                        for(int x = i; x >= i-3; x--)
                        {
                                auxT = EJ.valorCasilla(x, y);
                                //**********************************************
                                //valorJugada(propio, contrario, auxT, turno, linea4, contPropio, contContrario);
                                if(auxT == turno)
                                {
                                        if(contContrario != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contPropio++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contPropio = 0;
                                        }
                                }
                                else if(auxT != Jn)
                                {
                                        if(contPropio != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contContrario++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                contrario += pow(10, contContrario);
                                                linea4 = 0;
                                                contContrario = 0;
                                        }
                                }
                                else
                                {
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                if(contContrario != 0)contrario += pow(10, contContrario);
                                                if(contPropio != 0)propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contContrario = 0;
                                                contPropio = 0;
                                        }
                                }
                                //**********************************************
                                y--;
                        }
                }
        }

        //diagonal der arriba
        for(int j = 5; j >= 3;j--)
        {
                linea4 = 0;
                contContrario = 0;
                contPropio = 0;
                for(int i = 0; i <= 3; i++)
                {
                        int y = j;
                        for(int x = i; x <= i+3; x++)
                        {
                                auxT = EJ.valorCasilla(x, y);
                                //**********************************************
                                //valorJugada(propio, contrario, auxT, turno, linea4, contPropio, contContrario);
                                if(auxT == turno)
                                {
                                        if(contContrario != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contPropio++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contPropio = 0;
                                        }
                                }
                                else if(auxT != Jn)
                                {
                                        if(contPropio != 0)
                                        {
                                                contPropio = 0;
                                                contContrario = 0;
                                                linea4 = 0;
                                        }
                                        contContrario++;
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                contrario += pow(10, contContrario);
                                                linea4 = 0;
                                                contContrario = 0;
                                        }
                                }
                                else
                                {
                                        linea4++;
                                        if(linea4 == 4)
                                        {
                                                if(contContrario != 0)contrario += pow(10, contContrario);
                                                if(contPropio != 0)propio += pow(10, contPropio);
                                                linea4 = 0;
                                                contContrario = 0;
                                                contPropio = 0;
                                        }
                                }
                                //**********************************************
                                y--;
                        }
                }
        }
        return (contrario - propio);
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
 