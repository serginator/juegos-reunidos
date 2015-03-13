//---------------------------------------------------------------------------

#ifndef JugadorAleaOteloH
#define JugadorAleaOteloH

#include "Jugador.h"
//---------------------------------------------------------------------------
class JugadorAleaOtelo : public Jugador
{
        public:
                JugadorAleaOtelo();
                virtual ~JugadorAleaOtelo();
                virtual Casilla juega(const Juego2JTab &EJ) const;
};
#endif
