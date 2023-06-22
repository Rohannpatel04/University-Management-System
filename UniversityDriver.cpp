#include "CourseFactory.h"
#include "PersonFactory.h"
#include "University.h"

int main() {
  // Create a new university
  University UW("University of Washigton");

  cout << "Create 8 Courses" << endl;
  UW.removeCourse(1);
  // CSS142 is a pre req for CSS143
  UW.addCourse("UNDERGRADUATE", "CSS142", 0);
  UW.addCourse("UNDERGRADUATE", "CSS143", 1);
  UW.addCourse("UNDERGRADUATE", "CSS301", 0);
  UW.addCourse("UNDERGRADUATE", "CSS350", 0);
  UW.addCourse("UNDERGRADUATE", "CSS343", 0);
  UW.addCourse("GRADUATE", "CSS502", 0);
  UW.addCourse("GRADUATE", "CSS600", 0);
  UW.addCourse("GRADUATE", "CSS601", 0);

  cout << "Add 3 faculty" << endl;
  UW.addPerson("FACULTY", "jacob", "john");
  UW.addPerson("FACULTY", "rohan", "patel");
  UW.addPerson("FACULTY", "Oliver", "Jim");

  cout << "Add 1 Undergrauate" << endl;
  UW.addPerson("UNDERGRADUATE", "Smart", "Man");

  cout << "Add  2 Graduates" << endl;
  UW.addPerson("GRADUATE", "Bob", "patel");
  UW.addPerson("GRADUATE", "Bhavik", "patel");

  cout << "Add Faculty to courses" << endl;

  // Testing max teaching limit
  UW.addInstructorToCourse(1, 1);
  UW.addInstructorToCourse(1, 2);
  UW.addInstructorToCourse(1, 3);
  UW.addInstructorToCourse(1, 4);
  UW.PrintAInstructorsCourses(1);
  cout << " " << endl;

  UW.addInstructorToCourse(2, 4);
  UW.addInstructorToCourse(3, 5);

  cout << "Add Graduates to courses" << endl;

  // Testing a graduate student cant be enrolled in a undergrauate course
  UW.addStudentToCourse(5, 1);
  UW.PrintALLStudentsInACourse(1);
  cout << " " << endl;

  UW.addStudentToCourse(5, 6);
  UW.addStudentToCourse(6, 7);

  cout << "Add/Remove Grduates to courses at Insturctors" << endl;

  // Testing a graduate not being able to teach the class they are
  // enrolled in
  UW.addInstructorToCourse(5, 6);
  UW.PrintAInstructorsCourses(5);
  cout << " " << endl;

  // testing graduate max teaching limit and removing a instructor
  UW.addInstructorToCourse(6, 6);
  UW.addInstructorToCourse(6, 8);
  UW.PrintAInstructorsCourses(6);
  UW.removeInstructorFromCourse(6, 6);
  UW.addInstructorToCourse(6, 8);
  UW.PrintAInstructorsCourses(6);
  UW.PrintAInstructorsCourseHistory(6);
  cout << " " << endl;

  cout << "Add/Remove Undergrautes to courses" << endl;

  UW.addStudentToCourse(4, 3);
  UW.addStudentToCourse(4, 4);
  UW.addStudentToCourse(4, 5);
  UW.addStudentToCourse(4, 1);
  UW.PrintAStudentsCourses(4);
  UW.removeStudentFromCourse(4, 1);
  UW.PrintAStudentsCourses(4);
  UW.PrintAStudentsCourseHistory(4);
  cout << " " << endl;

  // Testing that a undergraduate student cant enroll in a graduate course
  UW.addStudentToCourse(4, 8);
  UW.PrintAStudentsCourses(4);
  cout << " " << endl;

  // A student cant enroll into a course they have already taken
  UW.addStudentToCourse(4, 1);
  UW.PrintAStudentsCourses(4);
  cout << " " << endl;

  cout << "check for invalid Students who arent taking atleast one class"
       << endl;
  UW.StudentValidatation();

  cout << "Add Undergraduate Students" << endl;

  // Testing that a course cant hold more than 40 students
  for (int i = 0; i < 50; i++) {
    UW.addPerson("UNDERGRADUATE", "FirstName", "LastName");

    // Assign the student to take course 1 so they can take course 2
    UW.addStudentToCourse(7 + i, 1);

    // Assign the student to course 2
    UW.addStudentToCourse(7 + i, 2);
  }
  // Check for invalid Students who arent taking atleast one class
  UW.StudentValidatation();

  UW.PrintALLStudentsInACourse(1);
  UW.PrintALLStudentsInACourse(2);
  cout << " " << endl;

  cout << "Add 2 students who don't want to take any classes" << endl;
  UW.addPerson("GRADUATE", "Bad", "Student");
  UW.addPerson("GRADUATE", "Lazy", "Student");

  cout << "check for invalid Students who arent taking atleast one class"
       << endl;
  UW.StudentValidatation();

  cout << "Remove courses" << endl;

  // Displaying how the instructors current courses updates before and after the
  // course was removed from the university
  UW.PrintAInstructorsCourses(1);
  UW.removeCourse(3);
  UW.PrintAInstructorsCourses(1);
  cout << " " << endl;

  cout << "Remove student" << endl;

  // Displaying course 6 students before and after student 5 was removed
  UW.PrintALLStudentsInACourse(6);
  UW.removePerson(5);
  UW.PrintALLStudentsInACourse(6);
  cout << " " << endl;

  cout << "Print to screen or into a file" << endl;
  UW.PrintAllCurrentCourses("SCREEN");
  UW.PrintAllCurrentCourses("FILE");

  cout << "Delete the university" << endl;
  UW.DeleteUniversity();

  return 0;
}
