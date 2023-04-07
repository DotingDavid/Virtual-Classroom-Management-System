//---------------------------------------------------------------------------

#pragma hdrstop

#include <fstream>
#include <string>
#include "School.h"
#include "User.h"
#include "Administrator.h"
#include "HelperFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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
    		std::string line;

    		while(getline(AdminInfoFile, line)) {
               std::vector<std::string> ParsedLine = ParseCommaDelimitedString(line);

               std::string UserID = ParsedLine[0];
               std::string Email = ParsedLine[1];
               std::string Password = ParsedLine[2];
               std::string FirstName = ParsedLine[3];
               std::string LastName = ParsedLine[4];
               std::string DateOfBirth = ParsedLine[5];
               std::string PhoneNumber = ParsedLine[6];
               std::string Address = ParsedLine[7];
               std::string SecurityQuestion = ParsedLine[8];
               std::string SecurityAnswer = ParsedLine[9];
               std::string IsBlockedString = ParsedLine[10];
               std::string JobTitle = ParsedLine[11];

               bool IsBlocked;
               if(IsBlockedString == "0") {
                   IsBlocked = false;
               } else {
                   IsBlocked = true;
               }

               std::unique_ptr<User> obj = std::make_unique<Administrator>(UserID, LastName,
     		FirstName, Email, Password, PhoneNumber, DateOfBirth, SecurityQuestion,
               SecurityAnswer, Address, IsBlocked, JobTitle);

               Administrators.push_back(std::move(obj));
          }

          AdminInfoFile.close();
    }
}

