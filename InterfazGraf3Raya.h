//---------------------------------------------------------------------------

#ifndef InterfazGraf3RayaH
#define InterfazGraf3RayaH

#include "InterfazGraf2JTab.h"
#include "Juego3Raya.h"
#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class InterfazGraf3Raya : public InterfazGraf2JTab
{
        private:
                static tBMP ficha3A;
                static tBMP ficha3B;
                static tBMP ficha3N;
                static Graphics::TBitmap *fichas[3];
                static const int ladoCasilla = 150;
                static const int altoTablero = 450; //7 de base y 6 de altura
                static const int anchoGraf = 450;
                static const int altoGraf = 498; //+48
        public:
                InterfazGraf3Raya(TCanvas *L);
                virtual void muestraEstado(const Juego2JTab &EJ)const throw(EInterfaz);
                virtual unsigned int dameColumna(unsigned int X) throw(EInterfaz);
                virtual unsigned int dameFila(unsigned int Y) throw(EInterfaz);
                virtual unsigned int dameAnchoGraf()const throw() {};
                virtual unsigned int dameAltoGraf()const throw() {};
};



#endif
 
