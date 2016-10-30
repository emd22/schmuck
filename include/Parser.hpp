#pragma once
#include "Error.hpp"
#include "Variable.hpp"

ErrorList error_list;
VariableList variable_list;

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
      if (line[3] == '!') {
        variable_list.new_variable(line[2], TYPE_STRING, 0, line.substr(4, 1));
      } else if (line[3] == '@') {
        if (line[4] == '!') {
          int temp_length = line[5] - '0';
          if (line[6] == ':') {
            variable_list.new_variable(line[2], TYPE_STRING, 0, line.substr(7, temp_length));
          }
        } else if (line[4] == '@') {
          int temp_length = std::stoi(line.substr(5, 2));
          if (line[7] == ':') {
            variable_list.new_variable(line[2], TYPE_STRING, 0, line.substr(8, temp_length));
          } else {
            error_list.send_error(line[7], SYNTAX_ERROR, current_line);
          }
        }
      } else {
        variable_list.new_variable(line[2], TYPE_STRING, 0, "EMPTY");
      }
    } else {
      error_list.send_error(line[1], SYNTAX_ERROR, current_line);
    }
  }
};

Parse parser;
