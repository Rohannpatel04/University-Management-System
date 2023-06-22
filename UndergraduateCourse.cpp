#include "UndergraduateCourse.h"

#include <string>
// Course:

// Constructor:
// Creates a undergraduate course
UndergraduateCourse::UndergraduateCourse(string courseType, int courseCode,
                                         string courseName) {
  courseType_ = courseType;
  courseCode_ = courseCode;
  courseName_ = courseName;
}

// Destructor:
UndergraduateCourse::~UndergraduateCourse() {}

// Getters:

// Get the courses code
int UndergraduateCourse::getCourseCode() { return courseCode_; }

// Get Course type
string UndergraduateCourse::getCourseType() { return courseType_; }

// Get Students vector
vector<I_Student*> UndergraduateCourse::getStudents() { return courseStudents; }

// Get Instructor vector
vector<I_Instructor*> UndergraduateCourse::getInstructor() {
  return courseInstructor;
}

// Get Course Name
string UndergraduateCourse::getCourseName() { return courseName_; }

// Setters:

// Sets the type of course
bool UndergraduateCourse::setCourseType(bool t) {
  courseType_ = t;
  return true;
}

// Functions:

// Adds a student to this course
bool UndergraduateCourse::AddStudentToCourse(I_Student* s) {
  // Insert the student being added into the courseStudent vector
  courseStudents.push_back(s);
  return true;
}

// Removes a student from this course
bool UndergraduateCourse::RemoveStudentFromCourse(I_Student* s) {
  for (int i = 0; i < courseStudents.size(); i++) {
    // if the the current student is the same as the student that needs to be
    // deleted
    if (courseStudents[i]->getPersonCode() == s->getPersonCode()) {
      // Set the student ptr to null [NOTE: May have to delete
      // courseStudents[i]]
      courseStudents[i] = NULL;

      // remove the student from the vector
      courseStudents.erase(courseStudents.begin() + i);

      return true;
    }
  }

  return false;
}

// Adds a Instructor to this course
bool UndergraduateCourse::AddInstructorToCourse(I_Instructor* i) {
  courseInstructor.push_back(i);

  return true;
}

// Removes a Instructor from this course
bool UndergraduateCourse::RemoveInstructorFromCourse(I_Instructor* i) {
  // Set the instructor pointer to NULL [NOTE: May have to delete
  // courseInstructor[0]]
  courseInstructor[0] = NULL;

  // remove the instructor from the course
  courseInstructor.pop_back();

  return true;
}

// Print the course's instructor
string UndergraduateCourse::PrintInstructor() {
  if (courseInstructor.empty()) {
    string empty = "No Instuctor";
    return empty;
  }

  string code = to_string(courseInstructor[0]->getPersonCode());

  string instructor = "ID: " + code + " " + "Instructor Name: " +
                      courseInstructor[0]->getFirstName() + " " +
                      courseInstructor[0]->getLastName();
  return instructor;
}

// Prints all the students in this course
string UndergraduateCourse::PrintAllStudents() {
  string students;

  if (courseStudents.empty()) {
    string empty = "No Students";
    return empty;
  }

  for (int i = 0; i < courseStudents.size(); i++) {
    string code = to_string(courseStudents[i]->getPersonCode());
    students +=
        "\n"
        "ID: " +
        code + " " + "Student Name: " + courseStudents[i]->getFirstName() +
        " " + courseStudents[i]->getLastName();
  }

  students += "\n";

  return students;
}

// Combindes the course name, instructor, and the students into a string
string UndergraduateCourse::PrintCourse() {
  string students = PrintAllStudents();

  string instructor = PrintInstructor();

  string course = "Course Name: " + courseName_ + "\n" +
                  "Instructor: " + instructor + "\n" + "Students: " + "\n" +
                  students + "\n";

  return course;
}

// Check if the class is full or not (Checks if the class is not over 40
// students)
bool UndergraduateCourse::CourseSizeValidation() {
  // the courseStudent size is less than or equal to 40
  if (courseStudents.size() <= 40) {
    return true;
  }

  // if the courseStudent size is greater than 40 we return false
  return false;
}

// Check if the course already has a instructor
bool UndergraduateCourse::CourseInstructorValidation() {
  if (courseInstructor.size() >= 1) {
    return false;
  }

  return true;
}

// Returns whether the student matches the course type or not (Matches the
// student type and course type to make sure the student can join the course)
bool UndergraduateCourse::StudentCourseValidation(I_Student* s) {
  // if the course type is not the same as the students type we return false
  if (courseType_ != s->getPersonType()) {
    return false;
  }

  // if the course type and the student type is the same return true
  return true;
}

// pop back from from courseStudents
void UndergraduateCourse::courseStudentsPopBack() { courseStudents.pop_back(); }

// pop back from from courseInstructor
void UndergraduateCourse::coursInstructorPopBack() {
  courseInstructor.pop_back();
}

// Getters:

// Return  the preReq vector
vector<I_Course*> UndergraduateCourse::getPreReq() { return preReq; }

// Return the preReqFor vector
vector<I_Course*> UndergraduateCourse::getPreReqFor() { return preReq; }

// Functions:

// Add to the preReq vector
void UndergraduateCourse::addPreReq(I_Course* c) { preReq.push_back(c); }

// Remove from the preReq vector
void UndergraduateCourse::removePreReq() { preReqFor.pop_back(); }

// Add to the PreReqFor vector
void UndergraduateCourse::addPreReqFor(I_Course* c) { preReqFor.push_back(c); }

// Remove from the PreReqFor Vector
void UndergraduateCourse::removePreReqFor() { preReqFor.pop_back(); }

// PreReq Checker
bool UndergraduateCourse::checkPreReqs(I_Student* s) {
  // Check if the student has the pre requiest that is needed to take the course

  if (preReq.empty()) {
    return true;
  }
  if (s->containsCurrentCourse(preReq.at(0)) == true) {
    return true;
  }
  return false;
}

// Swap  courseStudent
bool UndergraduateCourse::removeCourseStudent(I_Student* s) {
  for (int i = 0; i < courseStudents.size(); i++) {
    if (s->getPersonCode() == courseStudents.at(i)->getPersonCode()) {
      courseStudents.at(i) = NULL;

      courseStudents.erase(courseStudents.begin() + i);
      return true;
    }
  }

  return false;
}

// Swap courseInstructor
bool UndergraduateCourse::removeCourseInstructor(I_Instructor* i) {
  for (int j = 0; j < courseInstructor.size(); j++) {
    if (i->getPersonCode() == courseInstructor.at(j)->getPersonCode()) {
      courseInstructor.at(j) = NULL;

      courseInstructor.erase(courseInstructor.begin() + j);
      return true;
    }
  }

  return false;
}
