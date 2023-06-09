//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "SuperUserHome.h"
#include "VirtualClassroomLogin.h"
#include "User.h"
#include "Administrator.h"
#include "School.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSuperUserHomeForm *SuperUserHomeForm;
//---------------------------------------------------------------------------
__fastcall TSuperUserHomeForm::TSuperUserHomeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSuperUserHomeForm::FormClose(TObject *Sender, TCloseAction &Action)

{
     LoginForm->Close();
}
//---------------------------------------------------------------------------


void __fastcall TSuperUserHomeForm::CreateAdministratorButtonClick(TObject *Sender)

{
     AnsiString AnsiEmail = EmailEdit->Text;
     string Email = AnsiEmail.c_str();
     AnsiString AnsiPassword = PasswordEdit->Text;
     string Password = AnsiPassword.c_str();
     AnsiString AnsiFirstName = FirstNameEdit->Text;
     string FirstName = AnsiFirstName.c_str();
     AnsiString AnsiLastName = LastNameEdit->Text;
     string LastName = AnsiLastName.c_str();
     AnsiString AnsiBirthdate = BirthdateEdit->Text;
     string Birthdate = AnsiBirthdate.c_str();
     AnsiString AnsiPhoneNumber = PhoneNumberEdit->Text;
     string PhoneNumber = AnsiPhoneNumber.c_str();
     AnsiString AnsiAddress = AddressEdit->Text;
     string Address = AnsiAddress.c_str();
     AnsiString AnsiGender = GenderEdit->Text;
     string Gender = AnsiGender.c_str();
     AnsiString AnsiSecurityQuestion = SecurityQuestionEdit->Text;
     string SecurityQuestion = AnsiSecurityQuestion.c_str();
     AnsiString AnsiSecurityAnswer = SecurityAnswerEdit->Text;
     string SecurityAnswer = AnsiSecurityAnswer.c_str();
     AnsiString AnsiJobTitle = JobTitleEdit->Text;
     string JobTitle = AnsiJobTitle.c_str();


     std::unique_ptr<User> obj = std::make_unique<Administrator>(Email, Password, FirstName,
     LastName, Gender, Birthdate, PhoneNumber, Address, SecurityQuestion, SecurityAnswer, JobTitle);

     School::GetInstance().AddAdministrator(std::move(obj));
     School::GetInstance().SaveUsers();
}
//---------------------------------------------------------------------------

