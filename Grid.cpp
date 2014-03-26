#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(){
  setGrid(1, 1);
}

Grid::Grid(float x, float y){
  setGrid(x, y);
}

void Grid::setGrid(float x, float y){
  int i, j;
  x/=SPRITE_SIZE[width];
  y/=SPRITE_SIZE[height];
  //sets every "box" of grid
  sf::Vector2f gridsize(SPRITE_SIZE[width], SPRITE_SIZE[height]);
  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
      grid[i][j].setSize(gridsize);
      grid[i][j].setOutlineThickness(0.5f);
      grid[i][j].setOutlineColor(sf::Color::Black);
      grid[i][j].setFillColor(sf::Color::Transparent);
      grid[i][j].setOrigin(-0.5-(i*SPRITE_SIZE[width]), -0.5-(j*SPRITE_SIZE[height]));
    }
  }
}
