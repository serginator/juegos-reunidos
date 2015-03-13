//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JuegoOtelo.h"

//---------------------------------------------------------------------------
JuegoOtelo::JuegoOtelo():Juego2JTab()
{
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(9, 8, Jn);
        if(hayHumanos())
        {
                tablero->ponValor(3, 3, Jb);
                tablero->ponValor(4, 4, Jb);
        }
        else
        {
                tablero->ponValor(3, 3, Jc);
                tablero->ponValor(4, 4, Jc);
        }
        tablero->ponValor(3, 4, Ja);
        tablero->ponValor(4, 3, Ja);
        numFichas[0] = 60;
        numFichas[1] = 2;
        numFichas[2] = 2;
        numFichas[3] = 2;
};
//---------------------------------------------------------------------------
JuegoOtelo::JuegoOtelo(Turno &t, bool b):Juego2JTab()
{
        humanos = b;
        if (tablero != NULL)
        {
                delete tablero;
        }
        tablero = new Tablero(9, 8, Jn);
        if(b)
        {
                tablero->ponValor(3, 3, Jb);
                tablero->ponValor(4, 4, Jb);
        }
        else
        {
                tablero->ponValor(3, 3, Jc);
                tablero->ponValor(4, 4, Jc);
        }
        tablero->ponValor(3, 4, Ja);
        tablero->ponValor(4, 3, Ja);
        turno = t;
        numFichas[0] = 60;
        numFichas[1] = 2;
        numFichas[2] = 2;
        numFichas[3] = 2;
};
//---------------------------------------------------------------------------
JuegoOtelo::JuegoOtelo(JuegoOtelo &J):Juego2JTab(J)
{
        numFichas[0] = J.numFichas[0];
        numFichas[1] = J.numFichas[1];
        numFichas[2] = J.numFichas[2];
        numFichas[3] = J.numFichas[3];
        haPasado = J.haPasado;
};
//---------------------------------------------------------------------------
JuegoOtelo::~JuegoOtelo()
{
        delete tablero;
        tablero = NULL;
};
//---------------------------------------------------------------------------
void JuegoOtelo::reinicia(Turno turno)
{
        delete tablero;
        tablero = NULL;
        tablero = new Tablero();
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugada(unsigned int c, unsigned int f) throw(EJuego)
{
        haPasado = false;

        if(sePuedeArriba(c,f))aplicaJugadaArriba(c,f);
        if(sePuedeAbajo(c,f))aplicaJugadaAbajo(c,f);
        if(sePuedeDerecha(c,f))aplicaJugadaDerecha(c,f);
        if(sePuedeIzquierda(c,f))aplicaJugadaIzquierda(c,f);
        if(sePuedeArribaIzquierda(c,f))aplicaJugadaArribaIzquierda(c,f);
        if(sePuedeArribaDerecha(c,f))aplicaJugadaArribaDerecha(c,f);
        if(sePuedeAbajoIzquierda(c,f))aplicaJugadaAbajoIzquierda(c,f);
        if(sePuedeAbajoDerecha(c,f))aplicaJugadaAbajoDerecha(c,f);
        tablero->ponValor(c, f, turno);
        if(turno == Ja)numFichas[1]++;
        if(turno == Jb)numFichas[2]++;
        if(turno == Jc)numFichas[3]++;
        numFichas[0]--;
        cambiaTurno();
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuede(unsigned int c, unsigned int f) const throw()
{
        //*****************************************************
        //Casilla cAux;
        //if((c == 8) && (!sePuedeAlguna(cAux)))return false;
        //******************************************************
        if(c == 8) return false;
        Turno aux;
        tablero->dameElem(c, f, aux);
        if(aux != Jn)return false;
        bool si = false;
        si = si||sePuedeArriba(c,f);
        si = si||sePuedeAbajo(c,f);
        si = si||sePuedeDerecha(c,f);
        si = si||sePuedeIzquierda(c,f);
        si = si||sePuedeArribaIzquierda(c,f);
        si = si||sePuedeArribaDerecha(c,f);
        si = si||sePuedeAbajoDerecha(c,f);
        si = si||sePuedeAbajoIzquierda(c,f);
        //if(!si)ShowMessage("Movimiento no permitido");
        return si;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeMaq(unsigned int c, unsigned int f) const throw()
{
        if(c == 8) return false;
        Turno aux;
        tablero->dameElem(c, f, aux);
        if(aux != Jn)return false;
        bool si = false;
        si = si||sePuedeArriba(c,f);
        si = si||sePuedeAbajo(c,f);
        si = si||sePuedeDerecha(c,f);
        si = si||sePuedeIzquierda(c,f);
        si = si||sePuedeArribaIzquierda(c,f);
        si = si||sePuedeArribaDerecha(c,f);
        si = si||sePuedeAbajoDerecha(c,f);
        si = si||sePuedeAbajoIzquierda(c,f);
        return si;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::fin() const throw()
{
        if(numFichas[0] == 0)
        {
                if(humanos && (numFichas[1] < numFichas[2]))ShowMessage("Gana blancas");
                if(humanos && (numFichas[1] > numFichas[2]))ShowMessage("Gana negras");
                if(humanos && (numFichas[1] == numFichas[2]))ShowMessage("Tablas");
                if(!humanos && (numFichas[1] < numFichas[3]))ShowMessage("Gana blancas");
                if(!humanos && (numFichas[1] > numFichas[3]))ShowMessage("Gana negras");
                if(!humanos && (numFichas[1] == numFichas[3]))ShowMessage("Tablas");
                return true;
        }
        else if(numFichas[1] == 0)
        {
                ShowMessage("Paliza de las blancas");
                return true;
        }
        else if((humanos) && (numFichas[2] == 0))
        {
                ShowMessage("Paliza de las negras");
                return true;
        }
        else if((!humanos) && (numFichas[3] == 0))
        {
                ShowMessage("Paliza de las negras");
                return true;
        }
        else if(haPasado==true)
        {
                //algo para saber que le ha dado a pasar
        }
        return false;
};
//---------------------------------------------------------------------------
Juego2JTab* JuegoOtelo::clona()
{
        JuegoOtelo* clon = new JuegoOtelo(*this);
        return clon;
};
//---------------------------------------------------------------------------
Turno JuegoOtelo::dameGanador() const throw()
{
        Turno aux;
        if(humanos)
        {
                if(numFichas[1] == numFichas[2])aux = Jn;//tablas
                else if(numFichas[1] < numFichas[2])aux = Jb;//gana2
                else aux = Ja;
        }
        else if(!humanos)
        {
                if(numFichas[1] == numFichas[3])aux = Jn;//tablas
                else if(numFichas[1] < numFichas[3])aux = Jc;//gana2
                else aux = Ja;
        }
        return aux;
};
//---------------------------------------------------------------------------
Turno JuegoOtelo::valorCasilla(unsigned int c, unsigned int f)const
{
        Turno aux;
        tablero->dameElem(c, f, aux);
        return aux;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeAbajo(unsigned int c, unsigned int f) const
{
        Turno aux;
        int cont = 0;
        if(f == 0)return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                f--;
                for(int i = f;i >= 0;i--)
                {
                        tablero->dameElem(c, i, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //f--;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeArriba(unsigned int c, unsigned int f) const
{
        Turno aux;
        int cont = 0;
        if(f == 8)return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                f++;
                for(int i = f;i < 8;i++)
                {
                        tablero->dameElem(c, i, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //f++;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeDerecha(unsigned int c, unsigned int f) const
{

        Turno aux;
        int cont = 0;
        if(c == 0)return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                c--;
                for(int i = c;i >= 0;i--)
                {
                        tablero->dameElem(i, f, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c--;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeIzquierda(unsigned int c, unsigned int f) const
{
        Turno aux;
        int cont = 0;
        if(c == 8)return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                c++;
                for(int i = c;i < 8;i++)
                {
                        tablero->dameElem(i, f, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c++;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeAbajoIzquierda(unsigned int c, unsigned int f) const
{
        //+-
        Turno aux;
        int cont = 0;
        if((c == 8) || (f == 0))return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                int j = f;
                c++;
                for(int i = c;i < 8;i++)
                {
                        if(j <= 0)return false;
                        j--;
                        tablero->dameElem(i, j, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c++;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeAbajoDerecha(unsigned int c, unsigned int f) const
{
        //--
        Turno aux;
        int cont = 0;
        if((c == 0) || (f == 0))return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                int j = f;
                c--;
                for(int i = c;i >= 0;i--)
                {
                        if(j <= 0)return false;
                        j--;
                        tablero->dameElem(i, j, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c--;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeArribaIzquierda(unsigned int c, unsigned int f) const
{
        //++
        Turno aux;
        int cont = 0;
        if((c == 8) || (f == 8))return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                int j = f;
                c++;
                for(int i = c;i < 8;i++)
                {
                        if(j > 6)return false;
                        j++;
                        tablero->dameElem(i, j, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c++;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeArribaDerecha(unsigned int c, unsigned int f) const
{
        //-+
        Turno aux;
        int cont = 0;
        if((c == 0) || (f == 8))return false;
        tablero->dameElem(c, f, aux);
        if(aux == Jn)
        {
                int j = f;
                c--;
                for(int i = c;i >= 0;i--)
                {
                        if(j > 6)return false;
                        j++;
                        tablero->dameElem(i, j, aux);
                        if((aux != turno) && (aux != Jn))
                        {
                                cont++;
                                //c--;
                        }
                        else    if((aux == turno) && (cont != 0))return true;
                                else return false;
                }
        }
        return false;
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaArriba(unsigned int c, unsigned int f)
{
        Turno aux;
        f++;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                f++;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaAbajo(unsigned int c, unsigned int f)
{
        Turno aux;
        f--;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                f--;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaIzquierda(unsigned int c, unsigned int f)
{
        Turno aux;
        c++;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c++;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaDerecha(unsigned int c, unsigned int f)
{
        Turno aux;
        c--;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c--;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaArribaIzquierda(unsigned int c, unsigned int f)
{
        Turno aux;
        c++;
        f++;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c++;
                f++;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaArribaDerecha(unsigned int c, unsigned int f)
{
        Turno aux;
        c--;
        f++;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c--;
                f++;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaAbajoIzquierda(unsigned int c, unsigned int f)
{
        Turno aux;
        c++;
        f--;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c++;
                f--;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::aplicaJugadaAbajoDerecha(unsigned int c, unsigned int f)
{
        Turno aux;
        c--;
        f--;
        tablero->dameElem(c, f, aux);
        while(aux != turno)
        {
                sumaFichas(aux);
                tablero->ponValor(c,f,turno);
                c--;
                f--;
                tablero->dameElem(c, f, aux);
        }
};
//---------------------------------------------------------------------------
void JuegoOtelo::sumaFichas(Turno aux)
{
        if(turno == Ja)
        {
                numFichas[1]++;
                if(aux == Jb)numFichas[2]--;
                if(aux == Jc) numFichas[3]--;
        }
        else    if(turno == Jb)
                {
                        numFichas[2]++;
                        if(aux == Ja)numFichas[1]--;
                        if(aux == Jc) numFichas[3]--;
                }
        else    if(turno == Jc)
                {
                        numFichas[3]++;
                        if(aux == Jb)numFichas[2]--;
                        if(aux == Ja) numFichas[1]--;
                }
};
//---------------------------------------------------------------------------
void JuegoOtelo::pasar()
{
        haPasado = true;
        cambiaTurno();
        ShowMessage("Pasa turno");
};
//---------------------------------------------------------------------------
bool JuegoOtelo::salvar(ofstream &sal) const
{
        Juego2JTab::salvar(sal);
};
//---------------------------------------------------------------------------
bool JuegoOtelo::cargar(ifstream &ent)
{
        Juego2JTab::cargar(ent);
};
//---------------------------------------------------------------------------
bool JuegoOtelo::sePuedeAlguna(Casilla &cf)
{
        for(int i = 0;i < 8;i++)
        {
                for(int j = 0;j < 8;j++)
                {
                        if(sePuede(i, j))
                        {
                                cf = Casilla(i, j);
                                return true;
                        }
                }
        }
        return false;
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
 
