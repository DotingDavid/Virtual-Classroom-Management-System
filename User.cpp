//---------------------------------------------------------------------------

#pragma hdrstop

#include <vector>

#include "User.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::string User::generateID(UserType userType) {
	static int adminCounter = 0;
     static int instructorCounter = 0;
     static int studentCounter = 0;

     std::string id;

     switch (userType) {
         case UserType::Administrator:
             id = "ADM" + std::to_string(++adminCounter);
             break;
         case UserType::Instructor:
             id = "INS" + std::to_string(++instructorCounter);
             break;
         case UserType::Student:
             id = "STU" + std::to_string(++studentCounter);
             break;
         default:
             id = "UNKNOWN";
     }

     return id;
}

