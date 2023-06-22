using namespace std;
#include <fstream>
#include <iostream>

#ifndef LOGGER_H_
#define LOGGER_H_

#include "string"
using namespace std;

class Logger {
 public:
  // Destructor
  ~Logger();

  // get logger
  static Logger* getInstance();

  // Log information
  void Log(string s);

 private:
  // Constructor
  Logger();

  static Logger* Instance;

  ofstream logFile;
};

#endif  // LOGGER