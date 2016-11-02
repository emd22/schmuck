#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "../include/Error.hpp"
#include "../include/Variable.hpp"
#include "../include/Parser.hpp"

int main() {
  while (std::getline(file, line)) {
    if (line[0] == 'i') {
      parser.ParseIntDecl(line);
    } else if (line[0] == 's') {
      parser.ParseStrDecl(line);
    } else if (line[0] == 'E') {
      break;
    } else if (line[0] == 'p') {
      if (line[1] == '^') {
        int var_index = variable_list.GetVariableIndex(line[2]);
        if (var_index == -1) {
          error_list.send_error(line[2], DEFINE_ERROR, current_line, "UNKNOWN VARIABLE");
        } else {
          Variable &var = variable_list.GetVariable(var_index);
          if (var.type == TYPE_STRING) {
            std::cout << var.s_value << "\n";
          } else if (var.type == TYPE_INT) {
            std::cout << var.i_value << "\n";
          }
        }
      } else if (line[1] == '~') {
          int at = 2;
          std::string inner = "";
          while (line[at] != '~') {
            inner += line[at];
            at++;
          }
          std::cout << inner << "\n";
      } else {
        error_list.send_error(line[1], SYNTAX_ERROR, current_line);
      }
    } else {
      error_list.send_error(line[0], SYNTAX_ERROR, current_line);
    }
    if (line.back() != '.') {
      error_list.send_error(line.back(), SYNTAX_ERROR, current_line, "UNEXPECTED END OF LINE");
      break;
    }
    current_line++;
  }
    error_list.PrintErrors();
    variable_list.PrintVariables();

    std::cout << "HIT END; STOPPING\n";
}
