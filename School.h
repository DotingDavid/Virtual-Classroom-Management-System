//---------------------------------------------------------------------------

#ifndef SchoolH
#define SchoolH

#include <vector>
#include <memory>
#include "User.h"
#include "Administrator.h"
//#include "Course.h"

using std::string;
//---------------------------------------------------------------------------
class School {
private:
	 string LoggedInUserID;
	 string LoggedInUserName;
	 string SchoolName;
	 std::vector<std::shared_ptr<User>> Administrators;
	 std::vector<std::shared_ptr<User>> Instructors;
	 std::vector<std::shared_ptr<User>> Students;
	 //std::vector<std::shared_ptr<Course>> Courses;
     static School* Instance;

	 School(string name) {
          SchoolName = name;
     };
public:
	 static School& GetInstance();

	 void RemoveUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToRemove);
	 void BlockUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToBlock);
	 void UnblockUser(std::vector<std::shared_ptr<User>>& userVector,  User& userToBlock);

	 void AddAdministrator(std::shared_ptr<User> admin);
	 std::vector<std::shared_ptr<User>>& GetAdministrators();

	 void AddInstructor(std::shared_ptr<User> instructor);
	 std::vector<std::shared_ptr<User>>& GetInstructors();

	 void AddStudent(std::shared_ptr<User> student);
	 std::vector<std::shared_ptr<User>>& GetStudents();

     void SaveUsers();
     void LoadUsers();

	School(const School&) = delete;
	 School& operator=(const School&) = delete;

	 string GetLoggedInUserID();
     string GetLoggedInUserName();
	 void LoginUser(string userID, string userName);
	 void LogoutUser();
	 std::vector<User*> FilterUsersBySearchText(const std::vector<std::shared_ptr<User>>& users, const std::string& searchText);
};


#endif
