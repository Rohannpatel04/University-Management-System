#ifndef I_STUDENT_H_
#define I_STUDENT_H_

// #include <vector>

#include "I_Course.h"
#include "I_Person.h"

class I_Course;
class I_Student : virtual public I_Person {
 public:
  // Destructor:
  virtual ~I_Student() {}

  // Getters:

  // Get the current courses a student is taking
  virtual vector<I_Course*> getCurrentCourses() = 0;

  // Get the student course history vector
  virtual vector<I_Course*> getCourseHistory() = 0;

  // Functions:

  // Prints out all the classes this student is taking
  virtual void PrintCurrentCourses() = 0;

  // Prints out all the courses a student has taken
  virtual void PrintPastCourses() = 0;

  // Adds the course to the current course vector and the past courses vector
  virtual bool AddCourseToStudent(I_Course* c) = 0;

  // Removes a course from their current scheudle
  virtual bool RemoveCurrentCourse(I_Course* c) = 0;

  // Returns whether the student is eligible to be a student (Is taking one
  // course)
  virtual bool StudentValidation() = 0;

  // pop back from from currentCourses
  virtual void currentCoursesPopBack() = 0;

  // pop back from from courseHistory
  virtual void courseHistoryPopBack() = 0;

  // check if a course is inside the current courses vector
  virtual bool containsCurrentCourse(I_Course* c) = 0;

  // check if a course is inside the course history vector
  virtual bool containsCourseHistory(I_Course* c) = 0;

  // Swap currentCourses
  virtual bool removeCurrentCourses(I_Course* c) = 0;

  // Swap pastCourses
  virtual bool removePastCourses(I_Course* c) = 0;

 protected:
  // Data Structure:

  // Stores current coruses the Student is currently taking
  vector<I_Course*> currentCourses;

  // Stores the undergrauate students course history
  vector<I_Course*> pastCourses;
};

#endif  // I_STUDENT
