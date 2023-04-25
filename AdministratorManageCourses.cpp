//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <algorithm>
#pragma hdrstop

#include "AdministratorManageCourses.h"
#include "User.h"
#include "School.h"
#include "Instructor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdministratorUIParent"
#pragma resource "*.fmx"

TAdministratorManageCoursesForm *AdministratorManageCoursesForm;
//---------------------------------------------------------------------------
__fastcall TAdministratorManageCoursesForm::TAdministratorManageCoursesForm(TComponent* Owner)
	: TAdministratorUIParentForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::FormCreate(TObject *Sender)
{
	Left = 0;
	Top = 0;
	Width = ((Screen->Width)-50);
	Height = ((Screen->Height)-50);

	TShadowEffect *PopupProfileMenuShadow = new TShadowEffect(this);
	PopupProfileMenuShadow->Parent = PopupProfileMenuBackground;
	PopupProfileMenuShadow->Enabled = true;
	PopupProfileMenuShadow->Softness = 0.6f;  // A higher value creates a softer shadow
	PopupProfileMenuShadow->Distance = 2.0f;  // A lower value creates a shorter shadow
	PopupProfileMenuShadow->Direction = 90.0f; // Set the direction to 90 degrees (downwards)
	PopupProfileMenuShadow->ShadowColor = claBlack;
	PopupProfileMenuShadow->Opacity = 0.25f;
	PopupProfileMenuShadow->SendToBack();

	PopulateGridWithCourses(School::GetInstance().GetCourses());
	AdjustColumnWidths(AdministratorCoursesStringGrid);


	std::vector<std::shared_ptr<User>> Instructors = School::GetInstance().GetInstructors();
	InstructorNames = new TStringList;


	// Populate the TStringList with the instructor names
	for (int i = 0; i < Instructors.size(); i++) {
		InstructorNames->Add(Instructors[i]->GetFullName().c_str());
	}

	// Set the TStringList as the TComboBox's Items property
	CourseInstructorEdit->Items->Assign(InstructorNames);

	delete InstructorNames;
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorManageCoursesForm::ClearGridCells(Fmx::Grid::TStringGrid* stringGrid)
{
	if (stringGrid == nullptr)
		return;

	// Temporarily disable visual updates
	stringGrid->BeginUpdate();

	// Iterate through all cells in the TStringGrid
	for (int row = 0; row < stringGrid->RowCount; ++row)
	{
		for (int col = 0; col < stringGrid->ColumnCount; ++col)
		{
			// Remove the text from the current cell
			stringGrid->Cells[col][row] = "";
		}
	}

	// Re-enable visual updates and apply changes
	stringGrid->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorManageCoursesForm::PopulateGridWithCourses(const std::vector<std::shared_ptr<Course>>& courses)
{
	// Clear Previous Grid Info
	ClearGridCells(AdministratorCoursesStringGrid);

	// Set the row count based on the number of courses
	AdministratorCoursesStringGrid->RowCount = courses.size();

	// Add headers for the columns
	AdministratorCoursesStringGrid->Columns[0]->Header = "Course ID";
	AdministratorCoursesStringGrid->Columns[1]->Header = "Course Name";
	AdministratorCoursesStringGrid->Columns[2]->Header = "Department";
	AdministratorCoursesStringGrid->Columns[3]->Header = "Instructor";
	AdministratorCoursesStringGrid->Columns[4]->Header = "Semester";
	AdministratorCoursesStringGrid->Columns[5]->Header = "Start Date";
	AdministratorCoursesStringGrid->Columns[6]->Header = "End Date";
	AdministratorCoursesStringGrid->Columns[7]->Header = "Disabled?";

	// Populate StrinGrid
	for (int i=0; i < courses.size(); i++)
	{
		Course* course = courses[i].get();

		if (course)
		{
			AdministratorCoursesStringGrid->Cells[0][i] = course->GetCourseID().c_str();
			AdministratorCoursesStringGrid->Cells[1][i] = course->GetCourseName().c_str();
			AdministratorCoursesStringGrid->Cells[2][i] = course->GetCourseDepartment().c_str();
			AdministratorCoursesStringGrid->Cells[3][i] = course->GetCourseInstructorString().c_str();
			AdministratorCoursesStringGrid->Cells[4][i] = course->GetCourseSemester().c_str();
			AdministratorCoursesStringGrid->Cells[5][i] = course->GetCourseStartDate().c_str();
			AdministratorCoursesStringGrid->Cells[6][i] = course->GetCourseEndDate().c_str();
			AdministratorCoursesStringGrid->Cells[7][i] = course->GetIsCourseDisabled() ? "Disabled" : "Enabled";
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TAdministratorManageCoursesForm::AdjustColumnWidths(TStringGrid *StringGrid)
{
	// Initialize a vector to store the maximum width for each column
	std::vector<int> maxWidths(StringGrid->ColumnCount, 0);

    // Iterate over all cells in the TStringGrid
	for (int i = 0; i < StringGrid->RowCount; ++i)
    {
		for (int j = 0; j < StringGrid->ColumnCount; ++j)
        {
            // Calculate the width of the current cell or header
			int cellWidth = StringGrid->Canvas->TextWidth(StringGrid->Cells[j][i]);

            // If the current row is the first row, then we need to compare the cell width with the header width
            if (i == 0)
            {
				int headerWidth = StringGrid->Canvas->TextWidth(StringGrid->Columns[j]->Header);
                cellWidth = std::max(cellWidth, headerWidth);
            }

            // Update the maximum width for the current column, if needed
            if (cellWidth > maxWidths[j])
            {
                maxWidths[j] = cellWidth;
            }
        }
    }

    // Set the total available width, subtracting a constant value to account for any padding, margins, or scrollbars
	int totalAvailableWidth = StringGrid->Width - 8; // Adjust this value as needed

	//if vert scroll bar visible
	if(StringGrid->RowCount >= 28)
		totalAvailableWidth -= 14;


	// Calculate the total required width for all columns based on the maxWidths
	int totalRequiredWidth = 0;
	for (int maxWidth : maxWidths)
	{
		totalRequiredWidth += maxWidth;
	}

	// Calculate the remaining width that needs to be distributed among the columns
	int remainingWidth = totalAvailableWidth - totalRequiredWidth;

	// Adjust the width of each column based on the calculated maximum width and distribute the remaining width evenly
	int extraWidthPerColumn = remainingWidth / StringGrid->ColumnCount;
    // int remainingExtraWidth = remainingWidth % AccountsStringGrid->ColumnCount;

	for (int j = 0; j < StringGrid->ColumnCount; ++j)
	{
		StringGrid->Columns[j]->Width = maxWidths[j] + extraWidthPerColumn;

		/* Distribute the remaining extra width among the first few columns
		if (remainingExtraWidth > 0)
		{
			AccountsStringGrid->Columns[j]->Width += 1;
			remainingExtraWidth -= 1;
		}  */
	}
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::CourseInstructorEditExit(TObject *Sender)

{
	bool Valid = false;
	for(auto& Instructor : School::GetInstance().GetInstructors()) {
		if(CourseInstructorEdit->Text == Instructor->GetFullName().c_str()) {
			Valid = true;
			break;
		}
	}
	if(Valid == false) {
		CourseInstructorEdit->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::CreateCourseButtonClick(TObject *Sender)

{
	AnsiString AnsiCourseID = CourseIDEdit->Text;
	string CourseID = AnsiCourseID.c_str();
	if(CourseID == "" || IsOnlyWhitespace(CourseID))
		return;

	AnsiString AnsiCourseName = CourseNameEdit->Text;
	string CourseName = AnsiCourseName.c_str();
	if(CourseName == "" || IsOnlyWhitespace(CourseName))
		return;

	AnsiString AnsiCourseDepartment = CourseDepartmentEdit->Text;
	string CourseDepartment = AnsiCourseDepartment.c_str();
	if(CourseDepartment == "" || IsOnlyWhitespace(CourseDepartment))
		return;

	AnsiString AnsiCourseInstructor = CourseInstructorEdit->Text;
	string CourseInstructor = AnsiCourseInstructor.c_str();
	if(CourseInstructor == "" || IsOnlyWhitespace(CourseInstructor))
		return;

	AnsiString AnsiCourseSemester = CourseSemesterEdit->Text;
	string CourseSemester = AnsiCourseSemester.c_str();
	if(CourseSemester == "" || IsOnlyWhitespace(CourseSemester))
		return;

	AnsiString AnsiCourseStartDate = CourseStartDateEdit->Text;
	string CourseStartDate = AnsiCourseStartDate.c_str();
	if(CourseStartDate == "" || IsOnlyWhitespace(CourseStartDate))
		return;

	AnsiString AnsiCourseEndDate = CourseEndDateEdit->Text;
	string CourseEndDate = AnsiCourseEndDate.c_str();
	if(CourseEndDate == "" || IsOnlyWhitespace(CourseEndDate))
		return;

	AnsiString AnsiCourseDisabled = CourseDisabledEdit->Text;
	string CourseDisabled = AnsiCourseDisabled.c_str();
	if(CourseDisabled == "" || IsOnlyWhitespace(CourseDisabled))
		return;

	std::shared_ptr<Course> obj = std::make_shared<Course>(CourseID, CourseName, CourseDepartment,
	CourseInstructor, CourseSemester, CourseStartDate, CourseEndDate, StringToBool(CourseDisabled));

	School::GetInstance().AddCourse(std::move(obj));
	School::GetInstance().SaveCourses();

	CourseIDEdit->Text = "";
	CourseNameEdit->Text = "";
	CourseDepartmentEdit->Text = "";
	CourseInstructorEdit->Text = "";
	CourseSemesterEdit->Text = "";
	CourseStartDateEdit->Text = "";
	CourseEndDateEdit->Text = "";
	CourseDisabledEdit->Text = "";

	PopulateGridWithCourses(School::GetInstance().GetCourses());
	AdjustColumnWidths(AdministratorCoursesStringGrid);
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::AdministratorCoursesStringGridDrawColumnHeader(TObject *Sender,
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

	Canvas->FillText(paddedBounds, Column->Header, false, 1, fillTextFlags, TTextAlign::Leading);

	Canvas->Font->Assign(oldFont); // Restore the old font settings
	Canvas->Fill->Assign(oldFill); // Restore the old fill settings

	delete oldFont;
	delete oldFill;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DeleteCourseStringGridSelectorMouseEnter(TObject *Sender)

{
	DeleteCourseStringGridSelector->Fill->Kind = TBrushKind::Solid;
	DeleteCourseStringGridSelector->Fill->Color =  0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DeleteCourseStringGridSelectorMouseLeave(TObject *Sender)

{
	DeleteCourseStringGridSelector->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DeleteCourseStringGridSelectorClick(TObject *Sender)

{
    //Delete Course Function
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DisableCourseStringGridSelectorMouseEnter(TObject *Sender)

{
	DisableCourseStringGridSelector->Fill->Kind = TBrushKind::Solid;
	DisableCourseStringGridSelector->Fill->Color =  0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DisableCourseStringGridSelectorMouseLeave(TObject *Sender)

{
	DisableCourseStringGridSelector->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::DisableCourseStringGridSelectorClick(TObject *Sender)

{
    //Disable Course Function
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::ModifyCourseStringGridSelectorMouseEnter(TObject *Sender)

{
	ModifyCourseStringGridSelector->Fill->Kind = TBrushKind::Solid;
	ModifyCourseStringGridSelector->Fill->Color =  0xFFDFE9F1;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::ModifyCourseStringGridSelectorMouseLeave(TObject *Sender)

{
	ModifyCourseStringGridSelector->Fill->Kind = TBrushKind::None;
}
//---------------------------------------------------------------------------

void __fastcall TAdministratorManageCoursesForm::ModifyCourseStringGridSelectorClick(TObject *Sender)

{
    //Modify Course Function
}
//---------------------------------------------------------------------------

