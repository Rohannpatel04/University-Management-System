#include "CourseFactory.h"

#include <iostream>
using namespace std;

I_Course* CourseFactory::createCourse(string courseType, int courseCode,
                                      string courseName) {
  // If courseType is UNDERGRADUATE
  if (courseType == "UNDERGRADUATE") {
    // create a UNDERGRADUATE object and return it
    return new UndergraduateCourse(courseType, courseCode, courseName);
  }

  // If courseType is GRADUATE
  if (courseType == "GRADUATE") {
    // create a GRADUATE object and return it
    return new GraduateCourse(courseType, courseCode, courseName);
  }

  return NULL;
}