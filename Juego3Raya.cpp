//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Juego3Raya.h"
//---------------------------------------------------------------------------
Juego3Raya::Juego3Raya():Juego2JTab()
{
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(3, 3, Jn);
        libres = 9;
        humanos = false;

};
//---------------------------------------------------------------------------
Juego3Raya::Juego3Raya(Turno &t, bool b):Juego2JTab()
{
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(3, 3, Jn);
        libres = 9;
        turno = t;
        humanos = b;
};
//---------------------------------------------------------------------------
Juego3Raya::Juego3Raya(Juego3Raya &J) : Juego2JTab(J)
{
        libres = J.libres;
};
//---------------------------------------------------------------------------
Juego3Raya::~Juego3Raya()
{
        delete tablero;
        tablero = NULL;
};
//---------------------------------------------------------------------------
void Juego3Raya::reinicia(Turno turno)
{
        delete tablero;
        tablero = NULL;
        tablero = new Tablero();
};
//---------------------------------------------------------------------------
void Juego3Raya::aplicaJugada(unsigned int c, unsigned int f) throw(EJuego)
{
        tablero->ponValor(c, f, turno);
        libres--;
        return;
};
//---------------------------------------------------------------------------
bool Juego3Raya::sePuede(unsigned int c, unsigned int f) const throw()
{
        Turno aux;
        tablero->dameElem(c,f,aux);
        if(aux == Jn) return true;
        return false;
};
//---------------------------------------------------------------------------
bool Juego3Raya::sePuedeMaq(unsigned int c, unsigned int f) const throw()
{
        Turno aux;
        tablero->dameElem(c,f,aux);
        if(aux == Jn) return true;
        return false;
};
//---------------------------------------------------------------------------
bool Juego3Raya::fin() const throw()
{
        if(libres == 0) return true;
        Turno aux;
        int cont = 0;
        //vertical
        for(int i = 0; i < 3; i++)
        {
                cont = 0;
                for(int j = 0; j < 3; j++)
                {
                        tablero->dameElem(i, j, aux);
                        if(aux == turno)
                        {
                                cont++;
                                if(cont == 3)
                                {
                                        //ShowMessage("vertical");
                                        if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                        if(turno == Jb) ShowMessage("Ha ganado John!");
                                        if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                        return true;
                                }
                        }
                        else cont = 0;
                }
        }
        //horizontal
        for(int i = 0; i < 3;i++)
        {
                cont = 0;
                for(int j = 0;j < 3;j++)
                {
                        tablero->dameElem(j, i, aux);
                        if(aux == turno)
                        {
                                cont++;
                                if(cont == 3)
                                {
                                        //ShowMessage("Horizontal");
                                        if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                        if(turno == Jb) ShowMessage("Ha ganado John!");
                                        if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                        return true;
                                }
                        }
                        else cont = 0;
                }
        }
        //diagonal1 (izq arriba -> der abajo)
        tablero->dameElem(0,0,aux);
        if(aux == turno)
        {
                tablero->dameElem(1,1,aux);
                if(aux == turno)
                {
                        tablero->dameElem(2,2,aux);
                        if(aux == turno)
                        {
                                if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                if(turno == Jb) ShowMessage("Ha ganado John!");
                                if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                return true;
                        }
                }
        }
        //diagonal2 (der arriba -> izq abajo)
        tablero->dameElem(0,2,aux);
        if(aux == turno)
        {
                tablero->dameElem(1,1,aux);
                if(aux == turno)
                {
                        tablero->dameElem(2,0,aux);
                        if(aux == turno)
                        {
                                if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                if(turno == Jb) ShowMessage("Ha ganado John!");
                                if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                return true;
                        }
                }
        }
        cambiaTurno();
        return false;
};
//---------------------------------------------------------------------------
Juego2JTab* Juego3Raya::clona()
{
        Juego3Raya* clon = new Juego3Raya(*this);
        return clon;
};
//---------------------------------------------------------------------------
Turno Juego3Raya::dameGanador() const throw()
{
        return turno;
};
//---------------------------------------------------------------------------
Turno Juego3Raya::valorCasilla(unsigned int c, unsigned int f)const
{
        Turno aux;
        tablero->dameElem(c, f, aux);
        return aux;
};
//---------------------------------------------------------------------------
bool Juego3Raya::salvar(ofstream &sal) const
{
        Juego2JTab::salvar(sal);
};
//---------------------------------------------------------------------------
bool Juego3Raya::cargar(ifstream &ent)
{
        Juego2JTab::cargar(ent);
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
