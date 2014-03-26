#include <SFML/Graphics.hpp>
#include "env.h"  //global vars

class Grid{
public:
  sf::RectangleShape grid[30][30];
  void setGrid(float, float);
  Grid();
  Grid(float, float);
};
