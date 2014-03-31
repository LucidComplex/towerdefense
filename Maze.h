#pragma once
#include "env.h"

class Maze{
private:
  void setMaze();
public:
  Maze();
  bool boundary[30][30];
};
