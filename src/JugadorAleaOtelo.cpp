//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JugadorAleaOtelo.h"

//---------------------------------------------------------------------------
JugadorAleaOtelo::JugadorAleaOtelo() : Jugador()
{

}
//---------------------------------------------------------------------------
JugadorAleaOtelo::~JugadorAleaOtelo()
{

}
//---------------------------------------------------------------------------
Casilla JugadorAleaOtelo::juega(const Juego2JTab &EJ) const
{
        //if(EJ.final()) throw EA();
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
        if (cont == 100)
        {
                Casilla cf;
                if(!EJ.sePuedeAlguna(cf))return Casilla(8,0); //para que pase si no puede
                return cf;
        }
        return Casilla(col, fil);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
 