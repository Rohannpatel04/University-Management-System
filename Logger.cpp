using namespace std;
#include "Logger.h"

#include <fstream>
#include <iostream>

Logger* Logger::Instance = NULL;

// Constructor
Logger::Logger() { logFile.open("Logger.txt"); }

// Destructor
Logger::~Logger() { logFile.close(); }

// get logger
Logger* Logger::getInstance() {
  if (Instance == NULL) {
    Instance = new Logger();
  }

  return Instance;
}

// Log information
void Logger::Log(string s) { logFile << s << endl; }