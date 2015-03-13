//---------------------------------------------------------------------------

#ifndef JugadorConzC4H
#define JugadorConzC4H

#include "Jugador.h"
#include "JuegoC4.h"
//#include "Arbol2JTab.h"
#include "Math.h"
//---------------------------------------------------------------------------
typedef int (*FunHeuristicaC4)(const Juego2JTab &EC);

class JugadorConzC4 : public Jugador
{
        protected:
                FunHeuristicaC4 heuristica;
                int nivel;
        public:

                static int HeuristicaDef(const Juego2JTab &EJ);
                JugadorConzC4(int n=2, FunHeuristicaC4 FH = HeuristicaDef);// implementar y declarar HeuristicaDef
                ~JugadorConzC4();

                //métodos
                virtual Casilla juega(const Juego2JTab &EJ)const;
};
#endif
