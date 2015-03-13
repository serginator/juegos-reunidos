//---------------------------------------------------------------------------

#ifndef JugadorH
#define JugadorH

#include "Juego2JTab.h"
#include "Arbol2JTab.h"
//---------------------------------------------------------------------------
class EJugador{
};

class Jugador
{
        public:
                //constructora
                Jugador();

                //destructora
                virtual ~Jugador(){};

                //métodos
                virtual Casilla juega(const Juego2JTab &EJ)const{}; /*throw(EJugador)*/

};
#endif

