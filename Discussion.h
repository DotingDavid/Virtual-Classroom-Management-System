//---------------------------------------------------------------------------

#ifndef DiscussionH
#define DiscussionH
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "Assignment.h"
using std::string;

class Discussion : public Assignment {
private:
     //std::vector<Discussion Post*> DiscussionPosts;    [Map, Pair, Student, Post]
public:
     Discussion(string courseID, string title, string description, string dueDate, double maxPoints, double weight, Course* course)
       : Assignment(courseID, title, description, dueDate, maxPoints, weight, course) {
       //Constructor Body
     }
     Discussion(string title, string description, string dueDate, double maxPoints, double weight, Course* course)
       : Assignment(title, description, dueDate, maxPoints, weight, course) {
       //Constructor Body
     }
};


#endif
