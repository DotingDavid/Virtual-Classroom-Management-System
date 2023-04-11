//---------------------------------------------------------------------------

#include <fmx.h>
#include <FMX.Graphics.hpp>
#include <System.UIConsts.hpp>
#include <System.UITypes.hpp>

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
    Left = 0;
    Top = 0;
	Width = Screen->Width;
	Height = Screen->Height;

}
//---------------------------------------------------------------------------




void __fastcall TAdministratorUserAccountsForm::HomeMenuItemRectMouseEnter(TObject *Sender)

{
	HomeMenuItemRect->Fill->Kind = TBrushKind::Solid;
	HomeMenuItemRect->Fill->Color = 0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::HomeMenuItemRectMouseLeave(TObject *Sender)

{
	HomeMenuItemRect->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::HomeMenuItemRectClick(TObject *Sender)

{
	AdministratorHomeForm->Show();
	AdministratorUserAccountsForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::UserAccountsMenuItemRectMouseEnter(TObject *Sender)

{
	UserAccountsMenuItemRect->Fill->Kind = TBrushKind::Solid;
	UserAccountsMenuItemRect->Fill->Color = 0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::UserAccountsMenuItemRectMouseLeave(TObject *Sender)

{
	UserAccountsMenuItemRect->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::UserAccountsMenuItemRectClick(TObject *Sender)

{
	AdministratorUserAccountsForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::ManageCoursesMenuItemRectMouseEnter(TObject *Sender)

{
	ManageCoursesMenuItemRect->Fill->Kind = TBrushKind::Solid;
	ManageCoursesMenuItemRect->Fill->Color = 0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::ManageCoursesMenuItemRectMouseLeave(TObject *Sender)

{
	ManageCoursesMenuItemRect->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::ManageCoursesMenuItemRectClick(TObject *Sender)

{
	//AdministratorManageCoursesForm->Show();
	AdministratorUserAccountsForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::StudentStatisticsMenuItemRectMouseEnter(TObject *Sender)

{
	StudentStatisticsMenuItemRect->Fill->Kind = TBrushKind::Solid;
	StudentStatisticsMenuItemRect->Fill->Color = 0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::StudentStatisticsMenuItemRectMouseLeave(TObject *Sender)

{
	StudentStatisticsMenuItemRect->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::StudentStatisticsMenuItemRectClick(TObject *Sender)

{
	//AdministratorStudentStatisticsForm->Show();
	AdministratorUserAccountsForm->Close();
}
//---------------------------------------------------------------------------


