#pragma once
#include <map>
#include <iostream>
#include <string>

#define SYNTAX_ERROR 1
#define DEFINE_ERROR 2

struct Error {
  int level = 0;
  int line = 0;
  std::string cause = "None";
};

const std::map<int, std::string> error_strings {
  { SYNTAX_ERROR, "SYNTAX_ERROR" },
  { DEFINE_ERROR, "DEFINE_ERROR" },
};

class ErrorList {
public:
  void send_error(char cause, int type, int line) {
    std::string temp_string = "UNKNOWN \'";
    temp_string += cause;
    temp_string += "\'";
    Error err;
    err.level = type;
    err.cause = temp_string;
    err.line = line;
    errors.push_back(err);
  }

  void PrintErrors() {
    int i = 0;
    for (auto &error : errors) {
      i++;
      std::cout << "\nERROR #" << i << ":\n";
      std::cout << error.cause << "\n";
      std::cout << "ERROR TYPE: " << error_strings.at(error.level) << "; \n";
      std::cout << "LINE: " << error.line+1 << "\n";
    }
    std::cout << "\n";
  }
private:
  std::vector<Error> errors;
};
