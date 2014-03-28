#pragma once
#include <vector>
#include "Tower.h"

class Towers:public std::vector<Tower>{
public:
  Towers();
  void add_tower(int);
  void remove_tower();
  int towerquantity;
};
