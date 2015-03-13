//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutWindow *AboutWindow;
//---------------------------------------------------------------------------
__fastcall TAboutWindow::TAboutWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutWindow::botonSalirAboutClick(TObject *Sender)
{
        AboutWindow->Close();
}
//---------------------------------------------------------------------------

