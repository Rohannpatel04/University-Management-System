#ifndef FACULTY_H_
#define FACULTY_H_

#include "I_Course.h"
#include "I_Instructor.h"
#include "I_Person.h"
#include "cstring"
using namespace std;

class Faculty : public I_Instructor {
 public:
  // Constructor:

  // Creates a faculty member
  Faculty(int personCode, string personType, string fName, string lName);

  // Destructor:
  virtual ~Faculty() {}

  // Check if the faculty member can teach a course (no more than 3)
  bool MaxTeachingFaculty();

  // Instructor:

  // Getters:

  // Gets the courses the instructor is teaching currently
  virtual vector<I_Course*> getTeachingCurrentCourses();

  // Get the teaching history vector
  virtual vector<I_Course*> getTeachingHistory();

  // Functions:

  //  Prints out all the classes this faculty is teaching
  virtual void PrintTeachingCurretCourses();

  // Prints out all the classes this faculty has taught
  virtual void PrintTeachingCoursesHistory();

  // Add a course to the current courses teaching and history vector
  virtual bool AddCoursetoInstructor(I_Course* c);

  // Remove a course from a instructors current courses vector
  virtual bool removeCurrentInstructorClass(I_Course* c);

  // pop back from from currentCourses
  virtual void teachingCurrentCoursesPopBack();

  // pop back from from courseHistory
  virtual void teachedPastCoursesPopBack();

  // Person:

  // Getters:

  // Get the first name
  virtual string getFirstName();

  // Get the last name
  virtual string getLastName();

  // Get Student type
  virtual string getPersonType();

  // Get Person Code
  virtual int getPersonCode();

  // Setters:

  // Set the first name
  virtual void setFirstName(string fName);

  // Set the Last name
  virtual void setLastName(string lName);

  // Set the student type
  virtual void setPersonType(string personType);

  // Remove teachingCurrentCourse
  virtual bool removeTeachingCurrentCourse(I_Course* c);

  // Remove trachingPastCourse
  virtual bool removeTeachedPastCourse(I_Course* c);
};

#endif  // FACULTY
