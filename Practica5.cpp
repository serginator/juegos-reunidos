//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica5.res");
USEUNIT("Juego2JTab.cpp");
USEUNIT("JuegoOtelo.cpp");
USEUNIT("JuegoC4.cpp");
USEUNIT("Jugador.cpp");
USEUNIT("JugadorAleaOtelo.cpp");
USEUNIT("JugadorAleaC4.cpp");
USEUNIT("JugadorConzOtelo.cpp");
USEUNIT("JugadorConzC4.cpp");
USEFORM("UFP.cpp", FP);
USEUNIT("Arbol.cpp");
USEUNIT("UtLista.cpp");
USEUNIT("UtListaOrd.cpp");
USEUNIT("Arbol2JTab.cpp");
USEUNIT("InterfazGraf2JTab.cpp");
USEUNIT("InterfazGrafOtelo.cpp");
USEUNIT("InterfazGrafC4.cpp");
USE("\\alar\home\50555057\200809\LP2\Practica(5S)(6J)\PR5\UtMatriz.h", File);
USEUNIT("InterfazGraf3Raya.cpp");
USEUNIT("Juego3Raya.cpp");
USEUNIT("JugadorAlea3Raya.cpp");
USEUNIT("UtColaIter.cpp");
USEUNIT("JugadorConz3Raya.cpp");
USEFORM("UAbout.cpp", AboutWindow);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFP), &FP);
                 Application->CreateForm(__classid(TAboutWindow), &AboutWindow);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
