//---------------------------------------------------------------------------

#include <fmx.h>
#include <algorithm>
#include <FMX.Grid.hpp>
#pragma hdrstop

#include "School.h"
#include "Administrator.h"
#include "AdministratorHome.h"
#include "AdministratorUserAccounts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdministratorUIParent"
#pragma resource "*.fmx"
TAdministratorUserAccountsForm *AdministratorUserAccountsForm;
//---------------------------------------------------------------------------
__fastcall TAdministratorUserAccountsForm::TAdministratorUserAccountsForm(TComponent* Owner)
	: TAdministratorUIParentForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::ClearCreateEdits()
{
	 JobTitleEdit->Text = "";
	 EmailEdit->Text = "";
	 PasswordEdit->Text = "";
	 FirstNameEdit->Text = "";
	 LastNameEdit->Text = "";
	 BirthdateEdit->Text = "";
	 PhoneNumberEdit->Text = "";
	 AddressEdit->Text = "";
	 GenderEdit->Text = "";
	 SecurityQuestionEdit->Text = "";
	 SecurityAnswerEdit->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::AdjustColumnWidths()
{
	// Initialize a vector to store the maximum width for each column
	std::vector<int> maxWidths(AdministratorAccountsStringGrid->ColumnCount, 0);

	// Iterate over all cells in the TStringGrid
	for (int i = 0; i < AdministratorAccountsStringGrid->RowCount; ++i)
    {
		for (int j = 0; j < AdministratorAccountsStringGrid->ColumnCount; ++j)
        {
			// Calculate the width of the current cell or header
			int cellWidth = AdministratorAccountsStringGrid->Canvas->TextWidth(AdministratorAccountsStringGrid->Cells[j][i]);

			// If the current row is the first row, then we need to compare the cell width with the header width
			if (i == 0)
            {
				int headerWidth = AdministratorAccountsStringGrid->Canvas->TextWidth(AdministratorAccountsStringGrid->Columns[j]->Header);
				cellWidth = std::max(cellWidth, headerWidth);
            }

			// Update the maximum width for the current column, if needed
            if (cellWidth > maxWidths[j])
			{
				maxWidths[j] = cellWidth;
			}
		}
	}

	// Set the total available width
	int totalAvailableWidth = AdministratorAccountsStringGrid->Width;

	// Calculate the total required width for all columns based on the maxWidths
	int totalRequiredWidth = 0;
	for (int maxWidth : maxWidths)
	{
		totalRequiredWidth += maxWidth;
	}

	// Calculate the remaining width that needs to be distributed among the columns
	int remainingWidth = totalAvailableWidth - totalRequiredWidth;

	// Adjust the width of each column based on the calculated maximum width and distribute the remaining width
	int extraWidthPerColumn = (remainingWidth) / AdministratorAccountsStringGrid->ColumnCount;

	for (int j = 0; j < AdministratorAccountsStringGrid->ColumnCount; ++j)
	{
		AdministratorAccountsStringGrid->Columns[j]->Width = maxWidths[j];

		// Distribute the remaining width among the columns evenly
		AdministratorAccountsStringGrid->Columns[j]->Width += (extraWidthPerColumn);

		// Width
		//AdministratorAccountsStringGrid->Columns[7]->Width;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::PopulateGridWithAdministrators(const std::vector<std::unique_ptr<User>>& administrators)
{
	// Set the row count based on the number of administrators
	AdministratorAccountsStringGrid->RowCount = administrators.size();

	// Add headers for the columns
	AdministratorAccountsStringGrid->Columns[0]->Header = "User ID";
	AdministratorAccountsStringGrid->Columns[1]->Header = "Job Title";
	AdministratorAccountsStringGrid->Columns[2]->Header = "First Name";
	AdministratorAccountsStringGrid->Columns[3]->Header = "Last Name";
	AdministratorAccountsStringGrid->Columns[4]->Header = "Gender";
	AdministratorAccountsStringGrid->Columns[5]->Header = "Date of Birth";
	AdministratorAccountsStringGrid->Columns[6]->Header = "Phone Number";
	AdministratorAccountsStringGrid->Columns[7]->Header = "Blocked?";

	// Populate StrinGrid
	for (int i=0; i < administrators.size(); i++)
	{
		User* admin = administrators[i].get();
		Administrator* admin_ptr = dynamic_cast<Administrator*>(admin);

		if (admin_ptr)
		{
			AdministratorAccountsStringGrid->Cells[0][i] = admin_ptr->GetUserID().c_str();
			AdministratorAccountsStringGrid->Cells[1][i] = admin_ptr->GetJobTitle().c_str();
			AdministratorAccountsStringGrid->Cells[2][i] = admin_ptr->GetFirstName().c_str();
			AdministratorAccountsStringGrid->Cells[3][i] = admin_ptr->GetLastName().c_str();
			AdministratorAccountsStringGrid->Cells[4][i] = admin_ptr->GetGender().c_str();
			AdministratorAccountsStringGrid->Cells[5][i] = admin_ptr->GetDateOfBirth().c_str();
			AdministratorAccountsStringGrid->Cells[6][i] = admin_ptr->GetPhoneNumber().c_str();
			AdministratorAccountsStringGrid->Cells[7][i] = admin_ptr->GetIsBlocked() ? "Blocked" : "Not Blocked";
		}
	}
}

void __fastcall TAdministratorUserAccountsForm::FormCreate(TObject *Sender)
{
	Left = 0;
	Top = 0;
	Width = ((Screen->Width)-50);
	Height = ((Screen->Height)-50);

	TShadowEffect *dropShadow = new TShadowEffect(this);
    dropShadow->Parent = PopupProfileMenuBackground;
	dropShadow->Enabled = true;
	dropShadow->Softness = 0.6f;  // A higher value creates a softer shadow
	dropShadow->Distance = 2.0f;  // A lower value creates a shorter shadow
	dropShadow->Direction = 90.0f; // Set the direction to 90 degrees (downwards)
    dropShadow->ShadowColor = claBlack;
	dropShadow->Opacity = 0.25f;
	dropShadow->SendToBack();

	PopulateGridWithAdministrators(School::GetInstance().GetAdministrators());
	AdjustColumnWidths();
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::AdministratorAccountsStringGridDrawColumnHeader(TObject *Sender,
		  TCanvas * const Canvas, TColumn * const Column, const TRectF &Bounds)
{
	// Clear the header area with a solid color (white in this case)
	Canvas->Fill->Color = TAlphaColorRec::White;
	Canvas->FillRect(Bounds, 0, 0, {}, 1);

	TFont *oldFont = new TFont();
    TBrush *oldFill = new TBrush(TBrushKind::Solid, TAlphaColorRec::Black);

    oldFont->Assign(Canvas->Font); // Save the old font settings
    oldFill->Assign(Canvas->Fill); // Save the old fill settings

	Canvas->Font->Size = 10; // Set the header font size
	Canvas->Fill->Color = TAlphaColorRec::Slategray; // Set the header font color

	TFillTextFlags fillTextFlags = TFillTextFlags();

	// Add padding to the header text
	float paddingHorizontal = 6;
	float paddingVertical = 5;
	TRectF paddedBounds = TRectF(Bounds.Left + paddingHorizontal, Bounds.Top + paddingVertical, Bounds.Right - paddingHorizontal, Bounds.Bottom - paddingVertical);

	Canvas->FillText(paddedBounds, Column->Header, false, 1, fillTextFlags, TTextAlign::Leading, TTextAlign::Leading);

	Canvas->Font->Assign(oldFont); // Restore the old font settings
	Canvas->Fill->Assign(oldFill); // Restore the old fill settings

	delete oldFont;
	delete oldFill;
}

//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::CreateAdministratorButtonClick(TObject *Sender)

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
	 ClearCreateEdits();
	 PopulateGridWithAdministrators(School::GetInstance().GetAdministrators());
	 AdjustColumnWidths();
}
//---------------------------------------------------------------------------

