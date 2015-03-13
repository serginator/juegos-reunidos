//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Juego2JTab.h"
//--------------------------------------------------------------------------
Juego2JTab::Juego2JTab()
{
        hayGanador = false;
        turno = Ja;
        tablero = NULL;
        humanos = false;
};
//---------------------------------------------------------------------------
Juego2JTab::Juego2JTab(Juego2JTab &J)
{
        hayGanador = J.hayGanador;
        turno = J.turno;
        humanos = J.humanos;
        Turno aux = Jn;
        tablero = new Tablero(J.numCol(), J.numFil(), aux);
        for(int i = numCol() - 1; i >= 0;i--)
        {
                for(int j = numFil() - 1;j >= 0;j--)
                {
                        J.tablero->dameElem(i, j, aux);
                        tablero->ponValor(i, j, aux);
                }
        }
};
//---------------------------------------------------------------------------
Juego2JTab::~Juego2JTab()
{
        delete tablero;
        tablero = NULL;
}
//---------------------------------------------------------------------------
void Juego2JTab::aplicaJugada(Casilla cf)throw(EJuego)
{
        if(sePuede(cf))
        {
                aplicaJugada(cf.nColumna, cf.nFila);
        };
};
//---------------------------------------------------------------------------
bool Juego2JTab::sePuede(Casilla cf) const throw()
{
        if(!sePuede(cf.nColumna, cf.nFila))
        {
                if(turno != Jc)ShowMessage("Movimiento no permitido");
                return false;
        }
        return true;
};
//---------------------------------------------------------------------------
Turno Juego2JTab::valorCasilla(Casilla cf) const
{
        return valorCasilla(cf.nColumna, cf.nFila);
};
//---------------------------------------------------------------------------
void Juego2JTab::cambiaTurno()
{
        if((turno == Ja) && hayHumanos())
        {
                turno = Jb;
        }
        else
                if((turno == Jb) && hayHumanos())
                {
                        turno = Ja;
                }
                else
                        if ((turno == Ja) && !hayHumanos())
                        {
                                turno = Jc;
                        }
                        else turno = Ja;
}
//---------------------------------------------------------------------------
bool Juego2JTab::salvar(ofstream &sal) const
{
        sal.write((char*)& hayGanador,sizeof(bool));
        sal.write((char*)& humanos,sizeof(bool));
        return sal.good();
}
//---------------------------------------------------------------------------
bool Juego2JTab::cargar(ifstream &ent)
{
        ent.read((char*)& hayGanador,sizeof(bool));
        ent.read((char*)& humanos,sizeof(bool));
        return ent.good();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
