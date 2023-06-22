#include "Undergraduate.h"

// Constructor:

// Creates a graduate student with the a unique key, the first name, and last
// name
Undergraduate::Undergraduate(int personCode, string personType, string fName,
                             string lName) {
  personCode_ = personCode;
  personType_ = personType;
  firstName_ = fName;
  lastName_ = lName;
}

// Destructor:
// Undergraduate::~Undergraduate() { cout << "U D" << endl; }

// Person:

// Get the first name
string Undergraduate::getFirstName() { return firstName_; }

// Get the last name
string Undergraduate::getLastName() { return lastName_; }

// Get Student type
string Undergraduate::getPersonType() { return personType_; }

// Get Person Code
int Undergraduate::getPersonCode() { return personCode_; }

// Setters:

// Set the first name
void Undergraduate::setFirstName(string fName) {}

// Set the Last name
void Undergraduate::setLastName(string lName) { lastName_ = lName; }

// Set the student type
void Undergraduate::setPersonType(string personType) {
  personType_ = personType;
}

// Student:

// Getters:

// get current course vector
vector<I_Course*> Undergraduate::getCurrentCourses() { return currentCourses; }

// Get the student course history vector
vector<I_Course*> Undergraduate::getCourseHistory() { return pastCourses; }

// Functions:

// Prints out all the classes this student is taking
void Undergraduate::PrintCurrentCourses() {
  cout << "Current Courses : " << endl;
  for (int i = 0; i < currentCourses.size(); i++) {
    cout << "Course #" << i << ": " << currentCourses[i]->getCourseName()
         << endl;
  }
}

// Prints out all the courses a student has taken
void Undergraduate::PrintPastCourses() {
  cout << "Past Courses: " << endl;
  for (int i = 0; i < pastCourses.size(); i++) {
    cout << "Course #" << i << ": " << pastCourses[i]->getCourseName() << endl;
  }
}
// Adds the course to the current course vector and the past courses vector
bool Undergraduate::AddCourseToStudent(I_Course* c) {
  // Add a course to this student current courses
  currentCourses.push_back(c);

  // Add a course to this students course history
  pastCourses.push_back(c);

  return true;
}

// Removes a course from their current scheudle
bool Undergraduate::RemoveCurrentCourse(I_Course* c) {
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
bool Undergraduate::StudentValidation() {
  // If the student is taking 0 courses than return false
  if (currentCourses.size() == 0) {
    return false;
  }

  // The student is taking 1 or more classes currently
  return true;
}

// pop back from from currentCourses
void Undergraduate::currentCoursesPopBack() { currentCourses.pop_back(); }

// pop back from from courseHistory
void Undergraduate::courseHistoryPopBack() { pastCourses.pop_back(); }

// check if a course is inside the current courses vector
bool Undergraduate::containsCurrentCourse(I_Course* c) {
  int size = currentCourses.size();
  for (int i = 0; i < size; i++) {
    if (c->getCourseCode() == currentCourses[i]->getCourseCode()) {
      return true;
    }
  }
  return false;
}

// check if a course is inside the course history vector
bool Undergraduate::containsCourseHistory(I_Course* c) {
  int size = pastCourses.size();
  for (int i = 0; i < size; i++) {
    if (c->getCourseCode() == pastCourses[i]->getCourseCode()) {
      return true;
    }
  }
  return false;
}

// Swap currentCourses
bool Undergraduate::removeCurrentCourses(I_Course* c) {
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
bool Undergraduate::removePastCourses(I_Course* c) {
  for (int i = 0; i < pastCourses.size(); i++) {
    if (c->getCourseCode() == pastCourses.at(i)->getCourseCode()) {
      pastCourses.at(i) = NULL;

      pastCourses.erase(pastCourses.begin() + i);

      return true;
    }
  }

  return false;
}