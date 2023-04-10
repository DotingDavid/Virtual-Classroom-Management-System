//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AdministratorUserAccounts.h"
#include "AdministratorHome.h"
#include "CustomPanel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

TAdministratorUserAccountsForm *AdministratorUserAccountsForm;
//---------------------------------------------------------------------------
__fastcall TAdministratorUserAccountsForm::TAdministratorUserAccountsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::FormClose(TObject *Sender, TCloseAction &Action)

{
    AdministratorHomeForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall TAdministratorUserAccountsForm::FormCreate(TObject *Sender)
{
	Width = 1080;
	Height = 720;
}
//---------------------------------------------------------------------------




