#ifndef PERSONFACTORY_H_
#define PERSONFACTORY_H_

#include "Faculty.h"
#include "Graduate.h"
#include "I_Person.h"
#include "Undergraduate.h"
#include "string"
using namespace std;

class PersonFactory {
 public:
  I_Person* createPerson(int personCode, string personType, string fName,
                         string lName);
};

#endif  // PERSONFACTORY
