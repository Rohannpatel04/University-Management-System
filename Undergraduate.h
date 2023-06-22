#ifndef UNDERGRADUATE_H_
#define UNDERGRADUATE_H_

#include "I_Course.h"
#include "I_Person.h"
#include "I_Student.h"


class Undergraduate : public I_Student {
 public:
  // Creates a undergraduate student
  Undergraduate(int personCode, string personType, string fName, string lName);

  // Destructor:
  virtual ~Undergraduate() {}
  // ~Undergraduate();

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

  // Student:

  // Getters:

  // get current course vector
  virtual vector<I_Course*> getCurrentCourses();

  // Get the student course history vector
  virtual vector<I_Course*> getCourseHistory();

  // Functions:

  // Prints out all the classes this student is taking
  virtual void PrintCurrentCourses();

  // Prints out all the courses a student has taken
  virtual void PrintPastCourses();

  // Adds the course to the current course vector and the past courses vector
  virtual bool AddCourseToStudent(I_Course* c);

  // Removes a course from their current scheudle
  virtual bool RemoveCurrentCourse(I_Course* c);

  // Returns whether the student is eligible to be a student (Is taking one
  // course)
  virtual bool StudentValidation();

  // pop back from from currentCourses
  virtual void currentCoursesPopBack();

  // pop back from from courseHistory
  virtual void courseHistoryPopBack();

  // check if a course is inside the current courses vector
  virtual bool containsCurrentCourse(I_Course* c);

  // check if a course is inside the course history vector
  virtual bool containsCourseHistory(I_Course* c);

  // Swap currentCourses
  virtual bool removeCurrentCourses(I_Course* c);

  // Swap pastCourses
  virtual bool removePastCourses(I_Course* c);
};

#endif  // UNDERGRADUATE
