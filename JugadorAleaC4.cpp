//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorAleaC4.h"
//---------------------------------------------------------------------------
JugadorAleaC4::JugadorAleaC4() : Jugador()
{

}
//---------------------------------------------------------------------------
JugadorAleaC4::~JugadorAleaC4()
{

}
//---------------------------------------------------------------------------
Casilla JugadorAleaC4::juega(const Juego2JTab &EJ) const
{
        //if(EJ.final()) throw EA();
        int col;
        unsigned int nCol = EJ.numCol();
        col = random(nCol);
        while(!EJ.sePuede(col, 0)) col = random(nCol);
        return Casilla(col, 0);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
 