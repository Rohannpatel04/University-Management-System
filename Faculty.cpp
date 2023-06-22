
#include "Faculty.h"

// Creates a faculty member
Faculty::Faculty(int personCode, string personType, string fName,
                 string lName) {
  personCode_ = personCode;
  personType_ = personType;
  firstName_ = fName;
  lastName_ = lName;
}

// Destructor:

// Person:

// Get the first name
string Faculty::getFirstName() { return firstName_; }

// Get the last name
string Faculty::getLastName() { return lastName_; }

// Get Student type
string Faculty::getPersonType() { return personType_; }

// Get Person Code
int Faculty::getPersonCode() { return personCode_; }

// Setters:

// Set the first name
void Faculty::setFirstName(string fName) { firstName_ = fName; }

// Set the Last name
void Faculty::setLastName(string lName) { lastName_ = lName; }

// Set the student type
void Faculty::setPersonType(string personType) { personType_ = personType; }

// Instructor:

// Getters:

// Gets the courses the instructor is teaching currently
vector<I_Course*> Faculty::getTeachingCurrentCourses() {
  return teachingCurrentCourses;
}

// Get the teaching history vector
vector<I_Course*> Faculty::getTeachingHistory() { return TeachedPastCourses; }

// Functions:

// Prints out all the classes this faculty is teaching
void Faculty::PrintTeachingCurretCourses() {
  if (teachingCurrentCourses.size() != 0) {
    cout << firstName_ << "'s "
         << "Currently Teaching: " << endl;
    for (int i = 0; i < teachingCurrentCourses.size(); i++) {
      cout << "Course Code: " << teachingCurrentCourses[i]->getCourseCode()
           << " Course Name: " << teachingCurrentCourses[i]->getCourseName()
           << endl;
    }
  }
}

// Prints out all the classes this faculty has taught
void Faculty::PrintTeachingCoursesHistory() {
  if (TeachedPastCourses.size() != 0) {
    cout << firstName_ << "'s "
         << "Teaching History: " << endl;
    for (int i = 0; i < TeachedPastCourses.size(); i++) {
      cout << "Course Code: " << TeachedPastCourses[i]->getCourseCode()
           << " Course Name: " << TeachedPastCourses[i]->getCourseName()
           << endl;
    }
  }
}

// Add a course to the current courses teaching and history vector
bool Faculty::AddCoursetoInstructor(I_Course* c) {
  // Add a course to the instrucotors current teaching schedule
  teachingCurrentCourses.push_back(c);

  // Add a course to the instructors teaching history
  TeachedPastCourses.push_back(c);

  return true;
}

// Remove a course from a instructors current courses vector
bool Faculty::removeCurrentInstructorClass(I_Course* c) {
  for (int i = 0; i < teachingCurrentCourses.size(); i++) {
    // if the the current course is the same as the course that needs to be
    // deleted
    if (teachingCurrentCourses[i] == c) {
      // Set the course ptr to null [NOTE: May have to delete
      // teachingCurrentCourses[i]]
      teachingCurrentCourses[i] = NULL;

      // remove the course from the vector
      teachingCurrentCourses.erase(teachingCurrentCourses.begin() + i);

      return true;
    }
  }

  return false;
}

// pop back from from currentCourses
void Faculty::teachingCurrentCoursesPopBack() {
  teachingCurrentCourses.pop_back();
}

// pop back from from courseHistory
void Faculty::teachedPastCoursesPopBack() { TeachedPastCourses.pop_back(); }

// Faculty:

// Check if the faculty member can teach a course (no more than 3)
bool Faculty::MaxTeachingFaculty() {
  // If the instructor  is teaching more than 3 classes return false
  if (teachingCurrentCourses.size() >= 3) {
    return false;
  }

  // If the instructor is teaching less than 3 classes
  return true;
}

bool Faculty::removeTeachingCurrentCourse(I_Course* c) {
  for (int i = 0; i < teachingCurrentCourses.size(); i++) {
    if (c->getCourseCode() == teachingCurrentCourses.at(i)->getCourseCode()) {
      teachingCurrentCourses.at(i) = NULL;

      teachingCurrentCourses.erase(teachingCurrentCourses.begin() + i);
      return true;
    }
  }

  return false;
}

// Remove trachingPastCourse
bool Faculty::removeTeachedPastCourse(I_Course* c) {
  for (int i = 0; i < TeachedPastCourses.size(); i++) {
    if (c->getCourseCode() == TeachedPastCourses.at(i)->getCourseCode()) {
      TeachedPastCourses.at(i) = NULL;

      TeachedPastCourses.erase(TeachedPastCourses.begin() + i);
      return true;
    }
  }

  return false;
}