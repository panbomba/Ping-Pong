//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *pilka;
        TTimer *Timer_pilka;
        TImage *lewy;
        TImage *prawy;
        TTimer *lewy_gora;
        TTimer *lewy_dol;
        TTimer *prawy_gora;
        TTimer *prawy_dol;
        TTimer *lewy_lewo;
        TTimer *lewy_prawo;
        TTimer *prawy_lewo;
        TTimer *prawy_prawo;
        TButton *przycisk;
        TLabel *punktacja;
        TButton *dalej;
        TLabel *odbicia;
        TButton *nowa_gra;
        TButton *btnShowMsg;
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall lewy_dolTimer(TObject *Sender);
        void __fastcall lewy_goraTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall prawy_goraTimer(TObject *Sender);
        void __fastcall prawy_dolTimer(TObject *Sender);
        void __fastcall lewy_lewoTimer(TObject *Sender);
        void __fastcall lewy_prawoTimer(TObject *Sender);
        void __fastcall prawy_prawoTimer(TObject *Sender);
        void __fastcall prawy_lewoTimer(TObject *Sender);
        void __fastcall przyciskClick(TObject *Sender);
        void __fastcall dalejClick(TObject *Sender);
        void __fastcall nowa_graClick(TObject *Sender);
        void __fastcall btnShowMsgClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
