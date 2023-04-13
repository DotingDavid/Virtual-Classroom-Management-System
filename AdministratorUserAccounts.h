//---------------------------------------------------------------------------

#ifndef AdministratorUserAccountsH
#define AdministratorUserAccountsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "AdministratorUIParent.h"
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
#include <vector>

#include "User.h"
//---------------------------------------------------------------------------
class TAdministratorUserAccountsForm : public TAdministratorUIParentForm
{
__published:	// IDE-managed Components
	TVertScrollBox *UserAccountsScrollBox;
	TStringGrid *StringGrid1;
	TStringColumn *StringColumn1;
	TStringColumn *StringColumn2;
	TStringColumn *StringColumn3;
	TStringColumn *StringColumn4;
	TStringColumn *StringColumn5;
	TStringColumn *StringColumn6;
	TStringColumn *StringColumn7;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGrid1DrawColumnHeader(TObject *Sender, TCanvas * const Canvas,
          TColumn * const Column, const TRectF &Bounds);
private:	// User declarations
public:		// User declarations
	__fastcall TAdministratorUserAccountsForm(TComponent* Owner);
	void __fastcall PopulateGridWithAdministrators(const std::vector<std::unique_ptr<User>>& administrators);
    void __fastcall TAdministratorUserAccountsForm::AdjustColumnWidths();
};
//---------------------------------------------------------------------------
extern PACKAGE TAdministratorUserAccountsForm *AdministratorUserAccountsForm;
//---------------------------------------------------------------------------
#endif
