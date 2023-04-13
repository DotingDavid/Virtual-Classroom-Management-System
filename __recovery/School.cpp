//---------------------------------------------------------------------------

#pragma hdrstop

#include <fstream>
#include <string>
#include "School.h"
#include "User.h"
#include "Administrator.h"
#include "Instructor.h"
#include "Student.h"
#include "HelperFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using std::string;

School* School::Instance = nullptr; // Initialize the instance pointer

School& School::GetInstance() {
    if(Instance == nullptr) {
        Instance = new School("Horizon Middle School");
    }
    return *Instance;
}

void School::AddAdministrator(std::unique_ptr<User> admin) {
    Administrators.push_back(std::move(admin));
}

std::vector<std::unique_ptr<User>>& School::GetAdministrators() {
        return Administrators;
    }

void School::SaveUsers() {
    fstream AdminInfoFile;
    AdminInfoFile.open("AdminInfo.txt", ios::out);
    if(AdminInfoFile.is_open()) {

        for(auto& admin : Administrators) {
            admin->SaveUser(AdminInfoFile);
            AdminInfoFile << std::endl;
        }

        AdminInfoFile.close();
    }

    fstream InstructorInfoFile;
    InstructorInfoFile.open("InstructorInfo.txt", ios::out);
    if(InstructorInfoFile.is_open()) {

        for(auto& instructor : Instructors) {
            instructor->SaveUser(InstructorInfoFile);
            InstructorInfoFile << std::endl;
        }

        InstructorInfoFile.close();
    }

    fstream StudentInfoFile;
    StudentInfoFile.open("StudentInfo.txt", ios::out);
    if(StudentInfoFile.is_open()) {

        for(auto& student : Students) {
            student->SaveUser(StudentInfoFile);
            StudentInfoFile << std::endl;
        }

        StudentInfoFile.close();
    }
}

void School::LoadUsers() {
    fstream AdminInfoFile;
    AdminInfoFile.open("AdminInfo.txt", ios::in);
	if(AdminInfoFile.is_open()) {
		  string line;

			while(getline(AdminInfoFile, line)) {
               std::vector<string> ParsedLine = ParseCommaDelimitedString(line);

			   std::string UserID = ParsedLine[0];
			   std::string Email = ParsedLine[1];
			   std::string Password = ParsedLine[2];
			   std::string FirstName = ParsedLine[3];
			   std::string LastName = ParsedLine[4];
			   std::string Gender = ParsedLine[5];
			   std::string DateOfBirth = ParsedLine[6];
			   std::string PhoneNumber = ParsedLine[7];
			   std::string Address = ParsedLine[8];
			   std::string SecurityQuestion = ParsedLine[9];
			   std::string SecurityAnswer = ParsedLine[10];
			   std::string IsBlockedString = ParsedLine[11];
			   std::string JobTitle = ParsedLine[12];

               std::unique_ptr<User> obj = std::make_unique<Administrator>(UserID, Email, Password,
               FirstName, LastName, Gender, DateOfBirth, PhoneNumber, Address, SecurityQuestion,
               SecurityAnswer, StringToBool(IsBlockedString), JobTitle);

               Administrators.push_back(std::move(obj));
          }

          AdminInfoFile.close();
    }

    fstream InstructorInfoFile;
    InstructorInfoFile.open("InstructorInfo.txt", ios::in);
    if(InstructorInfoFile.is_open()) {
        std::string line;

        while(getline(InstructorInfoFile, line)) {
        	 std::vector<std::string> ParsedLine = ParseCommaDelimitedString(line);

           std::string UserID = ParsedLine[0];
           std::string Email = ParsedLine[1];
           std::string Password = ParsedLine[2];
           std::string FirstName = ParsedLine[3];
           std::string LastName = ParsedLine[4];
		   std::string Gender = ParsedLine[5];
           std::string DateOfBirth = ParsedLine[6];
           std::string PhoneNumber = ParsedLine[7];
           std::string Address = ParsedLine[8];
           std::string SecurityQuestion = ParsedLine[9];
           std::string SecurityAnswer = ParsedLine[10];
           std::string IsBlockedString = ParsedLine[11];

           std::unique_ptr<User> obj = std::make_unique<Instructor>(UserID, Email, Password,
           FirstName, LastName, Gender, DateOfBirth, PhoneNumber, Address, SecurityQuestion,
           SecurityAnswer, StringToBool(IsBlockedString));

           Instructors.push_back(std::move(obj));

        }
        InstructorInfoFile.close();
    }

    fstream StudentInfoFile;
    StudentInfoFile.open("StudentInfo.txt", ios::in);
    if(StudentInfoFile.is_open()) {
        std::string line;

        while(getline(StudentInfoFile, line)) {
		   std::vector<std::string> ParsedLine = ParseCommaDelimitedString(line);

           std::string UserID = ParsedLine[0];
           std::string Email = ParsedLine[1];
           std::string Password = ParsedLine[2];
           std::string FirstName = ParsedLine[3];
           std::string LastName = ParsedLine[4];
           std::string Gender = ParsedLine[5];
           std::string DateOfBirth = ParsedLine[6];
           std::string PhoneNumber = ParsedLine[7];
           std::string Address = ParsedLine[8];
           std::string SecurityQuestion = ParsedLine[9];
           std::string SecurityAnswer = ParsedLine[10];
           std::string IsBlockedString = ParsedLine[11];

           std::unique_ptr<User> obj = std::make_unique<Student>(UserID, Email, Password,
           FirstName, LastName, Gender, DateOfBirth, PhoneNumber, Address, SecurityQuestion,
           SecurityAnswer, StringToBool(IsBlockedString));

           Students.push_back(std::move(obj));

        }
        StudentInfoFile.close();
	}
}

std::string School::GetLoggedInUserID() {
	return LoggedInUserID;
}

std::string School::GetLoggedInUserName() {
	return LoggedInUserName;
}

void School::LoginUser(string userID, string userName) {
	LoggedInUserID = userID;
	LoggedInUserName = userName;
}

void School::LogoutUser() {

	if(LoggedInUserID.empty())
		return;

	for(auto& user : Administrators) {
		if(user->GetUserID() == LoggedInUserID) {
			user->Logout();
			LoggedInUserID = "";
			break;
		}
	}
	for(auto& user : Instructors) {
		if(user->GetUserID() == LoggedInUserID) {
			user->Logout();
			LoggedInUserID = "";
			break;
		}
	}
	for(auto& user : Students) {
		if(user->GetUserID() == LoggedInUserID) {
			user->Logout();
			LoggedInUserID = "";
			break;
		}
	}
}

