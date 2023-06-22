#include "PersonFactory.h"

I_Person* PersonFactory::createPerson(int personCode, string personType,
                                      string fName, string lName) {
  // Unique code counter
  int counter = 0;

  // If personType is UNDERGRADUATE
  if (personType == "UNDERGRADUATE") {
    // create a UNDERGRADUATE object and return it
    return new Undergraduate(personCode, personType, fName, lName);
  }

  // If personType is GRADUATE
  if (personType == "GRADUATE") {
    // create a GRADUATE object and return it
    return new Graduate(personCode, personType, fName, lName);
  }

  // If personType is FACULTY
  if (personType == "FACULTY") {
    // create a FACULTY object and return it
    return new Faculty(personCode, personType, fName, lName);
  }

  return NULL;
}
