//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InterfazGraf2JTab.h"
//---------------------------------------------------------------------------
Casilla InterfazGraf2JTab::dameCasilla(unsigned int X, unsigned int Y)const throw(EInterfaz)
{
        unsigned int x = dameColumna(X);
        unsigned int y = dameFila(Y);
        Casilla aux(x, y);
        return aux;
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
 