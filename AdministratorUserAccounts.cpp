//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AdministratorUserAccounts.h"
#include "AdministratorHome.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
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