#include "Graduate.h"

// Constructor:

// Creates a graduate student with the a unique key, the first name, and last
// name

Graduate::Graduate(int personCode, string personType, string fName,
                   string lName) {
  personCode_ = personCode;
  personType_ = personType;
  firstName_ = fName;
  lastName_ = lName;
}

// Destructor:
// Graduate::~Graduate() {}

// Person:

// Get the first name
string Graduate::getFirstName() { return firstName_; }

// Get the last name
string Graduate::getLastName() { return lastName_; }

// Get Student type
string Graduate::getPersonType() { return personType_; }

// Get Person Code
int Graduate::getPersonCode() { return personCode_; }

// Setters:

// Set the first name
void Graduate::setFirstName(string fName) { firstName_ = fName; }

// Set the Last name
void Graduate::setLastName(string lName) { lastName_ = lName; }

// Set the student type
void Graduate::setPersonType(string personType) { personType_ = personType; }

// Student:

// Getters:

// get the current courses vector
vector<I_Course*> Graduate::getCurrentCourses() { return currentCourses; }

// Get the student course history vector
vector<I_Course*> Graduate::getCourseHistory() { return pastCourses; }

// Functions:

// Prints out all the classes this student is taking
void Graduate::PrintCurrentCourses() {
  if (currentCourses.size() != 0) {
    cout << firstName_ << "'s "
         << "Current Courses : " << endl;
    for (int i = 0; i < currentCourses.size(); i++) {
      cout << "Course #" << i << ": " << currentCourses[i]->getCourseName()
           << endl;
    }
  }
}

// Prints out all the courses a student has taken
void Graduate::PrintPastCourses() {
  if (pastCourses.size() != 0) {
    cout << firstName_ << "'s "
         << "Past Courses: " << endl;
    for (int i = 0; i < pastCourses.size(); i++) {
      cout << "Course #" << i << ": " << pastCourses[i]->getCourseName()
           << endl;
    }
  }
}

// Adds the course to the current course vector and the past courses vector
bool Graduate::AddCourseToStudent(I_Course* c) {
  // Add a course to this student current courses
  currentCourses.push_back(c);

  // Add a course to this students course history
  pastCourses.push_back(c);

  return true;
}

// Removes a course from their current scheudle
bool Graduate::RemoveCurrentCourse(I_Course* c) {
  for (int i = 0; i < currentCourses.size(); i++) {
    // if the the current course is the same as the course that needs to be
    // deleted
    if (currentCourses[i] == c) {
      // Set the course ptr to null [NOTE: May have to delete
      // courseCourses[i]]
      currentCourses[i] = NULL;

      // remove the course from the vector
      currentCourses.erase(currentCourses.begin() + i);

      return true;
    }
  }

  return false;
}

// Returns whether the student is eligible to be a student (Is taking one
// course)
bool Graduate::StudentValidation() {
  // If the student is taking 0 courses than return false
  if (currentCourses.size() == 0) {
    return false;
  }

  // The student is taking 1 or more classes currently
  return true;
}

// pop back from from currentCourses
void Graduate::currentCoursesPopBack() { currentCourses.pop_back(); }

// pop back from from courseHistory
void Graduate::courseHistoryPopBack() { pastCourses.pop_back(); }

// Instructor:

// Gets the courses the instructor is teaching currently
vector<I_Course*> Graduate::getTeachingCurrentCourses() {
  return teachingCurrentCourses;
}

// Get the teaching history vector
vector<I_Course*> Graduate::getTeachingHistory() { return TeachedPastCourses; }
// Prints out all the classes this faculty is teaching
void Graduate::PrintTeachingCurretCourses() {
  cout << firstName_ << "'s "
       << "Currently Teaching:" << endl;
  for (int i = 0; i < teachingCurrentCourses.size(); i++) {
    cout << "Course Code: " << teachingCurrentCourses[i]->getCourseCode()
         << " Course Name: " << teachingCurrentCourses[i]->getCourseName()
         << endl;
  }
}

// Prints out all the classes this faculty has taught
void Graduate::PrintTeachingCoursesHistory() {
  cout << firstName_ << "'s "
       << "Teaching History: " << endl;
  for (int i = 0; i < TeachedPastCourses.size(); i++) {
    cout << "Course Code: " << TeachedPastCourses[i]->getCourseCode()
         << " Course Name: " << TeachedPastCourses[i]->getCourseName() << endl;
  }
}

// Add a course to the current courses teaching and history vector
bool Graduate::AddCoursetoInstructor(I_Course* c) {
  // Add a course to the instrucotors current teaching schedule
  teachingCurrentCourses.push_back(c);

  // Add a course to the instructors teaching history
  TeachedPastCourses.push_back(c);

  return true;
}

// Remove a course from a instructors current courses vector
bool Graduate::removeCurrentInstructorClass(I_Course* c) {
  for (int i = 0; i < teachingCurrentCourses.size(); i++) {
    // if the the current course is the same as the course that needs to be
    // deleted
    if (teachingCurrentCourses[i]->getCourseCode() == c->getCourseCode()) {
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
void Graduate::teachingCurrentCoursesPopBack() {
  teachingCurrentCourses.pop_back();
}

// pop back from from courseHistory
void Graduate::teachedPastCoursesPopBack() { TeachedPastCourses.pop_back(); }

// Graduate:

// Fucntions:

// check if the graduate student is not enrolled in the course they are trying
// to teach
bool Graduate::TeachingValidation(I_Course* c) {
  // Iterate through the current classes the graduate student is enrolled in
  for (int i = 0; i < teachingCurrentCourses.size(); i++) {
    // If the graduate student is not enrolled in the class they are trying to
    // teach return false
    if (teachingCurrentCourses[i] == c) {
      return false;
    }
  }

  // The graduate student is not enrolled in the class they are trying to teach
  // return true
  return true;
}

// check if a graduate is already teaching a class
bool Graduate::MaxTeachingGraduate() {
  // If the graduate student is teaching more than 1 class return false
  if (teachingCurrentCourses.size() >= 1) {
    return false;
  }

  // If the graduate student is only teaching one class
  return true;
}

// check if a course is inside the current courses vector
bool Graduate::containsCurrentCourse(I_Course* c) {
  int size = currentCourses.size();
  for (int i = 0; i < size; i++) {
    if (c->getCourseCode() == currentCourses[i]->getCourseCode()) {
      return true;
    }
  }
  return false;
}

// check if a course is inside the course history vector
bool Graduate::containsCourseHistory(I_Course* c) {
  int size = pastCourses.size();
  for (int i = 0; i < size; i++) {
    if (c->getCourseCode() == pastCourses[i]->getCourseCode()) {
      return true;
    }
  }
  return false;
}

// Swap currentCourses
bool Graduate::removeCurrentCourses(I_Course* c) {
  for (int i = 0; i < currentCourses.size(); i++) {
    if (c->getCourseCode() == currentCourses.at(i)->getCourseCode()) {
      currentCourses.at(i) = NULL;

      currentCourses.erase(currentCourses.begin() + i);
      return true;
    }
  }

  return false;
}

// Swap pastCourses
bool Graduate::removePastCourses(I_Course* c) {
  for (int i = 0; i < pastCourses.size(); i++) {
    if (c->getCourseCode() == pastCourses.at(i)->getCourseCode()) {
      pastCourses.at(i) = NULL;
      pastCourses.erase(pastCourses.begin() + i);
      return true;
    }
  }

  return false;
}

// Remove teachingCurrentCourse
bool Graduate::removeTeachingCurrentCourse(I_Course* c) {
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
bool Graduate::removeTeachedPastCourse(I_Course* c) {
  for (int i = 0; i < TeachedPastCourses.size(); i++) {
    if (c->getCourseCode() == TeachedPastCourses.at(i)->getCourseCode()) {
      TeachedPastCourses.at(i) = NULL;

      TeachedPastCourses.erase(TeachedPastCourses.begin() + i);
      return true;
    }
  }

  return false;
}