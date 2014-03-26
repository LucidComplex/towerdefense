#pragma once
#include <vector>
#include "Tower.h"

class Towers:public std::vector<Tower>{
public:
  void add_tower();
  void add_tower(int);
};
