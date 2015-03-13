//---------------------------------------------------------------------------

#ifndef JugadorConz3RayaH
#define JugadorConz3RayaH

#include "Jugador.h"
#include "Juego3Raya.h"
//#include "Arbol2JTab.h"
#include "Math.h"
//---------------------------------------------------------------------------
typedef int (*FunHeuristica3Raya)(const Juego2JTab &EC);

class JugadorConz3Raya : public Jugador
{
        protected:
                FunHeuristica3Raya heuristica;
                int nivel;
        public:

                static int HeuristicaDef(const Juego2JTab &EJ);
                JugadorConz3Raya(int n=2, FunHeuristica3Raya FH = HeuristicaDef); //implementar y declarar HeuristicaDef
                ~JugadorConz3Raya();

                //métodos
                virtual Casilla juega(const Juego2JTab &EJ)const;
};
#endif
 