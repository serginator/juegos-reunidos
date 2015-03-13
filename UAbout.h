//---------------------------------------------------------------------------

#ifndef UAboutH
#define UAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TAboutWindow : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *botonSalirAbout;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TImage *Image1;
        void __fastcall botonSalirAboutClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAboutWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutWindow *AboutWindow;
//---------------------------------------------------------------------------
#endif
