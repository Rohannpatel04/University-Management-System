#ifndef I_PERSON_H_
#define I_PERSON_H_

#include <string>
#include <vector>

#include "iostream"
using namespace std;

class I_Person {
 public:
  // Destrucutor:
  virtual ~I_Person() {}

  // Getters:

  // Get the first name
  virtual string getFirstName() = 0;

  // Get the last name
  virtual string getLastName() = 0;

  // Get Student type
  virtual string getPersonType() = 0;

  // Get Person Code
  virtual int getPersonCode() = 0;

  // Setters:

  // Set the first name
  virtual void setFirstName(string fName) = 0;

  // Set the Last name
  virtual void setLastName(string lName) = 0;

  // Set the student type
  virtual void setPersonType(string personType) = 0;

  // Functions:

  //  Operator Overloads:

 protected:
  // Data Type:

  // first name
  string firstName_;

  // last name
  string lastName_;

  // The unique key
  int personCode_;

  // The type of person object
  string personType_;
};

#endif  // I_PERSON