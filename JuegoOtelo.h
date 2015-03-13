//---------------------------------------------------------------------------

#ifndef JuegoOteloH
#define JuegoOteloH
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class JuegoOtelo : public Juego2JTab
{
        protected:
                int numFichas[4]; //para saber cuantas fichas hay de cada tipo
                bool haPasado; //determina si el usuario ha pasado

        public:
                //constructoras
                JuegoOtelo();
                JuegoOtelo(Turno &t, bool b);
                JuegoOtelo(JuegoOtelo &J);

                //destructoras
                ~JuegoOtelo();

                //inventado
                virtual void reinicia(Turno turno);
                virtual void aplicaJugada(unsigned int c, unsigned int f) throw(EJuego);
                virtual bool sePuede(unsigned int c, unsigned int f) const throw();
                virtual bool sePuedeMaq(unsigned int c, unsigned int f) const throw();
                virtual bool fin() const throw();
                virtual Juego2JTab* clona();
                virtual Turno dameGanador() const throw();
                virtual Turno valorCasilla(unsigned int c, unsigned int f)const;
                bool sePuedeArriba(unsigned int c, unsigned int f) const;
                bool sePuedeAbajo(unsigned int c, unsigned int f) const;
                bool sePuedeIzquierda(unsigned int c, unsigned int f) const;
                bool sePuedeDerecha(unsigned int c, unsigned int f) const;
                bool sePuedeArribaDerecha(unsigned int c, unsigned int f) const;
                bool sePuedeArribaIzquierda(unsigned int c, unsigned int f) const;
                bool sePuedeAbajoDerecha(unsigned int c, unsigned int f) const;
                bool sePuedeAbajoIzquierda(unsigned int c, unsigned int f) const;
                void aplicaJugadaArriba(unsigned int c, unsigned int f);
                void aplicaJugadaAbajo(unsigned int c, unsigned int f);
                void aplicaJugadaIzquierda(unsigned int c, unsigned int f);
                void aplicaJugadaDerecha(unsigned int c, unsigned int f);
                void aplicaJugadaArribaIzquierda(unsigned int c, unsigned int f);
                void aplicaJugadaArribaDerecha(unsigned int c, unsigned int f);
                void aplicaJugadaAbajoIzquierda(unsigned int c, unsigned int f);
                void aplicaJugadaAbajoDerecha(unsigned int c, unsigned int f);
                void sumaFichas(Turno aux);
                virtual void pasar();
                virtual bool salvar(ofstream &sal) const;
                virtual bool cargar(ifstream &ent);
                virtual bool sePuedeAlguna(Casilla &cf);
};
#endif
