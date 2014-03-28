#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(){
  setGrid(1, 1);

  //set path
  int i;
  maze.boundary[0][2]=false;
  for(i=2; i>0; i--)
    maze.boundary[1][i]=false;
  maze.boundary[2][1]=false;
  for(i=1; i<7; i++)
    maze.boundary[3][i]=false;
  maze.boundary[4][6]=false;
  for(i=6; i>2; i--)
    maze.boundary[5][i]=false;
  for(i=6; i<11; i++)
    maze.boundary[i][3]=false;
  for(i=2; i>0; i--)
    maze.boundary[10][i]=false;
  for(i=11; i<13; i++)
    maze.boundary[i][1]=false;

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
        grid[i][j].setFillColor(sf::Color::Green);
      else
        grid[i][j].setFillColor(sf::Color::Red);
      grid[i][j].setOrigin(-0.5-(i*SPRITE_SIZE[width]), -0.5-(j*SPRITE_SIZE[height]));
    }
  }
}
