//---------------------------------------------------------------------------

#ifndef JugadorAlea3RayaH
#define JugadorAlea3RayaH
#include "Jugador.h"
//---------------------------------------------------------------------------
class JugadorAlea3Raya : public Jugador
{
        public:
                JugadorAlea3Raya();
                virtual ~JugadorAlea3Raya();
                virtual Casilla juega(const Juego2JTab &EJ) const;
};
#endif
