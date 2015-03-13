//---------------------------------------------------------------------------

#ifndef InterfazGraf2JTabH
#define InterfazGraf2JTabH

#include "Juego2JTab.h"
//---------------------------------------------------------------------------
class EInterfaz{
};

class InterfazGraf2JTab : protected Juego2JTab
{
        protected:
                TCanvas* lienzo;

        public:
                InterfazGraf2JTab(TCanvas *L = NULL):lienzo(L){};
                virtual ~InterfazGraf2JTab(){};
                virtual unsigned int dameColumna(unsigned int X)throw(EInterfaz)=0;
                virtual unsigned int dameFila(unsigned int Y)throw(EInterfaz)=0;
                Casilla dameCasilla(unsigned int X, unsigned int Y)const throw(EInterfaz);
                virtual void muestraEstado(const Juego2JTab &EJ)const throw(EInterfaz)=0;
                virtual unsigned int dameAnchoGraf()const throw(){};
                virtual unsigned int dameAltoGraf()const throw(){};
};

class tBMP
{
        public:
                Graphics::TBitmap* bmp;
                tBMP()
                {
                        bmp = new Graphics::TBitmap();
                };
                tBMP(AnsiString Bmp)
                {
                        bmp = new Graphics::TBitmap();
                        bmp->LoadFromFile(Bmp);
                };
                ~tBMP()
                {
                        delete bmp;
                        bmp = NULL;
                };
                void cargar(AnsiString Bmp)
                {
                        bmp->LoadFromFile(Bmp);
                };
                Graphics::TBitmap* BMP()
                {
                        return bmp;
                };
};
#endif
