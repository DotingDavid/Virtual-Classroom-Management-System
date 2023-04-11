//---------------------------------------------------------------------------

#ifndef VirtualClassroomLoginH
#define VirtualClassroomLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TLoginForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *UsernameEdit;
	TLabel *UsernameLabel;
	TEdit *PasswordEdit;
	TLabel *PasswordLabel;
	TButton *LoginButton;
	TImage *HeaderImage;
	TLayout *Layout;
	void __fastcall LoginButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif
