//---------------------------------------------------------------------------

#ifndef AdministratorH
#define AdministratorH
#include "User.h"
//---------------------------------------------------------------------------

#include <iostream>
#include <string>

using std::string;

class Administrator : public User {
private:
     string JobTitle;
public:
     Administrator(string userID, string lastname, string firstname, string email, string password, string phoneNumber, string dob, string question, string answer, string address, bool isBlocked, string jobTitle)
       : User(userID, lastname, firstname, email, password, phoneNumber, dob, question, answer, address, isBlocked), JobTitle(jobTitle){
          //Constructor Body
     }

     Administrator(string lastname, string firstname, string email, string password, string phoneNumber, string dob, string question, string answer, string address, string jobTitle)
       : User(UserType::Administrator, lastname, firstname, email, password, phoneNumber, dob, question, answer, address), JobTitle(jobTitle){
          //Constructor Body
     }

     string GetJobTitle();

     void SaveUser(std::ostream& out);
};




#endif
