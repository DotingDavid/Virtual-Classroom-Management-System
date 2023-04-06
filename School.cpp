//---------------------------------------------------------------------------

#pragma hdrstop

#include "School.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

School* School::instance = nullptr; // Initialize the instance pointer



void School::addAdministrator(std::unique_ptr<User> admin) {
    Administrators.push_back(std::move(admin));
}

School& School::getInstance() {
    if(instance == nullptr) {
        instance = new School("Horizon Middle School");
    }
    return *instance;
}