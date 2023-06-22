#ifndef I_INSTRUCTOR_H_
#define I_INSTRUCTOR_H_

#include "I_Person.h"

class I_Course;
class I_Instructor : virtual public I_Person {
 public:
  // Destructor:
  virtual ~I_Instructor() {}
  // Getters:

  // Gets the courses the instructor is teaching currently
  virtual vector<I_Course*> getTeachingCurrentCourses() = 0;

  // Get the teaching history vector
  virtual vector<I_Course*> getTeachingHistory() = 0;

  // Functions:

  // Prints out all the classes this faculty is teaching
  virtual void PrintTeachingCurretCourses() = 0;

  // Prints out all the classes this faculty has taught
  virtual void PrintTeachingCoursesHistory() = 0;

  // Add a course to the current courses teaching and history vector
  virtual bool AddCoursetoInstructor(I_Course* c) = 0;

  // Remove a course from a instructors current courses vector
  virtual bool removeCurrentInstructorClass(I_Course* c) = 0;

  // pop back from from currentCourses
  virtual void teachingCurrentCoursesPopBack() = 0;

  // pop back from from courseHistory
  virtual void teachedPastCoursesPopBack() = 0;

  // Remove teachingCurrentCourse
  virtual bool removeTeachingCurrentCourse(I_Course* c) = 0;

  // Remove trachingPastCourse
  virtual bool removeTeachedPastCourse(I_Course* c) = 0;

 protected:
  // Data Structure:

  // Stores all the current classes the faculty memeber is teaching
  vector<I_Course*> teachingCurrentCourses;

  // Stores the faculty members teaching hsitory
  vector<I_Course*> TeachedPastCourses;
};

#endif  // I_Instructor