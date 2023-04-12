//---------------------------------------------------------------------------

#ifndef AdministratorHomeH
#define AdministratorHomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TAdministratorHomeForm : public TForm
{
__published:	// IDE-managed Components
	TLayout *Header;
	TRectangle *HeaderBackground;
	TImage *PopupProfileMenu;
	TRectangle *PopupProfileMenuBackground;
	TRectangle *LogoutPopupProfileMenuItemSelector;
	TRectangle *EditProfilePopupProfileMenuSelector;
	TImage *EditProfilePopupMenuItemIcon;
	TText *EditProfilePopupProfileMenuItem;
	TText *LogoutProfilePopupMenuItem;
	TImage *LogoutProfilePopupMenuItemIcon;
	TText *HeaderText;
	TImage *ProfileIcon;
	TLine *HorizontalRule;
	TImage *HeaderLogo;
	TLine *Line1;
	TImage *NotificationIcon;
	TImage *MessagesIcon;
	TRectangle *ProfileMenuIndicator;
	TText *ProfileMenuIndicatorText;
	TText *UserNameProfile;
	TRectangle *PopupProfileMenuSelector;
	TRectangle *NotificationsIndicator;
	TText *NotificationsIndicatorText;
	TRectangle *MessagesIndicator;
	TText *MessagesIndicatorText;
	TLayout *MenuBar;
	TRectangle *HomeMenuItemRect;
	TRectangle *StudentStatisticsMenuItemRect;
	TRectangle *ManageCoursesMenuItemRect;
	TRectangle *UserAccountsMenuItemRect;
	TText *HomeMenuItem;
	TImage *UserAccountsMenuItemIcon;
	TText *UserAccountsMenuItem;
	TText *ManageCourseMenuItem;
	TText *StudentStatisticsMenuItem;
	TImage *ManageCoursesMenuItemIcon;
	TImage *StudentStatisticsMenuItemIcon;
	TImage *HomeMenuItemIcon;
	TLayout *Footer;
	TRectangle *FooterBar;
	TLayout *RightMargin;
	TRectangle *FooterRight;
	TLayout *LeftMargin;
	TRectangle *FooterLeft;
	TLayout *TopMargin;
	void __fastcall HomeMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall HomeMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall HomeMenuItemRectClick(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall UserAccountsMenuItemRectClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall ManageCoursesMenuItemRectClick(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectMouseEnter(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectMouseLeave(TObject *Sender);
	void __fastcall StudentStatisticsMenuItemRectClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAdministratorHomeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdministratorHomeForm *AdministratorHomeForm;
//---------------------------------------------------------------------------
#endif
