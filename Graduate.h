#ifndef GRADUATE_H_
#define GRADUATE_H_
#include "I_Instructor.h"
#include "I_Person.h"
#include "I_Student.h"

#include "string"

class Graduate : public I_Instructor, public I_Student {
 public:
  // Constructor:

  // Creates a graduate student with the a unique key, the first name, and last
  // name
  Graduate(int personCode, string personType, string fName, string lName);

  // Destructor:
  // ~Graduate();
  virtual ~Graduate() {}

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
  void teachingCurrentCoursesPopBack();

  // pop back from from courseHistory
  void teachedPastCoursesPopBack();

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

  // Student:

  // Getters:

  // Gets the current courses a student is taking
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

  // Fucntions:

  // check if the graduate student is not enrolled in the course they are trying
  // to teach
  bool TeachingValidation(I_Course*);

  // check if a graduate is already teaching a class
  bool MaxTeachingGraduate();

  // check if a course is inside the current courses vector
  virtual bool containsCurrentCourse(I_Course* c);

  // check if a course is inside the course history vector
  virtual bool containsCourseHistory(I_Course* c);

  // remove currentCourses
  virtual bool removeCurrentCourses(I_Course* c);

  // remove pastCourses
  virtual bool removePastCourses(I_Course* c);

  // Remove teachingCurrentCourse
  virtual bool removeTeachingCurrentCourse(I_Course* c);

  // Remove trachingPastCourse
  virtual bool removeTeachedPastCourse(I_Course* c);
};

#endif  // GRADUATE
