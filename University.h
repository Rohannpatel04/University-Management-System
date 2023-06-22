#ifndef UNIVERSITY
#define UNIVERSITY

#include <unordered_map>

#include "CourseFactory.h"
#include "I_Course.h"
#include "I_Instructor.h"
#include "I_Person.h"
#include "I_Student.h"
#include "Logger.h"
#include "PersonFactory.h"
using namespace std;

class University {
 public:
  // Constructor:

  // Creates a Univerity
  University(string uName);

  // Destructor:

  ~University();

  // Setters:

  // Sets the name of the university
  void setNameOfUniversity(string name);

  // Functions:

  // Create and add the course into the university
  bool addCourse(string courseType, string courseName, int PRCode);

  // Remove a course from the university
  bool removeCourse(int courseCode);

  // Create and add the person into the univeristy
  bool addPerson(string personType, string fName, string lName);

  // Remove a person from the university
  bool removePerson(int personCode);

  // Asign a Instructor member to a course
  bool addInstructorToCourse(int personCode, int courseCode);

  // Remove a Instructor member from a course
  bool removeInstructorFromCourse(int personCode, int courseCode);

  // Add a student to a course
  bool addStudentToCourse(int personCode, int courseCode);

  // Remove a student from a course
  bool removeStudentFromCourse(int personCode, int courseCode);

  // Print a students current courses
  void PrintAStudentsCourses(int personCode);

  // Print a students course history
  void PrintAStudentsCourseHistory(int personCode);

  // Print a instructors current courses
  void PrintAInstructorsCourses(int personCode);

  // Print a instructors course history
  void PrintAInstructorsCourseHistory(int personCode);

  // Print all the students in course
  void PrintALLStudentsInACourse(int courseCode);

  // Print a Instructor for a course
  void PrintInstructorInACouse(int courseCode);

  // Print all Current courses including the
  void PrintAllCurrentCourses(string outputType);

  // Delete the university including deleting all people and courses
  bool DeleteUniversity();

  // Checks if a student is enrolled in atleast one course and removes students
  // that are not
  bool StudentValidatation();

 private:
  // Data Structure:

  // Stores all the people within the univeristy
  unordered_map<int, I_Person*> universityPeople;

  // Stores all the courses taught at the univeristy
  unordered_map<int, I_Course*> universityCourses;

  // Data Type:

  // Univerity Name
  string universityName_;

  // Code Counter
  int ccounter_ = 0;
  int pcounter_ = 0;
};

#endif  // UNIVERSITY
