//---------------------------------------------------------------------------

#ifndef UserH
#define UserH
#include <iostream>
#include <string>
#include <memory>

using std::string;

//---------------------------------------------------------------------------
class User {
private:
     string LastName;
     string FirstName;
     string UserID;
     string Email;
     string Password;
     string PhoneNumber;
     string DateOfBirth;
     string SecurityQuestion;
     string SecurityAnswer;
     string Address;
     string Gender;
     bool IsBlocked;
     bool IsLoggedIn;
     //std::vector<Notification> Notifications;

protected:
    enum class UserType {
            Administrator,
            Instructor,
            Student
         };

     string generateID(UserType userType);

public:
	User(UserType type, string email, string password, string firstname, string lastname, string gender, string dob, string phoneNumber, string address, string question, string answer){
          UserID = generateID(type);
          LastName = lastname;
          FirstName = firstname;
          Email = email;
          Password = password;
          PhoneNumber = phoneNumber;
          DateOfBirth = dob;
          SecurityQuestion = question;
          SecurityAnswer = answer;
          Address = address;
          Gender = gender;
          IsBlocked = false;
          IsLoggedIn = false;
	};

     User(string userID, string email, string password, string firstname, string lastname, string gender, string dob, string phoneNumber, string address, string question, string answer, bool isBlocked){
          UserID = userID;
          LastName = lastname;
          FirstName = firstname;
          Email = email;
          Password = password;
          PhoneNumber = phoneNumber;
          DateOfBirth = dob;
          SecurityQuestion = question;
          SecurityAnswer = answer;
          Address = address;
          Gender = gender;
          IsBlocked = isBlocked;
          IsLoggedIn = false;
	};

     //User(userID, lastname, firstname, email, password, phoneNumber, dob, question, answer, address, isBlocked)

     string GetLastName();
     string GetFirstName();
     string GetUserID();
     string GetEmail();
     string GetPassword();
     string GetPhoneNumber();
     string GetDateOfBirth();
     string GetSecurityQuestion();
     string GetSecurityAnswer();
     string GetAddress();
     string GetGender();
     bool GetIsBlocked();
     bool GetIsLoggedIn();
     virtual void SaveUser(std::ostream& out);
};







#endif
