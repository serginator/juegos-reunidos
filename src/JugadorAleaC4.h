//---------------------------------------------------------------------------

#ifndef JugadorAleaC4H
#define JugadorAleaC4H

#include "Jugador.h"
//---------------------------------------------------------------------------
class JugadorAleaC4 : public Jugador
{
        public:
                JugadorAleaC4();
                virtual ~JugadorAleaC4();
                virtual Casilla juega(const Juego2JTab &EJ) const;
};
#endif
