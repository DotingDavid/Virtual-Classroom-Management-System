//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AdministratorHome.h"
#include "AdministratorManageCourses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TAdministratorManageCoursesForm *AdministratorManageCoursesForm;
//---------------------------------------------------------------------------
__fastcall TAdministratorManageCoursesForm::TAdministratorManageCoursesForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorManageCoursesForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	AdministratorHomeForm->Show();
}
//---------------------------------------------------------------------------
