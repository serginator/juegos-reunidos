//---------------------------------------------------------------------------

#ifndef JugadorConzOteloH
#define JugadorConzOteloH

#include "Jugador.h"
#include "JuegoOtelo.h"


//---------------------------------------------------------------------------
typedef int (*FunHeuristicaOtelo)(const Juego2JTab &EC);

class JugadorConzOtelo : public Jugador
{
        protected:
                FunHeuristicaOtelo heuristica;
                int nivel;
        public:

                static int HeuristicaDef(const Juego2JTab &EJ);
                JugadorConzOtelo(int n=2, FunHeuristicaOtelo FH = HeuristicaDef); //implementar y declarar HeuristicaDef
                ~JugadorConzOtelo();

                //métodos
                virtual Casilla juega(const Juego2JTab &EJ)const;
};
#endif
