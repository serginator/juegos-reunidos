//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorAlea3Raya.h"
//---------------------------------------------------------------------------
JugadorAlea3Raya::JugadorAlea3Raya() : Jugador()
{

}
//---------------------------------------------------------------------------
JugadorAlea3Raya::~JugadorAlea3Raya()
{

}
//---------------------------------------------------------------------------
Casilla JugadorAlea3Raya::juega(const Juego2JTab &EJ) const
{
        int col;
        int fil;
        unsigned int nCol = EJ.numCol();
        unsigned int nFil = EJ.numFil();
        col = random(nCol);
        fil = random(nFil-1);
        int cont = 0;
        while(!EJ.sePuede(col, fil) && (cont != 100))
        {
                col = random(nCol);
                fil = random(nFil-1);
                cont++;
        }
        return Casilla(col, fil);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

