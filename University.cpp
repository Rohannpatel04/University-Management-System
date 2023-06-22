#include "University.h"
using namespace std;
#include <fstream>
#include <iostream>

#include "Logger.h"

Logger* logger = Logger::getInstance();

// Constructor:
// Creates a Univerity
University::University(string uName) {
  logger->Log("Succesful:: Created: " + uName);
  universityName_ = uName;
}

// Destructor:
University::~University() {
  DeleteUniversity();
  logger->Log("Succesful:: Deleted: " + universityName_);
  delete logger;
  logger = NULL;
}

// Setters:

// Sets the name of the university
void University::setNameOfUniversity(string name) { universityName_ = name; }

// Functions:

// Create and add the course into the university
bool University::addCourse(string courseType, string courseName, int PRCode) {
  // Create course factory
  CourseFactory cFactory;

  // Increment the code counter
  ccounter_++;

  // Asign temp code variable
  int courseCode = ccounter_;

  // Create course object
  I_Course* course = cFactory.createCourse(courseType, courseCode, courseName);

  // If there is a pre req
  if (PRCode != 0) {
    // Create temp PRCourse ptr
    I_Course* PRCourse = universityCourses.at(PRCode);

    // Set the pre req of this course to be PRCOurse
    course->addPreReq(PRCourse);

    // Set the pre req class to contain that it is a pre req for another course

    PRCourse->addPreReqFor(course);
  }

  // Adds the course to the university course hashmap
  universityCourses.insert({courseCode, course});

  string code = to_string(courseCode);
  logger->Log("Succesful:: Added Course: " + courseName + " Code: " + code);
  return true;
}

// Remove a course from the university
bool University::removeCourse(int courseCode) {
  if (universityCourses.find(courseCode) == universityCourses.end()) {
    string code = to_string(courseCode);
    logger->Log("Unsuccesful:: Remove Course Code: " + code);
    return false;

  } else {
    /// Create a temp course variable
    I_Course* course = universityCourses.at(courseCode);

    //  Iterate through the student vector of the course that is being removed
    if (!course->getStudents().empty()) {
      for (int i = 0; i < course->getStudents().size(); i++) {
        // Create a temp student ptr
        I_Student* student = course->getStudents().at(i);

        // Call remove course
        student->removeCurrentCourses(course);

        // Remove course from history
        student->removePastCourses(course);

        // if the number of current courses is 1
        if (course->getStudents().at(i)->StudentValidation() == false) {
          removePerson(course->getStudents().at(i)->getPersonCode());
        }
      }
    }

    if (!course->getInstructor().empty()) {
      // Remove current course from instructor
      // Iterate through the course's instructor's vector of the current
      // classes they are teaching

      I_Instructor* instructor = course->getInstructor().at(0);

      // Remove current course teaching
      instructor->removeTeachingCurrentCourse(course);

      // Remove course teaching history
      instructor->removeTeachedPastCourse(course);
    }

    if (!course->getPreReqFor().empty()) {
      // Remove PF ptrs
      // Get the course which holds this courses ptr
      I_Course* course1 =
          universityCourses.at(course->getPreReqFor().at(0)->getCourseCode());

      // Set the ptr to null and remove it
      course1->getPreReq().at(0) = NULL;
      course1->removePreReq();
    }
    if (!course->getPreReq().empty()) {
      // Remove PR ptrs
      // Get the course which holds this courses ptr
      I_Course* course2 =
          universityCourses.at(course->getPreReq().at(0)->getCourseCode());

      // Set the ptr to null and remove it
      course2->getPreReqFor().at(0) = NULL;
      course2->removePreReqFor();
    }

    // Remove the course from the map
    universityCourses.erase(course->getCourseCode());

    string code = to_string(courseCode);
    logger->Log("Succesful:: Removed Course: " + course->getCourseName() +
                " Code: " + code);

    // Dealocate course
    delete course;
    course = NULL;

    return true;
  }
}

// Create and add the person into the univeristy
bool University::addPerson(string personType, string fName, string lName) {
  // Create course factory
  PersonFactory pFactory;

  // Increment the code counter
  pcounter_++;

  // Asign temp code variable
  int personCode = pcounter_;

  // Create person object
  I_Person* person =
      pFactory.createPerson(personCode, personType, fName, lName);

  // Adds the person to the university people hashmap
  universityPeople.insert({personCode, person});

  string code = to_string(personCode);
  logger->Log("Succesful:: Added Person: " + fName + " " + lName +
              " Type: " + personType + " Code: " + code);
  return true;
}

// Remove a person from the university
bool University::removePerson(int personCode) {
  if (universityPeople.find(personCode) == universityPeople.end()) {
    string code = to_string(personCode);
    logger->Log("Unsuccesful:: Removed Person Code: " + code);

    return false;
  } else {
    if (universityPeople.at(personCode) == NULL) {
      string code = to_string(personCode);
      logger->Log("Unsuccesful:: Removed Person Code: " + code);
      return false;
    }

    // Type variable
    string type = universityPeople.at(personCode)->getPersonType();

    // If a undergaduate is being removed
    if (type == "UNDERGRADUATE") {
      // Create a temp variable for Undergraduate
      I_Person* u = universityPeople.at(personCode);
      // Cast the object to a student
      I_Student* undergraduate = dynamic_cast<I_Student*>(u);

      // Iterate through the current courses the student is taking
      for (int i = 0; i < undergraduate->getCurrentCourses().size(); i++) {
        // Create a temp course variable
        I_Course* course = undergraduate->getCurrentCourses().at(i);

        // Remove the student from the course
        course->removeCourseStudent(undergraduate);
      }

      // Remove the student from the hashmap
      universityPeople.erase(undergraduate->getPersonCode());

      string code = to_string(personCode);
      logger->Log("Succesful:: Removed " + undergraduate->getPersonType() +
                  ": " + undergraduate->getFirstName() + " " +
                  undergraduate->getLastName() + " Code: " + code);

      // Delalocate memory
      delete undergraduate;
      undergraduate = NULL;
    }

    // If a graduate is being removed
    if (type == "GRADUATE") {
      // Student:

      // Create a temp varible for Graduate
      I_Person* g1 = universityPeople.at(personCode);

      // Cast the object to a student
      I_Student* graduate1 = dynamic_cast<I_Student*>(g1);

      // Iterate through the current courses the student is taking
      for (int i = 0; i < graduate1->getCurrentCourses().size(); i++) {
        // Create a temp course variable
        I_Course* course = graduate1->getCurrentCourses().at(i);

        // Remove the student from the course
        course->removeCourseStudent(graduate1);
      }

      // Instructor:

      // Create a temp varible for Graduate
      I_Person* g2 = universityPeople.at(personCode);

      // Cast the object to a student
      I_Instructor* graduate2 = dynamic_cast<I_Instructor*>(g2);

      // Iterate through the current courses the instructor is teaching
      for (int i = 0; i < graduate2->getTeachingCurrentCourses().size(); i++) {
        // Create a temp course variable
        I_Course* course = graduate2->getTeachingCurrentCourses().at(i);

        // Remove the instructor from the course
        course->removeCourseInstructor(graduate2);
      }

      string code = to_string(personCode);
      logger->Log("Succesful:: Removed " + graduate2->getPersonType() + ": " +
                  graduate2->getFirstName() + " " + graduate2->getLastName() +
                  " Code: " + code);

      // Remove the student from the hashmap
      universityPeople.erase(graduate2->getPersonCode());

      // Delalocate memory
      delete graduate2;
      graduate2 = NULL;
    }

    // If a faculty is being removed
    if (type == "FACULTY") {
      // Create a temp variable for Faculty
      I_Person* f = universityPeople.at(personCode);

      // Cast the object to a student
      I_Instructor* faculty = dynamic_cast<I_Instructor*>(f);

      // Iterate through the current courses the instructor is teaching
      for (int i = 0; i < faculty->getTeachingCurrentCourses().size(); i++) {
        // Create a temp course variable
        I_Course* course = faculty->getTeachingCurrentCourses().at(i);

        // Remove the instructor from the course
        course->removeCourseInstructor(faculty);
      }

      string code = to_string(personCode);
      logger->Log("Succesful:: Removed " + faculty->getPersonType() + ": " +
                  faculty->getFirstName() + " " + faculty->getLastName() +
                  " Code: " + code);

      // Remove the student from the hashmap
      universityPeople.erase(faculty->getPersonCode());

      // Delalocate memory
      delete faculty;
      faculty = NULL;
    }
  }

  return true;
}

// Asign a Instructor member to a course
bool University::addInstructorToCourse(int personCode, int courseCode) {
  if (universityCourses.at(courseCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Added Instructor Code " + pcode +
                " -> Course Code: " + ccode);

    return false;
  }
  if (universityPeople.at(personCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Added Instructor Code " + pcode +
                " -> Course Code: " + ccode);

    return false;
  }

  // Create a temp variable for the course
  I_Course* course = universityCourses.at(courseCode);

  string type = universityPeople.at(personCode)->getPersonType();

  if (type == "GRADUATE") {
    // Create a temp varible for the instructor
    I_Person* g = universityPeople.at(personCode);

    // Cast the object to a student
    Graduate* graduate = dynamic_cast<Graduate*>(g);

    // if the course already has a instructor return false
    if (course->getInstructor().size() > 1) {
      return false;
    }

    // if  Sameclasstest == false return false
    if (graduate->TeachingValidation(course) == false) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log(
          "UnSuccesful:: Added Instructor: " + graduate->getFirstName() + " " +
          graduate->getLastName() + " Person Code: " + pcode +
          " -> Course: " + course->getCourseName() + " Course Code: " + ccode);
      return false;
    }

    // if  Maxteachingtest == false return false
    if (graduate->MaxTeachingGraduate() == false) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log(
          "UnSuccesful:: Added Instructor: " + graduate->getFirstName() + " " +
          graduate->getLastName() + " Person Code: " + pcode +
          " -> Course: " + course->getCourseName() + " Course Code: " + ccode);
      return false;
    }

    if (graduate->containsCurrentCourse(course) == true) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log(
          "UnSuccesful:: Added Instructor: " + graduate->getFirstName() + " " +
          graduate->getLastName() + " Person Code: " + pcode +
          " -> Course: " + course->getCourseName() + " Course Code: " + ccode);
      return false;
    }

    // Add the instructor to the course
    course->AddInstructorToCourse(graduate);
    // course->AddInstructorToCourse(graduate);

    // Add the course to the instructor
    graduate->AddCoursetoInstructor(course);

    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Succesful:: Added Instructor: " + graduate->getFirstName() +
                " " + graduate->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return true;
  }

  if (type == "FACULTY") {
    // Create a temp varible for the instructor
    I_Person* f = universityPeople.at(personCode);

    // Cast the object to a student
    Faculty* faculty = dynamic_cast<Faculty*>(f);

    // if the course already has a instructor return false
    if (course->getInstructor().size() > 1) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log("UnSuccesful:: Added Instructor: " + faculty->getFirstName() +
                  " " + faculty->getLastName() + " Person Code: " + pcode +
                  " -> Course: " + course->getCourseName() +
                  " Course Code: " + ccode);
      return false;
    }

    // if person type == FACULTY && MaxTeachtest == false return false
    if (faculty->MaxTeachingFaculty() == false) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log("UnSuccesful:: Added Instructor: " + faculty->getFirstName() +
                  " " + faculty->getLastName() + " Person Code: " + pcode +
                  " -> Course: " + course->getCourseName() +
                  " Course Code: " + ccode);
      return false;
    }

    // Add the instructor to the course
    course->AddInstructorToCourse(faculty);
    // course->getInstructor().push_back(faculty);

    // Add the course to the instructor
    faculty->AddCoursetoInstructor(course);
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Succesful:: Added Instructor: " + faculty->getFirstName() +
                " " + faculty->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return true;
  }

  string pcode = to_string(personCode);
  string ccode = to_string(courseCode);
  logger->Log("UnSuccesful:: Added Instructor Code " + pcode +
              " -> Course Code: " + ccode);

  // This person cannot be a instructor return false
  return false;
}

// Remove a Instructor member from a course
bool University::removeInstructorFromCourse(int personCode, int courseCode) {
  if (universityCourses.at(courseCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Removed Instructor Code " + pcode +
                " -> Course Code: " + ccode);
    return false;
  }
  if (universityPeople.at(personCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Removed Instructor Code " + pcode +
                " -> Course Code: " + ccode);
    return false;
  }

  // Create a temp variable for the course
  I_Course* course = universityCourses.at(courseCode);

  string type = universityPeople.at(personCode)->getPersonType();

  if (type == "GRADUATE") {
    // Create a temp varible for the instructor
    I_Person* g = universityPeople.at(personCode);

    // Cast the object to a student
    Graduate* graduate = dynamic_cast<Graduate*>(g);

    // remove the instructor from the course
    course->RemoveInstructorFromCourse(graduate);

    // remove the course from the instructor
    graduate->removeCurrentInstructorClass(course);
    // Add the course to the instructor history
    graduate->getTeachingHistory().push_back(course);

    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Succesful:: Added Instructor: " + graduate->getFirstName() +
                " " + graduate->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return true;
  }

  if (type == "FACULTY") {
    // Create a temp varible for the instructor
    I_Person* f = universityPeople.at(personCode);

    // Cast the object to a student
    Faculty* faculty = dynamic_cast<Faculty*>(f);

    // Add the instructor to the course
    course->getInstructor().push_back(faculty);

    // Add the course to the instructor
    faculty->getTeachingCurrentCourses().push_back(course);
    // Add the course to the instructor history
    faculty->getTeachingHistory().push_back(course);

    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Succesful:: Added Instructor: " + faculty->getFirstName() +
                " " + faculty->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);

    return true;
  }

  string pcode = to_string(personCode);
  string ccode = to_string(courseCode);
  logger->Log("UnSuccesful:: Remove Instructor Code " + pcode +
              " -> Course Code: " + ccode);

  // This person cannot be a instructor return false
  return false;
}

// Add a student to a course
bool University::addStudentToCourse(int personCode, int courseCode) {
  if (universityCourses.at(courseCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Added Student Code " + pcode +
                " -> Course Code: " + ccode);

    return false;
  }
  if (universityPeople.at(personCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Added Student Code " + pcode +
                " -> Course Code: " + ccode);
    return false;
  }

  // Create a temp variable for the course
  I_Course* course = universityCourses.at(courseCode);

  // Create a temp varible for the student
  I_Person* s = universityPeople.at(personCode);

  // Cast the object to a student
  I_Student* student = dynamic_cast<I_Student*>(s);

  // If the person type and coruse type dont match
  if (s->getPersonType() != course->getCourseType()) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Unsuccesful:: Added Student: " + student->getFirstName() +
                " " + student->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return false;
  }

  // If the course size is less than 40
  if (course->CourseSizeValidation() == false) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Unsuccesful:: Added Student: " + student->getFirstName() +
                " " + student->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return false;
  }

  // If they have the requiered pre reqs
  if (course->checkPreReqs(student) == false) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Unsuccesful:: Added Student: " + student->getFirstName() +
                " " + student->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return false;
  }

  // check if the student has already taken this course
  if (student->containsCourseHistory(course) == true) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Unsuccesful:: Added Student: " + student->getFirstName() +
                " " + student->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return false;
  }

  // Add student to the course
  course->AddStudentToCourse(student);

  // Add course to the student
  student->AddCourseToStudent(course);

  string pcode = to_string(personCode);
  string ccode = to_string(courseCode);
  logger->Log("Succesful:: Added Student: " + student->getFirstName() + " " +
              student->getLastName() + " Person Code: " + pcode +
              " -> Course: " + course->getCourseName() +
              " Course Code: " + ccode);
  return true;
}

// Remove a student from a course
bool University::removeStudentFromCourse(int personCode, int courseCode) {
  if (universityCourses.at(courseCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Removed Student Code " + pcode +
                " -> Course Code: " + ccode);
    return false;
  }
  if (universityPeople.at(personCode) == NULL) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("UnSuccesful:: Removed Student Code " + pcode +
                " -> Course Code: " + ccode);
    return false;
  }
  // Create a temp variable for the course
  I_Course* course = universityCourses.at(courseCode);

  // Create a temp varible for the student
  I_Person* s = universityPeople.at(personCode);

  // Cast the object to a student
  I_Student* student = dynamic_cast<I_Student*>(s);

  // Check if the course has students in it or not
  if (course->getStudents().empty()) {
    string pcode = to_string(personCode);
    string ccode = to_string(courseCode);
    logger->Log("Unsuccesful:: Removed Student: " + student->getFirstName() +
                " " + student->getLastName() + " Person Code: " + pcode +
                " -> Course: " + course->getCourseName() +
                " Course Code: " + ccode);
    return false;
  }

  // Check if the student exist in the course or not
  for (int i = 0; i < course->getStudents().size(); i++) {
    if (course->getStudents().at(i)->getPersonCode() == personCode) {
      break;
    }

    if (i == course->getStudents().size() - 1) {
      string pcode = to_string(personCode);
      string ccode = to_string(courseCode);
      logger->Log("Unsuccesful:: Removed Student: " + student->getFirstName() +
                  " " + student->getLastName() + " Person Code: " + pcode +
                  " -> Course: " + course->getCourseName() +
                  " Course Code: " + ccode);
      return false;
    }
  }

  // Remove student from course
  course->RemoveStudentFromCourse(student);

  // Remove course from student
  student->RemoveCurrentCourse(course);

  // Check if student is still a valid university
  // student
  if (student->StudentValidation() == false) {
    removePerson(student->getPersonCode());
  }

  string pcode = to_string(personCode);
  string ccode = to_string(courseCode);
  logger->Log("Succesful:: Removed Student: " + student->getFirstName() + " " +
              student->getLastName() + " Person Code: " + pcode +
              " -> Course: " + course->getCourseName() +
              " Course Code: " + ccode);

  return true;
}

// Print a students current courses
void University::PrintAStudentsCourses(int personCode) {
  // Create a temp varible for the student
  I_Person* s = universityPeople.at(personCode);

  // Cast the object to a student
  I_Student* student = dynamic_cast<I_Student*>(s);

  // print the students courses
  student->PrintCurrentCourses();

  string pcode = to_string(personCode);

  logger->Log(
      "Succesful:: Printed A Student's Courses: " + student->getFirstName() +
      " " + student->getLastName() + " Person Code: " + pcode);
}
// Print a students course history
void University::PrintAStudentsCourseHistory(int personCode) {
  // Create a temp student ptr
  // Create a temp varible for the student
  I_Person* s = universityPeople.at(personCode);

  // Cast the object to a student
  I_Student* student = dynamic_cast<I_Student*>(s);

  // print the students course history
  student->PrintPastCourses();

  string pcode = to_string(personCode);
  logger->Log("Succesful:: Printed A Student's Course History: " +
              student->getFirstName() + " " + student->getLastName() +
              " Person Code: " + pcode);
}

// Print a instructors current courses
void University::PrintAInstructorsCourses(int personCode) {
  // Create a temp instructor ptr
  I_Person* i = universityPeople.at(personCode);

  // Cast the object to a student
  I_Instructor* instructor = dynamic_cast<I_Instructor*>(i);

  // print the instructor current courses
  instructor->PrintTeachingCurretCourses();

  string pcode = to_string(personCode);
  logger->Log("Succesful:: Printed A Instructor's Courses: " +
              instructor->getFirstName() + " " + instructor->getLastName() +
              " Person Code: " + pcode);
}

// Print a instructors course history
void University::PrintAInstructorsCourseHistory(int personCode) {
  // Create a temp instructor ptr
  I_Person* i = universityPeople.at(personCode);

  // Cast the object to a student
  I_Instructor* instructor = dynamic_cast<I_Instructor*>(i);

  // print the instructor current courses
  instructor->PrintTeachingCoursesHistory();

  string pcode = to_string(personCode);
  logger->Log("Succesful:: Printed A Instructor's Teaching History: " +
              instructor->getFirstName() + " " + instructor->getLastName() +
              " Person Code: " + pcode);
}

// Print all the students in course
void University::PrintALLStudentsInACourse(int courseCode) {
  // Create a temp course ptr
  I_Course* course = universityCourses[courseCode];

  cout << "Course Code: " << course->getCourseCode() << " "
       << "Course Name: " << course->getCourseName() << endl;
  // print the students in a course
  cout << course->PrintAllStudents() << endl;

  string ccode = to_string(courseCode);
  logger->Log(
      "Succesful:: Printed A Courses's Students: " + course->getCourseName() +
      " "
      " Course Code: " +
      ccode);
}

// Print a Instructor for a course
void University::PrintInstructorInACouse(int courseCode) {
  // Create a temp course ptr
  I_Course* course = universityCourses[courseCode];

  cout << "Course Code: " << course->getCourseCode() << " "
       << "Course Name: " << course->getCourseName() << endl;
  cout << course->PrintInstructor() << endl;

  string ccode = to_string(courseCode);
  logger->Log(
      "Succesful:: Printed A Courses's Instructor: " + course->getCourseName() +
      " "
      " Course Code: " +
      ccode);
}

// Print all Current courses including the Students and instructor
void University::PrintAllCurrentCourses(string outputType) {
  if (outputType == "SCREEN") {
    for (auto i : universityCourses) {
      if (i.second == NULL) {
        continue;
      }
      cout << " " << endl;
      cout << i.second->PrintCourse() << endl;
    }

    logger->Log("Succesful:: Printed All Current Course At " + universityName_ +
                " To The Screen");
  }

  if (outputType == "FILE") {
    // Create and open a new file
    ofstream file("UniversityCourses.txt");

    for (auto i : universityCourses) {
      if (i.second == NULL) {
        continue;
      }
      // Print all the information to a File
      file << i.second->PrintCourse();
    }
    logger->Log("Succesful:: Printed All Current Course At " + universityName_ +
                " To UniversityCourses.txt");

    // Close the file
    file.close();
  }
}

// Delete the university including deleting all people and courses
bool University::DeleteUniversity() {
  // Delete all nodes inside course hashmap
  for (auto i : universityCourses) {
    if (i.second == NULL) {
      continue;
    } else {
      // Temp code
      int code = i.first;

      // Delete course
      delete i.second;
      i.second = NULL;
      universityCourses[code] = NULL;
    }
  }

  // Delete all nodes inside student hashmap
  for (auto i : universityPeople) {
    if (i.second == NULL) {
      continue;
    }

    if (i.second->getPersonType() == "UNDERGRADUATE" ||
        i.second->getPersonType() == "GRADUATE") {
      // Create a temp student ptr
      I_Person* s = i.second;

      // Cast the object to a student
      I_Student* student = dynamic_cast<I_Student*>(s);

      // Temp Code
      int code = student->getPersonCode();

      // Delete Student
      delete student;
      student = NULL;
      universityPeople[code] = NULL;

    }

    else if (i.second->getPersonType() == "FACULTY") {
      // Create a temp student ptr

      I_Person* inst = i.second;

      // Cast the object to a instuctor
      Faculty* instructor = dynamic_cast<Faculty*>(inst);

      // temp code
      int code = instructor->getPersonCode();

      // Delete Faculty
      delete instructor;
      instructor = NULL;
      universityPeople[code] = NULL;
    }
  }

  logger->Log("Succesful:: Deleted: " + universityName_);
  return true;
}

// Checks if a student is enrolled in atleast one course and removes
// students that are not
bool University::StudentValidatation() {
  for (auto i : universityPeople) {
    if (i.second == NULL) {
      continue;
    }

    I_Person* person = universityPeople.at(i.first);

    // Check if the person is a student
    if (person->getPersonType() == "GRADUATE" ||
        person->getPersonType() == "UNDERGRADUATE") {
      // Cast the object to a student
      I_Student* student = dynamic_cast<I_Student*>(person);

      // Check if the student is a valid student or not (if the student is
      // taking atleast 1 class)
      if (student->StudentValidation() == false) {
        // Remove the student from the university

        int code = student->getPersonCode();

        delete student;
        student = NULL;
        universityPeople[code] = NULL;
      }
    }
  }
  logger->Log("Succesful:: Checked For Invalid Students At: " +
              universityName_);
  return true;
}
