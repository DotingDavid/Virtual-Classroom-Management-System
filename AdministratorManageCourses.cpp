//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
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

	AnsiString AnsiCourseEnabled = CourseEnabledEdit->Text;
	string CourseEnabled = AnsiCourseEnabled.c_str();
	if(CourseEnabled == "" || IsOnlyWhitespace(CourseEnabled))
		return;

	std::shared_ptr<Course> obj = std::make_shared<Course>(CourseID, CourseName, CourseDepartment,
	CourseInstructor, CourseSemester, CourseStartDate, CourseEndDate, StringToBool(CourseEnabled));

	School::GetInstance().AddCourse(std::move(obj));
	School::GetInstance().SaveCourses();

	//ClearCreateEdits();

	//PopulateGridWithStudents(School::GetInstance().GetStudents());
	//AdjustColumnWidths(StudentAccountsStringGrid);
}
//---------------------------------------------------------------------------



