#pragma once
#include <string>

struct Goto {
    char name = '?';
    int line = 0;
};

class GotoList {
public:
  void new_goto(char name, int line) {
    Goto go_to;
    go_to.name = name;
    go_to.line = line;
    _gotos.push_back(go_to);
  }
  int GetGotoIndex(char name)
  {
    int goto_index = -1;
    for (int i = 0; i < _gotos.size(); i++) {
      if (_gotos[i].name == name) {
        goto_index = i;
        break;
      }
    }
    return goto_index;
  }

  Goto &GetGoto(int index)
  {
    return _gotos.at(index);
  }

private:
  std::vector<Goto> _gotos;
};
