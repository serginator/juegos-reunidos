//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Arbol2JTab.h"
//---------------------------------------------------------------------------
Arbol2JTab::Arbol2JTab(const Juego2JTab& EJ, int nivel, FunHeuristica2JTab heur)
{
        FH = heur;
        cont = 0;
        arbol = new ArbolJ(dato2JTab(EJ.clona()));
        generaArbol(arbol, nivel);
};
//---------------------------------------------------------------------------
Arbol2JTab::~Arbol2JTab()
{
        liberaArbol(arbol);
//        delete arbol;
}
//---------------------------------------------------------------------------
void Arbol2JTab::liberaArbol(ArbolJ* &arbol)
{
        int hijos = arbol->numHijos();
        ArbolJ* dato;
        delete arbol->getDato().juego;
        for(int i = 0; i < hijos; i++)
        {
                dato = arbol->getHijo(i);
                if(!arbol->getHijo(i)->esHoja())liberaArbol(dato);
                else
                {
                        delete arbol->getHijo(i)->getDato().juego;
                        delete arbol->getHijo(i);
                }
                if(i == hijos - 1) delete arbol;
        }
}
//---------------------------------------------------------------------------
void Arbol2JTab::generaArbol(ArbolJ* arbol, int nivel) const throw(EJuego)
{
        if((nivel >/*=*/ 0) && !(arbol->getDato().juego->final()))
        {
                if(nivel%2 != 0)
                {
                        dato2JTab dato = arbol->getDato();
                        if(dato.juego->dameTurno() != Ja)dato.juego->cambiaTurno();
                }
                else
                {
                        dato2JTab dato = arbol->getDato();
                        if(dato.juego->dameTurno() != Jc)dato.juego->cambiaTurno();
                }
                for(int c = 0; c < arbol->getDato().juego->numCol(); c++)
                {
                        for(int f = 0; f < arbol->getDato().juego->numFil(); f++)
                        {
                                if(arbol->getDato().juego->sePuedeMaq(c, f))
                                {
                                        Juego2JTab* sigEstado = arbol->getDato().juego->clona();
                                        sigEstado->aplicaJugada(c, f);
                                        Arbol<dato2JTab>* aux = new Arbol<dato2JTab>(dato2JTab(sigEstado, Casilla(c, f)));
                                        arbol->addHijo(aux);
                                        generaArbol(arbol->getHijo(arbol->numHijos() - 1), nivel-1);
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------
Casilla Arbol2JTab::buscaMejorJugada() throw(EJuego)
{
        if(arbol->esHoja()) throw EJuego();
        else
        {
                int mejorC = -1;
                int mejorV = INT_MIN;
                int c, v;
                int n = arbol->numHijos();
                for(c = 0; c < n; c++)
                {
                        v = buscaMiniMax(arbol->getHijo(c));
                        if(v > mejorV)
                        {
                                mejorV = v;
                                mejorC = c;
                        }
                }
                //String vS = IntToStr(v);
                //ShowMessage("Tablero:" + vS);
                return arbol->getHijo(mejorC)->getDato().jugada;
        }
}
//---------------------------------------------------------------------------
int Arbol2JTab::buscaMiniMax(ArbolJ* arbol) const throw (EJuego)
{
        if(arbol->esHoja())
        {
                dato2JTab dato;
                int valor = INT_MIN;
                dato = arbol->getDato();
                return FH(*(dato.juego));
        }
        else if (arbol->getDato().juego->dameTurno() == Jc)
        {
                int mejorV = INT_MIN;
                int c, v;
                int n = arbol->numHijos();
                for(int c = 0; c < n; c++)
                {
                        v = buscaMiniMax(arbol->getHijo(c));
                        if(v > mejorV) mejorV = v;
                }
                return mejorV;
        }
        else
        {       //turno del contrario (Ja) -> minimizar
                int mejorV = INT_MAX;
                int c, v;
                int n = arbol->numHijos();
                for(int c = 0; c < n; c++)
                {
                        v = buscaMiniMax(arbol->getHijo(c));
                        if (v < mejorV) mejorV = v;
                }
                return mejorV;
        }
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
