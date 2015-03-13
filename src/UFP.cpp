//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFP *FP;
//---------------------------------------------------------------------------
__fastcall TFP::TFP(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFP::SalirClick(TObject *Sender)
{
        if (MessageDlg("¿Realmente desea abandonar el programa?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
        {
                Close();
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if(interfaz == NULL)
        {
                return;
        }
        if(((interfaz->dameFila(Y) >= 6) && (juego == conecta4))||((interfaz->dameFila(Y) >= 8) && (juego == otelo)))
        {
                return;
        }
        if((interfaz->dameFila(Y) >= 4) && (juego == raya)) return;
        pasar = 0;
        if(!up && partida != NULL)
        {
                if((juego == conecta4) &&(partida->valorCasilla(interfaz->dameColumna(X),0) != Jn) && !partida->final())
                {
                        ShowMessage("Movimiento no permitido");
                        return;
                }
                if((juego == raya) &&(partida->valorCasilla(interfaz->dameColumna(X),interfaz->dameFila(Y)) != Jn))
                {
                        ShowMessage("Movimiento no permitido");
                        return;
                }
                up = true;
                try
                {
                if(!partida->final() && partida->dameTurno() != Jc)//por lo que hay que pone otro hueco para Jc
                {
                        interfaz->muestraEstado(*partida);
                        Casilla ca = interfaz->dameCasilla(X,Y);
                        Casilla cAux;
                        if(juego == otelo && ca.nColumna == 8)
                        {
                                if(!partida->sePuedeAlguna(cAux))
                                {
                                        partida->pasar();
                                        pasar++;
                                        cola->push(ca);
                                }
                                else ShowMessage("No puedes pasar(golpe con bastón en el suelo)");
                        }
                        else if(partida->sePuede(ca))//.nColumna, ca.nFila))
                        {
                                if(partidaClon != NULL)
                                {
                                        delete partidaClon;
                                        partidaClon = NULL;
                                }
                                partidaClon = partida->clona();
                                if(Deshacer->Enabled == false) Deshacer->Enabled = true;
                                cola->push(ca);
                                partida->aplicaJugada(ca);
                        }
                        //partida->aplicaJugada(ca);
                        interfaz->muestraEstado(*partida);//repaint
                        if(partida->fin())
                        {
                                partida->ponGanador();
                                ShowMessage("Partida finalizada");
                        }
                        interfaz->muestraEstado(*partida);
                }
                if(!partida->final() && (partida->dameTurno() == Jc)) //turno maquina
                {
                        interfaz->muestraEstado(*partida);
                        Sleep(MiliSec);
                        Casilla cb = jugador->juega(*partida);

                        /*if(juego == otelo && !partida->sePuede(cb))
                        {
                                partida->pasar();
                        } */

                        if(juego == otelo && cb.nColumna == 8)
                        {
                                partida->pasar();
                                pasar++;
                                cola->push(cb);
                        }
                        if(partida->sePuede(cb))
                        {
                                cola->push(cb);
                                partida->aplicaJugada(cb);
                        }
                        interfaz->muestraEstado(*partida);
                        if(partida->fin())
                        {
                                partida->ponGanador();
                                ShowMessage("Partida finalizada");
                        }
                }
                if (pasar == 2)
                {
                        partida->ponGanador();
                        ShowMessage("Partida finalizada por tablas");
                }
                }
                catch(Exception /*EG*/ &e)
                {
                        up = false;
                        ShowMessage(/*e.getMes().c_str()*/"Peta");
                }
                interfaz->muestraEstado(*partida);
                up= false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::juegaHumano()
{
        Casilla ca;
        cola->actualIter(ca);
        if(juego == otelo && ca.nColumna == 8)
        {
                partida->pasar();
                pasar++;
        }
        partida->aplicaJugada(ca);
        cola->avanzaIter();
        interfaz->muestraEstado(*partida);//repaint
        if(partida->fin())
        {
                partida->ponGanador();
                ShowMessage("Partida finalizada");
        }
}                       
//---------------------------------------------------------------------------
void __fastcall TFP::juegaOrdenador()
{
        Casilla cb;
        cola->actualIter(cb);
        if(juego == otelo && cb.nColumna == 8)
        {
                partida->pasar();
                pasar++;
        }
        partida->aplicaJugada(cb);
        cola->avanzaIter();
        interfaz->muestraEstado(*partida);
        if(partida->fin())
        {
                partida->ponGanador();
                ShowMessage("Partida finalizada");
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::FormCreate(TObject *Sender)
{
        juego = ninguno;
        partida = NULL;
        partidaClon = NULL;
        interfaz = NULL;
        jugador = NULL;
        cola = NULL;
        tipo = NULL;
        nivel = bajo;
        jugIni = Ja;
        MiliSec = 1000;
        up = false;
        humanos = false;
        Randomize();
        Bajo->Enabled = false;
        Medio->Enabled = false;
        Alto->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFP::FormDestroy(TObject *Sender)
{
        delete partidaClon;
        delete partida;
        delete cola;
        delete interfaz;
        delete jugador;
        int num = formularios.size();
        for(int i = 0; i < num; i++)
        {
                delete formularios.at(i);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::FormPaint(TObject *Sender)
{
        if((partida != NULL) && (interfaz != NULL))
        {
                interfaz->muestraEstado(*partida);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::Conecta4Click(TObject *Sender)
{
        juego = conecta4;
        if (interfaz != NULL)
        {
                delete interfaz;
                interfaz = NULL;
        }
        if (partida != NULL)
        {
                delete partida;
                partida = NULL;
        }
        ClientHeight = 350;
        ClientWidth = 350;
        Repaint();
        interfaz = new InterfazGrafC4(Canvas);  
        Bajo->Enabled = true;
        Medio->Enabled = true;
        Alto->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFP::OteloClick(TObject *Sender)
{
        juego = otelo;
        if (interfaz != NULL)
        {
                delete interfaz;
                interfaz = NULL;
        }
        if (partida != NULL)
        {
                delete partida;
                partida = NULL;
        }
        ClientHeight = 400;
        ClientWidth = 400;
        Repaint();
        interfaz = new InterfazGrafOtelo(Canvas); 
        Bajo->Enabled = true;
        Medio->Enabled = true;
        Alto->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFP::TresEnRayaClick(TObject *Sender)
{
        juego = raya;
        if (interfaz != NULL)
        {
                delete interfaz;
                interfaz = NULL;
        }
        if (partida != NULL)
        {
                delete partida;
                partida = NULL;
        }
        ClientHeight = 500;
        ClientWidth = 450;
        Repaint();
        interfaz = new InterfazGraf3Raya(Canvas);
        Bajo->Enabled = true; 
        Medio->Enabled = false;
        Alto->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFP::UsuarioClick(TObject *Sender)
{
        Turno t = Ja;
        jugIni = Ja;
        if(humanos == false)
        {
                if(jugador != NULL)     //con ésto nos quitamos la basura y podemos jugar directamente
                                        //contra la máquina si no elegimos inteligencia o usuario
                {
                        delete jugador;
                        jugador = NULL;
                }
                if(juego == conecta4)
                {
                        if(nivel == aleatorio)jugador = new JugadorAleaC4();
                        else jugador = new JugadorConzC4(nivel);
                }
                if(juego == otelo)
                {
                        if(nivel == aleatorio)jugador = new JugadorAleaOtelo();
                        else jugador = new JugadorConzOtelo(nivel);
                }
                if(juego == raya)
                {
                        if(nivel == aleatorio)jugador = new JugadorAlea3Raya();
                        else jugador = new JugadorConz3Raya(nivel);
                }
        }
        if(juego == conecta4)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGrafC4(Canvas);
                partida = new JuegoC4(t, humanos);
        }
        else if(juego == otelo)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGrafOtelo(Canvas);
                partida = new JuegoOtelo(t, humanos);
        }
        else if(juego == raya)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGraf3Raya(Canvas);
                partida = new Juego3Raya(t, humanos);
        }
        else ShowMessage("Debe seleccionar un juego antes.");
        if (cola != NULL)
        {
                delete cola;
                cola = NULL;
        }
        cola = new tColaIter<Casilla>();
}
//---------------------------------------------------------------------------
void __fastcall TFP::OrdenadorClick(TObject *Sender)
{
        Turno t;
        if (humanos == true)
        {
                t = Jb;
                jugIni = Jb;
        }
        else
        {
                t = Jc;
                jugIni = Jc;
        }
        if(humanos == false)
        {
                if(jugador != NULL)     //con ésto nos quitamos la basura y podemos jugar directamente
                {                        //contra la máquina si no elegimos inteligencia o usuario
                        delete jugador;
                        jugador = NULL;
                }
                if(juego == conecta4)
                {
                        if(nivel == aleatorio)jugador = new JugadorAleaC4();
                        else jugador = new JugadorConzC4(nivel);
                }
                if(juego == otelo)
                {
                        if(nivel == aleatorio)jugador = new JugadorAleaOtelo();
                        else jugador = new JugadorConzOtelo(nivel);
                }
                if(juego == raya)
                {
                        if(nivel == aleatorio)jugador = new JugadorAlea3Raya();
                        else jugador = new JugadorConz3Raya(nivel);
                }
        }
        else ShowMessage("Debe seleccionar un juego antes.");

        if(juego == conecta4)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGrafC4(Canvas);
                partida = new JuegoC4(t, humanos);
        }
        else if(juego == otelo)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGrafOtelo(Canvas);
                partida = new JuegoOtelo(t, humanos);
        }
        else if(juego == raya)
        {
                delete interfaz;
                interfaz = NULL;
                delete partida;
                partida = NULL;
                interfaz = new InterfazGraf3Raya(Canvas);
                partida = new Juego3Raya(t, humanos);
        }
        if(humanos == false)
        {
                //Primer turno si empieza la máquina
                Sleep(MiliSec);
                Casilla cb = jugador->juega(*partida);
                partida->aplicaJugada(cb);
                if(juego != otelo) partida->cambiaTurno();
                interfaz->muestraEstado(*partida);
        }

        if (cola != NULL)
        {
                delete cola;
                cola = NULL;
        }
        cola = new tColaIter<Casilla>();
}
//---------------------------------------------------------------------------
void __fastcall TFP::OtroUsuarioClick(TObject *Sender)
{
        humanos = true;
}
//---------------------------------------------------------------------------


void __fastcall TFP::AleatorioClick(TObject *Sender)
{
        humanos = false;
        nivel = aleatorio;
}
//---------------------------------------------------------------------------

void __fastcall TFP::GuardarClick(TObject *Sender)
{
        if (SaveDialog->Execute())
        {
                archivo = SaveDialog->FileName;
                ofstream fich;
                fich.open(archivo.c_str(),ios::binary);
                fich.write((char*)& humanos,sizeof(bool));
                int jug;
                if(jugIni == Ja)
                {
                        jug = 0;
                        fich.write((char*)& jug,sizeof(int));
                }
                else if(jugIni == Jb)
                {
                        jug = 1;
                        fich.write((char*)& jug,sizeof(int));
                }
                else if(jugIni == Jc)
                {
                        jug = 2;
                        fich.write((char*)& jug,sizeof(int));
                }
                int n;
                if(juego == conecta4)
                {
                        n = 0;
                        fich.write((char*)& n,sizeof(int));
                }
                else if(juego == otelo)
                {
                        n = 1;
                        fich.write((char*)& n,sizeof(int));
                }
                else if(juego == raya)
                {
                        n = 2;
                        fich.write((char*)& n,sizeof(int));
                }
		int niv;
		if(nivel == aleatorio)
		{
			niv = 0;
			fich.write((char*)& niv, sizeof(int));
		}
		else if(nivel == bajo)
		{
			niv = 2;
			fich.write((char*)& niv, sizeof(int));
		}
		else if(nivel == medio)
		{
			niv = 4;
			fich.write((char*)& niv, sizeof(int));
		}
		else if(nivel == alto)
		{
			niv = 6;
			fich.write((char*)& niv, sizeof(int));
		}
                partida->salvar(fich);
                cola->iniciaIter();
                int cont = cola->size();
                Casilla aux;
                fich.write((char*)& cont,sizeof(int));
                for(int i = 0; i < cont; i++)
                {
                        if(cola->actualIter(aux))
                        {
                                //cola->actualIter(aux);
                                fich.write((char*)& aux.nFila,sizeof(int));
                                fich.write((char*)& aux.nColumna,sizeof(int));
                                cola->avanzaIter();
                        }
                }
                fich.close();
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::CargarClick(TObject *Sender)
{
        if (OpenDialog->Execute())
        {
                up = true;
                archivo = OpenDialog->FileName;
                ifstream fich;
                fich.open(archivo.c_str(),ios::binary);
                fich.read((char*)& humanos,sizeof(bool));
                if (jugador != NULL)
                {
                        delete jugador;
                        jugador = NULL;
                }
                if (cola != NULL)
                {
                        delete cola;
                        cola = NULL;
                }
                int jug;
                fich.read((char*)& jug,sizeof(int));
                if (jug == 0) jugIni = Ja;
                else if (jug == 1) jugIni = Jb;
                else if (jug == 2) jugIni = Jc;
                int n;
                fich.read((char*)& n,sizeof(int));
                if (interfaz != NULL)
                {
                        delete interfaz;
                        interfaz = NULL;
                }
                if (partida != NULL)
                {
                        delete partida;
                        partida = NULL;
                }
                if (n == 0)
                {
                        juego = conecta4;
                        partida = new JuegoC4(jugIni,humanos);
                        ClientHeight = 350;
                        ClientWidth = 350;
                        Repaint();
                        interfaz = new InterfazGrafC4(Canvas);
                }
                else if (n == 1)
                {
                        juego = otelo;
                        partida = new JuegoOtelo(jugIni,humanos);
                        ClientHeight = 400;
                        ClientWidth = 400;
                        Repaint();
                        interfaz = new InterfazGrafOtelo(Canvas);
                }
                else if (n == 2)
                {
                        juego = raya;
                        partida = new Juego3Raya(jugIni,humanos);
                        ClientHeight = 500;
                        ClientWidth = 450;
                        Repaint();
                        interfaz = new InterfazGraf3Raya(Canvas);
                }
                int niv;
		fich.read((char*)& niv, sizeof(int));
                if(!humanos)
                {
			if(niv == 0)
			{                        
				if(juego == conecta4)jugador = new JugadorAleaC4();
                        	if(juego == otelo)jugador = new JugadorAleaOtelo();
                        	if(juego == raya)jugador = new JugadorAlea3Raya();
				nivel = aleatorio;
			}
			else if(niv == 2)
			{
				if(juego == conecta4)jugador = new JugadorConzC4(2);
                        	if(juego == otelo)jugador = new JugadorConzOtelo(2);
                        	if(juego == raya)jugador = new JugadorConz3Raya(2);
				nivel = bajo;
			}
			else if(niv == 4)
			{
				if(juego == conecta4)jugador = new JugadorConzC4(4);
                        	if(juego == otelo)jugador = new JugadorConzOtelo(4);
                        	if(juego == raya)jugador = new JugadorConz3Raya(4);
				nivel = medio;
			}
			else if(niv == 6)
			{
				if(juego == conecta4)jugador = new JugadorConzC4(6);
                        	if(juego == otelo)jugador = new JugadorConzOtelo(6);
                        	if(juego == raya)jugador = new JugadorConz3Raya(6);
				nivel = alto;
			}
			
                }
                partida->cargar(fich);
                int cont;
                Casilla aux;
                cola = new tColaIter<Casilla>();
                fich.read((char*)& cont,sizeof(int));
                for(int i = 0; i < cont; i++)
                {
                        fich.read((char*)& aux.nFila,sizeof(int));
                        fich.read((char*)& aux.nColumna,sizeof(int));
                        cola->push(aux);
                }
                fich.close();
                cola->iniciaIter();
                //aplica jugadas
                if (jugIni != Jc) juegaHumano();
                else juegaOrdenador();
                for(int i = 0; i < cont-1; i++)
                {
                        Sleep(MiliSec);
                        if(partida->dameTurno() != Jc) juegaHumano();
                        else juegaOrdenador();
                }
                Sleep(500);
                interfaz->muestraEstado(*partida);
                Deshacer->Enabled = false;
                ShowMessage("Cargar finalizado");
                up = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFP::AboutClick(TObject *Sender)
{
        AboutWindow->ShowModal();         
}
//---------------------------------------------------------------------------
void __fastcall TFP::BajoClick(TObject *Sender)
{
        humanos = false;
        nivel = bajo;
}
//---------------------------------------------------------------------------
void __fastcall TFP::MedioClick(TObject *Sender)
{
        humanos = false;
        nivel = medio;
}
//---------------------------------------------------------------------------
void __fastcall TFP::AltoClick(TObject *Sender)
{
        humanos = false;
        nivel = alto;
}
//---------------------------------------------------------------------------
void __fastcall TFP::DeshacerClick(TObject *Sender)
{
        delete partida;
        partida = NULL;
        partida = partidaClon->clona();

        tColaIter<Casilla>* cola_aux = new tColaIter<Casilla>();
        cola->iniciaIter();
        Casilla aux;
        int size = cola->size();
        for(int i = 0; i < size - 2; i++)
        {
                cola->actualIter(aux);
                cola->pop();
                cola->iniciaIter();
                cola_aux->push(aux);
        }
        cola->pop();
        cola->pop();
        cola_aux->iniciaIter();
        size = cola_aux->size();
        for(int i = 0; i < size; i++)
        {
                cola_aux->actualIter(aux);
                cola_aux->pop();
                cola_aux->iniciaIter();
                cola->push(aux);
        }
        delete cola_aux;
        cola_aux = NULL;

        Repaint();
        Deshacer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFP::OtraVentanaClick(TObject *Sender)
{
        TFP* nuevaVentana = new TFP(NULL);
        formularios.insert(nuevaVentana);
        nuevaVentana->Show();
        nuevaVentana->OtraVentana->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TFP::borraFormulario(TFP* form)
{
        delete form;
        int pos;
        FP->formularios.find(this, pos);
        FP->formularios.erase(pos);
	/* Al sólo ser posible crear nuevas ventanas a partir de la principal
	llamamos al find y el erase de la ListaOrd del FP. Si cada uno pudiera tener
	sus propios hijos, habría que usar Owner->
	*/
}
//---------------------------------------------------------------------------
void __fastcall TFP::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(this->OtraVentana->Visible == false)
        {
                borraFormulario(this);
                ShowMessage("Se ha eliminado la partida.");
        }
        else ShowMessage("Gracias por utilizar el juegator2000.");
}
//---------------------------------------------------------------------------

