//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>


#include "Juego2JTab.h"
#include "InterfazGraf2JTab.h"
#include "InterfazGrafC4.h"
#include "InterfazGrafOtelo.h"
#include "InterfazGraf3Raya.h"
#include "JugadorAleaC4.h"
#include "JugadorAleaOtelo.h"
#include "JugadorAlea3Raya.h"
#include "UtColaIter.h"
#include "UAbout.h"
#include "JugadorConzC4.h"
#include "JugadorConzOtelo.h"
#include "JugadorConz3Raya.h"
#include "UtListaOrd.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFP : public TForm
{


__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Juego;
        TMenuItem *Jugador1;
        TMenuItem *Partida;
        TMenuItem *OtraVentana;
        TMenuItem *About;
        TMenuItem *Otelo;
        TMenuItem *Conecta4;
        TMenuItem *TresEnRaya;
        TMenuItem *Aleatorio;
        TMenuItem *Concienzudo;
        TMenuItem *Bajo;
        TMenuItem *Medio;
        TMenuItem *Alto;
        TMenuItem *OtroUsuario;
        TMenuItem *Inicia;
        TMenuItem *Usuario;
        TMenuItem *Ordenador;
        TMenuItem *Deshacer;
        TMenuItem *N1;
        TMenuItem *Guardar;
        TMenuItem *Cargar;
        TMenuItem *Salir;
        TSaveDialog *SaveDialog;
        TOpenDialog *OpenDialog;
        void __fastcall SalirClick(TObject *Sender);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall juegaHumano();
        void __fastcall juegaOrdenador();
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall Conecta4Click(TObject *Sender);
        void __fastcall OteloClick(TObject *Sender);
        void __fastcall UsuarioClick(TObject *Sender);
        void __fastcall OrdenadorClick(TObject *Sender);
        void __fastcall OtroUsuarioClick(TObject *Sender);
        void __fastcall AleatorioClick(TObject *Sender);
        void __fastcall TresEnRayaClick(TObject *Sender);
        void __fastcall GuardarClick(TObject *Sender);
        void __fastcall CargarClick(TObject *Sender);
        void __fastcall AboutClick(TObject *Sender);
        void __fastcall BajoClick(TObject *Sender);
        void __fastcall MedioClick(TObject *Sender);
        void __fastcall AltoClick(TObject *Sender);
        void __fastcall DeshacerClick(TObject *Sender);
        void __fastcall OtraVentanaClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations

        static bool menor(TFP* t1, TFP* t2)
        {
                if (t1 < t2) return true;
                return false;
        };

        bool up;/*Cuando es el turno de la maquina || el juego no ha comenzado ||
        la partida ha terminado up tiene que ser false*/
        int MiliSec;
        Juego2JTab* partida;
        Juego2JTab* partidaClon;
        Jugador* jugador;
        bool humanos;
        int pasar;
        tColaIter<Casilla>* cola;
        tListaOrd<TFP*, menor> formularios;
        AnsiString archivo;


        enum enuJuego{ninguno, conecta4, otelo, raya};
        enum enuJugador{otro, alea, conz};
        enum enuNivel{aleatorio=0,bajo=2, medio=4, alto=6};


        enuJuego juego;
        enuJugador tipo;
        enuNivel nivel;
        Turno jugIni;

public:		// User declarations
        __fastcall TFP(TComponent* Owner);
        InterfazGraf2JTab* interfaz;
        void __fastcall borraFormulario(TFP* form);
};
//---------------------------------------------------------------------------
extern PACKAGE TFP *FP;
//---------------------------------------------------------------------------
#endif
