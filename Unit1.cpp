//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = 8;
int y = 8;
int punkty_lewy = 0;
int punkty_prawy = 0;
AnsiString punkty_l, punkty_p, odbicia_s;
int ilosc_odbic = 0;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
pilka->Left += x;
pilka->Top += y;

//odbij od gory
if(pilka->Top-5 <= tlo->Top) y=-y;
//odbij od dolu
if(pilka->Top+pilka->Height+5 >= tlo->Height) y=-y;

//punkt dla lewego
if(pilka->Left+pilka->Width >= tlo->Width)

{
        Timer_pilka->Enabled = false;
        pilka->Visible = false;
        punkty_lewy ++;
        punkty_l = IntToStr(punkty_lewy);
        punkty_p = IntToStr(punkty_prawy);
        przycisk->Caption = "<<< Punkt dla niebieskiego!";
        przycisk->Visible = true;
}
if(pilka->Top+pilka->Height/2 <= prawy->Top+prawy->Height && pilka->Top+pilka->Height/2 >= prawy->Top &&
        pilka->Left+pilka->Width >= prawy->Left && pilka->Left+pilka->Width <= prawy->Left+prawy->Width)
        {
         if (x>0)
         {
         ilosc_odbic++;
          if (pilka->Top+pilka->Height/2 <= prawy->Top+prawy->Height*0.65 && pilka->Top+pilka->Height/2 >= prawy->Top+prawy->Height*0.35 && x>0) {x = -12;}
          else x=-8;
         }
         //przyspieszenie
         if(ilosc_odbic > 5 && ilosc_odbic <= 10) Timer_pilka->Interval == 15;
         if(ilosc_odbic > 10) Timer_pilka->Interval == 10;
        };
//punkt dla prawego

     if (pilka->Left <= tlo->Left)
     {
       Timer_pilka->Enabled = false;
       pilka->Visible = false;
       punkty_prawy ++;
       punkty_l = IntToStr(punkty_lewy);
       punkty_p = IntToStr(punkty_prawy);
       przycisk->Caption = "Punkt dla czerwonego! >>>";
       przycisk->Visible = true;
     }
if(pilka->Top+pilka->Height/2 <= lewy->Top+lewy->Height && pilka->Top+pilka->Height/2 >= lewy->Top &&
        pilka->Left <= lewy->Left+lewy->Width && pilka->Left >= lewy->Left)
        {
         if (x<0)
         {
         ilosc_odbic++;
          if (pilka->Top+pilka->Height/2 <= lewy->Top+lewy->Height*0.65 && pilka->Top+pilka->Height/2 >= lewy->Top+lewy->Height*0.35 && x<0) {x = 12;}
          else x=8;
          //przyspieszenie
         if(ilosc_odbic >= 5 && ilosc_odbic <= 10) Timer_pilka->Interval = 15;
         if(ilosc_odbic > 10) Timer_pilka->Interval = 10;
         }
        };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewy_dolTimer(TObject *Sender)
{
        if(lewy->Top+lewy->Height < tlo->Height-10)lewy->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewy_goraTimer(TObject *Sender)
{
        if(lewy->Top > 10)lewy->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP) prawy_gora->Enabled = true;
        if (Key == VK_DOWN) prawy_dol->Enabled = true;
        if (Key == 0x57) lewy_gora->Enabled = true;
        if (Key == 0x53) lewy_dol->Enabled = true;

        if (Key == VK_RIGHT) prawy_prawo->Enabled = true;
        if (Key == VK_LEFT) prawy_lewo->Enabled = true;
        if (Key == 0x44) lewy_prawo->Enabled = true;
        if (Key == 0x41) lewy_lewo->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP) prawy_gora->Enabled = false;
        if (Key == VK_DOWN) prawy_dol->Enabled = false;
        if (Key == 0x57) lewy_gora->Enabled = false;
        if (Key == 0x53) lewy_dol->Enabled = false;

        if (Key == VK_RIGHT) prawy_prawo->Enabled = false;
        if (Key == VK_LEFT) prawy_lewo->Enabled = false;
        if (Key == 0x44) lewy_prawo->Enabled = false;
        if (Key == 0x41) lewy_lewo->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawy_goraTimer(TObject *Sender)
{
        if(prawy->Top > 10)prawy->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawy_dolTimer(TObject *Sender)
{
        if(prawy->Top+prawy->Height < tlo->Height-10)prawy->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewy_lewoTimer(TObject *Sender)
{
        if(lewy->Left >10) lewy->Left -= 5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewy_prawoTimer(TObject *Sender)
{
        if(lewy->Left+lewy->Width < tlo->Width/3) lewy->Left += 5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawy_prawoTimer(TObject *Sender)
{
        if(prawy->Left+prawy->Width < tlo->Width) prawy->Left += 5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawy_lewoTimer(TObject *Sender)
{
        if(prawy->Left > tlo->Width/3*2) prawy->Left -= 5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::przyciskClick(TObject *Sender)
{
        pilka->Left = tlo->Width/2;
        pilka->Top = tlo->Height/2;

        lewy->Left = 10;
        prawy->Left = tlo->Width-10-prawy->Width;
        lewy->Top = tlo->Height/2-lewy->Height/2;
        prawy->Top = tlo->Height/2-prawy->Height/2;

        przycisk->Visible = false;
        punktacja->Caption = "Niebieski: " + punkty_l + " Czerwony: " + punkty_p;
        punktacja->Visible = true;
        odbicia_s = IntToStr(ilosc_odbic);
        odbicia->Caption = "Odbicia: " + odbicia_s;
        ilosc_odbic = 0;
        odbicia->Visible = true;
        dalej->Visible = true;
        nowa_gra->Visible = true;

        if (przycisk->Caption == "<<< Punkt dla niebieskiego!")
        x = 8; y = 8;
        if (przycisk->Caption == "Punkt dla czerwonego! >>>")
        x = -8; y = -8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::dalejClick(TObject *Sender)
{
lewy->Left = tlo->Left + 15;
lewy->Top = tlo->Height/2 - lewy->Height/2;
prawy->Left = tlo->Width - 15 - prawy->Width;
prawy->Top = tlo->Height/2 - prawy->Height/2;
dalej->Visible = false;
punktacja->Visible = false;
odbicia->Visible = false;
nowa_gra->Visible = false;
pilka->Visible = true;
Timer_pilka->Enabled = true;
Timer_pilka->Interval = 20;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::nowa_graClick(TObject *Sender)
{
lewy->Left = tlo->Left + 15;
lewy->Top = tlo->Height/2 - lewy->Height/2;
prawy->Left = tlo->Width - 15 - prawy->Width;
prawy->Top = tlo->Height/2 - prawy->Height/2;
punkty_lewy = 0;
punkty_prawy = 0;
Timer_pilka->Interval = 20;
punktacja->Visible = false;
odbicia->Visible = false;
dalej->Visible = false;
nowa_gra->Visible = true;

pilka->Visible = true;
Timer_pilka->Enabled = true;

nowa_gra->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnShowMsgClick(TObject *Sender)
{
	AnsiString str1 = "PING-PONG";
	AnsiString str2 = "Sterowanie lewego gracze: W, S, A, D.";
	AnsiString str3 = "Prawy gracz uzywa strzalek.";
	AnsiString str4 = "Jezeli uda Ci sie odbic pilke najbardziej centralna czescia paletki to pilka przyspieszy pod zmienionym katem.";
        AnsiString str5 = "W miare uplywu rozgrywki pilka bedzie poruszac sie szybciej.";
        AnsiString str6 = "Mozesz zmieniac rozmiar pola gry.";
        AnsiString str7 = "Zaczynajmy!";

	ShowMessage(str1 + sLineBreak + sLineBreak + str2 + sLineBreak +
			str3 + sLineBreak + sLineBreak + str4 + sLineBreak + str5 + sLineBreak + str6 + sLineBreak + sLineBreak + str7);
}
//---------------------------------------------------------------------------

