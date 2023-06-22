#ifndef I_COURSE_H_
#define I_COURSE_H_

#include <string>
#include <vector>

#include "I_Instructor.h"
#include "I_Student.h"

class I_Student;
class I_Instructor;
class I_Course {
 public:
  // Destructor

  // Getters:

  // Get the courses code
  virtual int getCourseCode() = 0;

  // Get Course type
  virtual string getCourseType() = 0;

  // Get Students
  virtual vector<I_Student*> getStudents() = 0;

  // Get Instructor
  virtual vector<I_Instructor*> getInstructor() = 0;

  // Get Course Name
  virtual string getCourseName() = 0;

  // Setters:

  // Set all data

  // Sets the type of course
  virtual bool setCourseType(bool type) = 0;

  // Functions:

  // Adds a student to this course
  virtual bool AddStudentToCourse(I_Student* s) = 0;

  // Removes a student from this course
  virtual bool RemoveStudentFromCourse(I_Student* s) = 0;

  // Adds a Instructor to this course
  virtual bool AddInstructorToCourse(I_Instructor* i) = 0;

  // Removes a Instructor from this course
  virtual bool RemoveInstructorFromCourse(I_Instructor* i) = 0;

  // Puts all the students into a string
  virtual string PrintAllStudents() = 0;

  // Puts the instructor for the course into a string
  virtual string PrintInstructor() = 0;

  // Combindes the course name, instructor, and the students into a string
  virtual string PrintCourse() = 0;

  // Check if the class is full or not (Checks if the class is not over 40
  // students)
  virtual bool CourseSizeValidation() = 0;

  // Check if the course already has a instructor
  virtual bool CourseInstructorValidation() = 0;

  // Returns whether the student matches the course type or not (Matches the
  // student type and course type to make sure the student can join the course)
  virtual bool StudentCourseValidation(I_Student* s) = 0;

  // pop back from from courseStudents
  virtual void courseStudentsPopBack() = 0;

  // pop back from from courseInstructor
  virtual void coursInstructorPopBack() = 0;

  // Pre Req Inplementation:

  // Getters:

  // Return  the preReq vector
  virtual vector<I_Course*> getPreReq() = 0;

  // Return the preReqFor vector
  virtual vector<I_Course*> getPreReqFor() = 0;

  // Functions:

  // Add to the preReq vector
  virtual void addPreReq(I_Course* c) = 0;

  // Remove from the preReq vector
  virtual void removePreReq() = 0;

  // Add to the PreReqFor vector
  virtual void addPreReqFor(I_Course* c) = 0;

  // Remove from the PreReqFor Vector
  virtual void removePreReqFor() = 0;

  // PreReq Checker
  virtual bool checkPreReqs(I_Student* s) = 0;

  // Swap  courseStudent
  virtual bool removeCourseStudent(I_Student* s) = 0;

  // Swap courseInstructor
  virtual bool removeCourseInstructor(I_Instructor* i) = 0;

 protected:
  // Data Structure:

  // Stores the students in this course
  vector<I_Student*> courseStudents;

  // Stores the instructor for this class
  vector<I_Instructor*> courseInstructor;

  // Stores the prereqs for this course
  vector<I_Course*> preReq;

  // Stores what this course is a prereq for
  vector<I_Course*> preReqFor;

  // Data Type:

  // Course type
  string courseType_;

  // Course name
  string courseName_;

  // course code
  int courseCode_;
};

#endif  // I_COURSE