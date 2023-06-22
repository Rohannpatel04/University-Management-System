#ifndef COURSEFACTORY_H_
#define COURSEFACTORY_H_

#include "GraduateCourse.h"
#include "I_Course.h"
#include "Undergraduate.h"
#include "UndergraduateCourse.h"

class CourseFactory {
 public:
  I_Course* createCourse(string courseType, int courseCode, string courseName);
};

#endif  // PERSONFACTORY
