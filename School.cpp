//---------------------------------------------------------------------------

#pragma hdrstop
#include <System.SysUtils.hpp>
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

void School::RemoveUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToRemove) {
	for (auto it = userVector.begin(); it != userVector.end(); ++it) {
		if((*it)->GetUserID() == userToRemove.GetUserID()) {
			userVector.erase(it);
			break;
		}
	}
}

void School::BlockUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToBlock) {
	for (auto it = userVector.begin(); it != userVector.end(); ++it) {
		if((*it)->GetUserID() == userToBlock.GetUserID()) {
			(*it)->BlockUser();
			break;
		}
	}
}

void School::UnblockUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToBlock) {
	for (auto it = userVector.begin(); it != userVector.end(); ++it) {
		if((*it)->GetUserID() == userToBlock.GetUserID()) {
			(*it)->UnblockUser();
			break;
		}
	}
}

void School::AddAdministrator(std::shared_ptr<User> admin) {
	Administrators.push_back(std::move(admin));
}

std::vector<std::shared_ptr<User>>& School::GetAdministrators() {
		return Administrators;
}

void School::AddInstructor(std::shared_ptr<User> instructor) {
	Instructors.push_back(std::move(instructor));
}

std::vector<std::shared_ptr<User>>& School::GetInstructors() {
		return Instructors;
}

void School::AddStudent(std::shared_ptr<User> student) {
	Students.push_back(std::move(student));
}

std::vector<std::shared_ptr<User>>& School::GetStudents() {
		return Students;
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

			   std::shared_ptr<User> obj = std::make_shared<Administrator>(UserID, Email, Password,
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
		   std::string Department = ParsedLine[12];

           std::shared_ptr<User> obj = std::make_shared<Instructor>(UserID, Email, Password,
           FirstName, LastName, Gender, DateOfBirth, PhoneNumber, Address, SecurityQuestion,
           SecurityAnswer, StringToBool(IsBlockedString), Department);

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
		   std::string GPAString = ParsedLine[12];

		   std::shared_ptr<User> obj = std::make_shared<Student>(UserID, Email, Password,
           FirstName, LastName, Gender, DateOfBirth, PhoneNumber, Address, SecurityQuestion,
		   SecurityAnswer, StringToBool(IsBlockedString), StringToFloat(GPAString));

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

std::vector<User*> School::FilterUsersBySearchText(const std::vector<std::shared_ptr<User>>& users, const std::string& searchText) {
	std::vector<User*> filteredUsers;

	for (const auto& user : users) {
		if (user->HasAttributeSubstring(searchText)) {
			filteredUsers.push_back(user.get());
		}
	}

	return filteredUsers;
}
