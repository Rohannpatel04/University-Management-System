#ifndef GRADUATECOURSE_H_
#define GRADUATECOURSE_H_

#include "I_Course.h"
#include "I_Instructor.h"
#include "I_Person.h"
#include "I_Student.h"


class GraduateCourse : public I_Course {
 public:
  // Constructor:

  // Creates a graduate course
  GraduateCourse(string courseType, int courseCode, string courseName);

  // Destructor:
  // virtual ~GraduateCourse() {}
  ~GraduateCourse();

  // Getters:

  // Get the courses code
  virtual int getCourseCode();

  // Get Course type
  virtual string getCourseType();

  // Get Students
  virtual vector<I_Student*> getStudents();

  // Get Instructor
  virtual vector<I_Instructor*> getInstructor();

  // Get Course Name
  virtual string getCourseName();

  // Setters:

  // Sets the type of course
  virtual bool setCourseType(bool type);

  // Functions:

  // Adds a student to this course
  virtual bool AddStudentToCourse(I_Student* s);

  // Removes a student from this course
  virtual bool RemoveStudentFromCourse(I_Student* s);

  // Adds a Instructor to this course
  virtual bool AddInstructorToCourse(I_Instructor* i);

  // Removes a Instructor from this course
  virtual bool RemoveInstructorFromCourse(I_Instructor* i);

  // Prints all the students in this course
  virtual string PrintAllStudents();

  // Print the course's instructor
  virtual string PrintInstructor();

  // Combindes the course name, instructor, and the students into a string
  virtual string PrintCourse();

  // Check if the class is full or not (Checks if the class is not over 40
  // students)
  virtual bool CourseSizeValidation();

  // Check if the course already has a instructor
  virtual bool CourseInstructorValidation();

  // Returns whether the student matches the course type or not (Matches the
  // student type and course type to make sure the student can join the course)
  virtual bool StudentCourseValidation(I_Student* s);

  // pop back from from courseStudents
  virtual void courseStudentsPopBack();

  // pop back from from courseInstructor
  virtual void coursInstructorPopBack();

  // Pre Req Inplementation:

  // Getters:

  // Return  the preReq vector
  virtual vector<I_Course*> getPreReq();

  // Return the preReqFor vector
  virtual vector<I_Course*> getPreReqFor();

  // Functions:

  // Add to the preReq vector
  virtual void addPreReq(I_Course* c);

  // Remove from the preReq vector
  virtual void removePreReq();

  // Add to the PreReqFor vector
  virtual void addPreReqFor(I_Course* c);

  // Remove from the PreReqFor Vector
  virtual void removePreReqFor();

  // PreReq Checker
  virtual bool checkPreReqs(I_Student* s);

  // Swap  courseStudent
  virtual bool removeCourseStudent(I_Student* s);

  // Swap courseInstructor
  virtual bool removeCourseInstructor(I_Instructor* i);
};

#endif  // GRADUATECOURSE
