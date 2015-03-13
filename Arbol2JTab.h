//---------------------------------------------------------------------------

#ifndef Arbol2JTabH
#define Arbol2JTabH

#include "Arbol.h"
#include "Juego2JTab.h"
#include "Math.h"
//---------------------------------------------------------------------------
struct dato2JTab
{
        Juego2JTab* juego;
        Casilla jugada;
        dato2JTab(Juego2JTab* jg = NULL, Casilla cf = Casilla())
        {
                juego = jg;
                jugada = cf;
        }
};

typedef Arbol<dato2JTab> ArbolJ;

typedef int (*FunHeuristica2JTab)(const Juego2JTab& EC);

class Arbol2JTab
{
        protected:
                Juego2JTab* juego;
                Casilla jugada;
                ArbolJ* arbol;
                int nivel;
                FunHeuristica2JTab FH;
                int cont;
                int buscaMiniMax(ArbolJ* arbol) const throw(EJuego);
                void generaArbol(ArbolJ* arbol, int nivel) const throw(EJuego);
                void liberaArbol(ArbolJ* &arbol);
        public:
                //métodos
                Arbol2JTab(const Juego2JTab& EJ, int nivel, FunHeuristica2JTab heur);
                ~Arbol2JTab();
                Casilla buscaMejorJugada() throw(EJuego);
};
#endif
