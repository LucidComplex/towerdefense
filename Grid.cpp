#include "Grid.h"
#include "env.h"

Grid::Grid(){
  setGrid(WINDOW_X, WINDOW_Y);
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
      grid[i][j].setOutlineThickness(1.f);
      grid[i][j].setOutlineColor(sf::Color::Black);
      if(!maze.boundary[i][j])
        grid[i][j].setFillColor(sf::Color(0, 255, 0, 100));
      else
        grid[i][j].setFillColor(sf::Color(255, 0, 0, 100));
      grid[i][j].setOrigin(-0.5-(i*SPRITE_SIZE[width]), -0.5-(j*SPRITE_SIZE[height]));
    }
  }
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const{
  for(int i=0; i<WINDOW_X/SPRITE_SIZE[width]; i++){
    for(int j=0; j<WINDOW_Y/SPRITE_SIZE[height]; j++)
      target.draw(grid[i][j]);
  }
}
