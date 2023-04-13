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
void __fastcall TAdministratorUserAccountsForm::AdjustColumnWidths()
{
	// Initialize a vector to store the maximum width for each column
	std::vector<int> maxWidths(StringGrid1->ColumnCount, 0);

	// Iterate over all cells in the TStringGrid
    for (int i = 0; i < StringGrid1->RowCount; ++i)
    {
		for (int j = 0; j < StringGrid1->ColumnCount; ++j)
        {
            // Calculate the width of the current cell or header
			int cellWidth = StringGrid1->Canvas->TextWidth(StringGrid1->Cells[j][i]);

			// If the current row is the first row, then we need to compare the cell width with the header width
			if (i == 0)
            {
                int headerWidth = StringGrid1->Canvas->TextWidth(StringGrid1->Columns[j]->Header);
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
	int totalAvailableWidth = 1120;

	// Calculate the total required width for all columns based on the maxWidths
	int totalRequiredWidth = 0;
	for (int maxWidth : maxWidths)
	{
		totalRequiredWidth += maxWidth;
	}

	// Calculate the remaining width that needs to be distributed among the columns
	int remainingWidth = totalAvailableWidth - totalRequiredWidth;

	// Adjust the width of each column based on the calculated maximum width and distribute the remaining width
	int extraWidthPerColumn = (remainingWidth-7) / StringGrid1->ColumnCount;

	for (int j = 0; j < StringGrid1->ColumnCount; ++j)
	{
		StringGrid1->Columns[j]->Width = maxWidths[j];

		// Distribute the remaining width among the columns evenly
		StringGrid1->Columns[j]->Width += extraWidthPerColumn;

		// Remainder Width
		StringGrid1->Columns[6]->Width += 3;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorUserAccountsForm::PopulateGridWithAdministrators(const std::vector<std::unique_ptr<User>>& administrators)
{
	// Set the row count based on the number of administrators
	StringGrid1->RowCount = administrators.size();

	// Add headers for the columns
	StringGrid1->Columns[0]->Header = "User ID";
	StringGrid1->Columns[1]->Header = "First Name";
	StringGrid1->Columns[2]->Header = "Last Name";
	StringGrid1->Columns[3]->Header = "Gender";
	StringGrid1->Columns[4]->Header = "Date of Birth";
	StringGrid1->Columns[5]->Header = "Phone Number";
	StringGrid1->Columns[6]->Header = "Blocked?";

	// Populate StrinGrid
	for (int i=0; i < administrators.size(); i++)
	{
		User* admin = administrators[i].get();

		StringGrid1->Cells[0][i] = admin->GetUserID().c_str();
		StringGrid1->Cells[1][i] = admin->GetFirstName().c_str();
		StringGrid1->Cells[2][i] = admin->GetLastName().c_str();
		StringGrid1->Cells[3][i] = admin->GetGender().c_str();
		StringGrid1->Cells[4][i] = admin->GetDateOfBirth().c_str();
		StringGrid1->Cells[5][i] = admin->GetPhoneNumber().c_str();
		StringGrid1->Cells[6][i] = admin->GetIsBlocked() ? "Blocked" : "Not Blocked";
	}
}

void __fastcall TAdministratorUserAccountsForm::FormCreate(TObject *Sender)
{
	PopulateGridWithAdministrators(School::GetInstance().GetAdministrators());
	AdjustColumnWidths();
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorUserAccountsForm::StringGrid1DrawColumnHeader(TObject *Sender,
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
	float paddingHorizontal = 3;
	float paddingVertical = 5;
    TRectF paddedBounds = TRectF(Bounds.Left + paddingHorizontal, Bounds.Top + paddingVertical, Bounds.Right - paddingHorizontal, Bounds.Bottom - paddingVertical);

    Canvas->FillText(paddedBounds, Column->Header, false, 1, fillTextFlags, TTextAlign::Leading, TTextAlign::Leading);

    Canvas->Font->Assign(oldFont); // Restore the old font settings
    Canvas->Fill->Assign(oldFill); // Restore the old fill settings

    delete oldFont;
    delete oldFill;
}

//---------------------------------------------------------------------------

