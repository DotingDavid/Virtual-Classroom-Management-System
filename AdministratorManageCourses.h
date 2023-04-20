//---------------------------------------------------------------------------

#ifndef AdministratorManageCoursesH
#define AdministratorManageCoursesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "AdministratorUIParent.h"
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <System.Rtti.hpp>
#include <FMX.ComboEdit.hpp>
//---------------------------------------------------------------------------
class TAdministratorManageCoursesForm : public TAdministratorUIParentForm
{
__published:	// IDE-managed Components
	TLayout *Content;
	TImage *UserTypeSelectionContainer;
	TRectangle *UserTypeSelector;
	TText *UserTypeSelectionText;
	TRectangle *BlockUserStringGridOptionSelector;
	TImage *BlockUserStringGridOption;
	TRectangle *RemoveUserStringGridOptionSelector;
	TImage *RemoveUserStringGridOption;
	TRectangle *EditUserStringGridOptionSelector;
	TImage *EditUserStringGridOption;
	TLayout *SearchBarLayout;
	TRectangle *SearchIconRectangle;
	TImage *SearchIcon;
	TEdit *SearchBarEdit;
	TVertScrollBox *UserAccountsScrollBox;
	TStringGrid *AdministratorCoursesStringGrid;
	TStringColumn *CourseID;
	TStringColumn *CourseDepartment;
	TStringColumn *CourseName;
	TStringColumn *CourseInstructor;
	TStringColumn *CourseStartDate;
	TStringColumn *CourseEndDate;
	TStringColumn *CourseEnabled;
	TImage *UserTypePopupMenu;
	TRectangle *UserTypePopupMenuBackground;
	TRectangle *AdministratorSelector;
	TText *AdministratorUserType;
	TLayout *CreateNewSection;
	TText *CreateNewCourseText;
	TLine *VerticleDivider;
	TButton *CreateCourseButton;
	TLayout *EmailLayout;
	TLabel *InstructorLabel;
	TLayout *FirstNameLayout;
	TLabel *CourseNameLabel;
	TEdit *CourseNameEdit;
	TLayout *PasswordLayout;
	TLabel *PasswordLabel;
	TEdit *PasswordEdit;
	TLayout *LastNameLayout;
	TLabel *CourseDepartmentLabel;
	TEdit *CourseDepartmentEdit;
	TLayout *BirthdateLayout;
	TLabel *BirthdateLabel;
	TEdit *BirthdateEdit;
	TLayout *SecurityAnswerLayout;
	TLabel *SecurityAnswerLabel;
	TEdit *SecurityAnswerEdit;
	TLayout *SecurityQuestionLayout;
	TLabel *SecurityQuestionLabel;
	TEdit *SecurityQuestionEdit;
	TLayout *GenderLayout;
	TLabel *GenderLabel;
	TEdit *GenderEdit;
	TLayout *AddressLayout;
	TLabel *AddressLabel;
	TEdit *AddressEdit;
	TLayout *PhoneNumberLayout;
	TLabel *PhoneNumberLabel;
	TEdit *PhoneNumberEdit;
	TLayout *BottomEditLayout;
	TLayout *DepartmentLayout;
	TEdit *DepartmentEdit;
	TLabel *DepartmentLabel;
	TLayout *JobTitleLayout;
	TEdit *JobTitleEdit;
	TLabel *JobTitleLabel;
	TStringColumn *CourseSemester;
	TComboEdit *CourseInstructorDropDownEdit;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CourseInstructorDropDownEditExit(TObject *Sender);
private:	// User declarations
    TStringList *InstructorNames;
public:		// User declarations
	__fastcall TAdministratorManageCoursesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdministratorManageCoursesForm *AdministratorManageCoursesForm;
//---------------------------------------------------------------------------
#endif
