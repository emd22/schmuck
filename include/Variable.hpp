#pragma once
#include <string>
#include "Line.hpp"

enum VariableType {
  TYPE_INT,
  TYPE_STRING
};

struct Variable {
  char name = '?';
  int i_value = 0;
  std::string s_value = "EMPTY";
  VariableType type;
};

class VariableList {
public:
  void new_variable(char name, VariableType var_type, int i_value = 0, std::string s_value = "E") {
    Variable vars;
    if (var_type == TYPE_STRING) {
      vars.name = name;
      vars.s_value = s_value;
      vars.type = TYPE_STRING;
      variables.push_back(vars);
    } else if (var_type == TYPE_INT) {
      vars.name = name;
      vars.i_value = i_value;
      vars.type = TYPE_INT;
      variables.push_back(vars);
    }
  }

  int GetVariableIndex(char name)
  {
    int var_index = -1;
    for (int i = 0; i < variables.size(); i++) {
      if (variables[i].name == name) {
        var_index = i;
        break;
      }
    }
    return var_index;
  }

  Variable &GetVariable(int index)
  {
    return variables.at(index);
  }

  void PrintVariables() {
    for (auto &var : variables) {
      if (var.type == TYPE_INT) {
        std::cout << "VARIABLE: " << var.name << "; VALUE: " << var.i_value << "\n";
      } else if (var.type == TYPE_STRING) {
        std::cout << "VARIABLE: " << var.name << "; VALUE: " << var.s_value << "\n";
      } else {
        std::cout << "Something went wrong :/ - type: " << var.type << "\n";
      }
    }
  }
private:
  std::vector<Variable> variables;
};
