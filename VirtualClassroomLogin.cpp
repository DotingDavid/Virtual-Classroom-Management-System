//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "VirtualClassroomLogin.h"
#include "SuperUserHome.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TLoginForm::LoginButtonClick(TObject *Sender)
{
       if(UsernameEdit->Text == "SuperUser") {
            if(PasswordEdit->Text == "HorizonSU") {
            SuperUserHomeForm->Show();
            LoginForm->Hide();
            }
       }
}
//---------------------------------------------------------------------------

