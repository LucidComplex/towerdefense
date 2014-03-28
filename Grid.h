#pragma once
#include <SFML/Graphics.hpp>
#include "env.h"  //global vars
#include "Maze.h"

class Grid{
public:
  sf::RectangleShape grid[30][30];
  void setGrid(float, float);
  Grid();
  Grid(float, float);
  Maze maze;
};
