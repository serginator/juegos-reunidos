//---------------------------------------------------------------------------

#ifndef InterfazGrafOteloH
#define InterfazGrafOteloH

#include "InterfazGraf2JTab.h"
#include "JuegoOtelo.h"
//---------------------------------------------------------------------------
class InterfazGrafOtelo : public InterfazGraf2JTab
{
        private:
                static tBMP OteloA;
                static tBMP OteloB;
                static tBMP OteloC;
                static tBMP OteloN;
                static tBMP OteloP;
                static Graphics::TBitmap *fichas[3];
                static const int ladoCasilla = 45;
                static const int altoTablero = 400; //8 de base y 8 de altura mas la casilla de pasar
                static const int anchoGraf = 450;
                static const int altoGraf = 400;
        public:
                InterfazGrafOtelo(TCanvas *L) /*:InterfazGraf2JTab(){}*/;
                virtual void muestraEstado(const Juego2JTab &EJ)const throw(EInterfaz);
                virtual unsigned int dameColumna(unsigned int X) throw(EInterfaz);
                virtual unsigned int dameFila(unsigned int Y) throw(EInterfaz);
};


#endif
 