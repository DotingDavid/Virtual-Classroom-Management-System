//---------------------------------------------------------------------------

#ifndef AdministratorUserAccountsH
#define AdministratorUserAccountsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TAdministratorUserAccountsForm : public TForm
{
__published:	// IDE-managed Components
	TRectangle *FooterBar;
	TText *HeaderText;
	TLayout *Header;
	TLayout *MenuBar;
	TLayout *Footer;
	TText *HomeMenuItem;
	TImage *UserAccountsMenuItemIcon;
	TText *UserAccountsMenuItem;
	TRectangle *HomeMenuItemRect;
	TRectangle *UserAccountsMenuItemRect;
	TImage *ManageCoursesMenuItemIcon;
	TText *ManageCourseMenuItem;
	TRectangle *ManageCoursesMenuItemRect;
	TText *StudentStatisticsMenuItem;
	TImage *StudentStatisticsMenuItemIcon;
	TRectangle *StudentStatisticsMenuItemRect;
	TLayout *RightMargin;
	TLayout *LeftMargin;
	TImage *ProfileIcon;
	TRectangle *FooterLeft;
	TRectangle *FooterRight;
	TLine *HorizontalRule;
	TLayout *TopMargin;
	TImage *HeaderLogo;
	TLine *Line1;
	TImage *MessagesIcon;
	TImage *HomeMenuItemIcon;
	TImage *NotificationIcon;
	TImage *PopupProfileMenu;
	TRectangle *PopupProfileMenuBackground;
	TImage *EditProfilePopupMenuItemIcon;
	TText *LogoutProfilePopupMenuItem;
	TText *EditProfilePopupProfileMenuItem;
	TImage *LogoutProfilePopupMenuItemIcon;
	TRectangle *ProfileMenuIndicator;
	TText *ProfileMenuIndicatorText;
	TRectangle *EditProfilePopupProfileMenuSelector;
	TRectangle *LogoutPopupProfileMenuItemSelector;
	TText *UserNameProfile;
	TRectangle *PopupProfileMenuSelector;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HomeMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall HomeMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall HomeMenuItemRectClick(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectClick(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectClick(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectClick(TObject *Sender);
	void __fastcall PopupProfileMenuSelectorClick(TObject *Sender);
	void __fastcall PopupProfileMenuSelectorMouseEnter(TObject *Sender);
	void __fastcall PopupProfileMenuSelectorMouseLeave(TObject *Sender);
	void __fastcall LogoutPopupProfileMenuItemSelectorClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAdministratorUserAccountsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdministratorUserAccountsForm *AdministratorUserAccountsForm;
//---------------------------------------------------------------------------
#endif
