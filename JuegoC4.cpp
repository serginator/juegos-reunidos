//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JuegoC4.h"
//---------------------------------------------------------------------------
JuegoC4::JuegoC4():Juego2JTab()
{
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(7, 6, Jn);
        libres = 42;
        humanos = false;

};
//---------------------------------------------------------------------------
JuegoC4::JuegoC4(Turno &t, bool b):Juego2JTab()
{
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(7, 6, Jn);
        libres = 42;
        turno = t;
        humanos = b;
};
//---------------------------------------------------------------------------
JuegoC4::JuegoC4(JuegoC4 &J):Juego2JTab(J)
{
        libres = J.libres;
};
//---------------------------------------------------------------------------
JuegoC4::~JuegoC4()
{
        delete tablero;
        tablero = NULL;
};
//---------------------------------------------------------------------------
void JuegoC4::reinicia(Turno turno)
{
        delete tablero;
        tablero = NULL;
        tablero = new Tablero();
};
//---------------------------------------------------------------------------
void JuegoC4::aplicaJugada(unsigned int c, unsigned int f) throw(EJuego)
{
        for(int i = 5; i >= 0; i--)
        {
                Turno aux;
                tablero->dameElem(c,i,aux);
                if(aux == Jn)
                {
                        tablero->ponValor(c, i, turno);
                        libres--;
                        return;
                }
        }
};
//---------------------------------------------------------------------------
bool JuegoC4::sePuede(unsigned int c, unsigned int f) const throw()
{
        Turno aux;
        for(int i = 0;i < 6;i++)
        {
                tablero->dameElem(c,i,aux);
                if(aux == Jn) return true;
                return false;
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoC4::sePuedeMaq(unsigned int c, unsigned int f) const throw()
{
        Turno aux;
        Turno aux1;
        tablero->dameElem(c,f,aux);
        if(f != 0)
        {
                tablero->dameElem(c,f-1,aux1);
                if((aux == Jn) && (aux1 != Jn)) return true;
                return false;
        }
        if(f == 0)
        {
                if(aux == Jn)return true;
                return false;
        }
};
//---------------------------------------------------------------------------
bool JuegoC4::fin() const throw()
{
        Turno aux;
        int cont = 0;
        //vertical
        for(int i = 0; i < 7; i++)
        {
                cont = 0;
                for(int j = 0; j < 6; j++)
                {
                        tablero->dameElem(i, j, aux);
                        if(aux == turno)
                        {
                                cont++;
                                if(cont == 4)
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
        for(int i = 0; i < 6;i++)
        {
                cont = 0;
                for(int j = 0;j < 7;j++)
                {
                        tablero->dameElem(j, i, aux);
                        if(aux == turno)
                        {
                                cont++;
                                if(cont == 4)
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
        for(int i = 0; i < 4; i++)
        {
                for(int j = 0; j < 3; j++)
                {
                        cont = 0;
                        int y = j;
                        tablero->dameElem(i, j, aux);
                        for(int x = i; x < 7; x++)
                        {
                                tablero->dameElem(x, y, aux);
                                if(aux == turno)
                                {
                                        cont++;
                                        if(cont == 4)
                                        {
                                                //ShowMessage("diagonal1");
                                                if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                                if(turno == Jb) ShowMessage("Ha ganado John!");
                                                if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                                return true;
                                        }
                                }
                                else cont = 0;
                                if(y < 5) y++;
                                else
                                {
                                        x = 7;
                                        cont = 0;
                                }
                        }
                }
        }
        //diagonal2 (der arriba -> izq abajo)
        for(int i = 0; i < 4; i++)
        {
                for(int j = 3; j < 6; j++)
                {
                        cont = 0;
                        int y = j;
                        tablero->dameElem(i, j, aux);
                        for(int x = i; x < 7; x++)
                        {
                                tablero->dameElem(x, y, aux);
                                if(aux == turno)
                                {
                                        cont++;
                                        if(cont == 4)
                                        {
                                                //ShowMessage("diagonal2");
                                                if(turno == Ja) ShowMessage("Ha ganado Mike!");
                                                if(turno == Jb) ShowMessage("Ha ganado John!");
                                                if(turno == Jc) ShowMessage("Ha ganado HAL!");
                                                return true;
                                        }
                                }
                                else cont = 0;
                                if(y > 0) y--;
                                else
                                {
                                        x = 7;
                                        cont = 0;
                                }
                        }
                }
        }
        if(libres == 0)
        {
                ShowMessage("Tablas");
                return true;
        }
        cambiaTurno();
        return false;
};
//---------------------------------------------------------------------------
Juego2JTab* JuegoC4::clona()
{
        JuegoC4* clon = new JuegoC4(*this);
        return clon;
};
//---------------------------------------------------------------------------
Turno JuegoC4::dameGanador() const throw()
{
        return turno;
};
//---------------------------------------------------------------------------
Turno JuegoC4::valorCasilla(unsigned int c, unsigned int f)const
{
        Turno aux;
        tablero->dameElem(c, f, aux);
        return aux;
};
//---------------------------------------------------------------------------
bool JuegoC4::salvar(ofstream &sal) const
{
        Juego2JTab::salvar(sal);
};
//---------------------------------------------------------------------------
bool JuegoC4::cargar(ifstream &ent)
{
        Juego2JTab::cargar(ent);
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
 
