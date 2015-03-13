//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InterfazGrafOtelo.h"

//---------------------------------------------------------------------------
tBMP InterfazGrafOtelo::OteloA("OteloA.bmp");
tBMP InterfazGrafOtelo::OteloB("OteloB.bmp");
tBMP InterfazGrafOtelo::OteloC("OteloC.bmp");
tBMP InterfazGrafOtelo::OteloN("OteloN.bmp");
tBMP InterfazGrafOtelo::OteloP("OteloP.bmp");

InterfazGrafOtelo::InterfazGrafOtelo(TCanvas *L) : InterfazGraf2JTab()
{
        lienzo = L;
        int X = 0;
        int Y = 0;
        if(L != NULL)
        {
                for(int i = 0;i < 8;i++)
                {
                        X = 0;
                        for(int j = 0; j < 8; j++)
                        {
                                lienzo->Draw(X,Y,OteloN.BMP());
                                X += ladoCasilla;
                        }
                        Y += ladoCasilla;
                }
                lienzo->Draw(135, 135, OteloB.BMP());
                lienzo->Draw(135, 180, OteloA.BMP());
                lienzo->Draw(180, 180, OteloB.BMP());
                lienzo->Draw(180, 135, OteloA.BMP());
                lienzo->Draw(355, 0, OteloP.BMP());
                lienzo->Font->Color = clRed;
                lienzo->Font->Height = 20;
                lienzo->TextOutA(140,370,"Otelo");
        }
};
//---------------------------------------------------------------------------
unsigned int InterfazGrafOtelo::dameColumna(unsigned int X) throw(EInterfaz)
{
        return (X/ladoCasilla);
};
//---------------------------------------------------------------------------
unsigned int InterfazGrafOtelo::dameFila(unsigned int Y) throw(EInterfaz)
{
        return (Y/ladoCasilla);
};
//---------------------------------------------------------------------------
void InterfazGrafOtelo::muestraEstado(const Juego2JTab &EJ)const throw(EInterfaz)
{
        Turno aux;
        int  X, Y = 0;
        for(int i = 0;i < 8;i++)
        {
                X = 0;
                for(int j = 0; j < 8; j++)
                {
                        Casilla cf(j, i);
                        aux = EJ.valorCasilla(cf);
                        if (aux == Jn) lienzo->Draw(X,Y,OteloN.BMP());
                        if (aux == Ja) lienzo->Draw(X,Y,OteloA.BMP());
                        if (aux == Jb) lienzo->Draw(X,Y,OteloB.BMP());
                        if (aux == Jc) lienzo->Draw(X,Y,OteloC.BMP());
                        X += ladoCasilla;
                }
                Y += ladoCasilla;
        }
        lienzo->Draw(355, 0, OteloP.BMP());
        lienzo->Font->Color = clRed;
        lienzo->Font->Height = 20;
        AnsiString turno;
        if(EJ.dameTurno() == Ja)
        {
                turno = "negras   ";
        }
        else    if (EJ.dameTurno() == Jb)
                {
                        turno = "blancas";
                }
                else turno = "maquina";
        lienzo->TextOutA(20,370,"Turno: " + turno);
        lienzo->TextOutA(140,370,"Otelo");
};
#pragma package(smart_init)

