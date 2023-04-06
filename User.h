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
	User(UserType type, string lastname, string firstname, string email, string password, string phoneNumber, string dob, string question, string answer, string address){
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
          IsBlocked = false;
          IsLoggedIn = false;
	};

};







#endif