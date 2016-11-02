#pragma once
#include "Error.hpp"
#include "Variable.hpp"
#include "Lists.hpp"

ErrorList error_list;

class Parse {
public:
  void ParseIntDecl(std::string line) {
    if (line[1] == '^') {
      if (line[3] == '!') {
        variable_list.new_variable(line[2], TYPE_INT, std::stoi(line.substr(4, 1)));
      } else if (line[3] == '@') {
        variable_list.new_variable(line[2], TYPE_INT, std::stoi(line.substr(4, 2)));
      } else {
        variable_list.new_variable(line[2], TYPE_INT, 0);
      }
    } else {
      error_list.send_error(line[1], SYNTAX_ERROR, current_line);
    }
  }

  void ParseStrDecl(std::string line) {
    if (line[1] == '^') {
      int at = 4;
      std::string inner = "";
      while (line[at] != '~') {
        inner += line[at];
        at++;
      }
      variable_list.new_variable(line[2], TYPE_STRING, 0, inner);
    } else {
      error_list.send_error(line[1], SYNTAX_ERROR, current_line);
    }
  }
};
Parse parser;
