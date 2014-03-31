#include "Maze.h"

Maze::Maze(){
  int i, j;
  for(i=0; i<WINDOW_X/SPRITE_SIZE[width]; i++)
    for(j=0; j<WINDOW_Y/SPRITE_SIZE[height]; j++)
      boundary[i][j]=true;
  setMaze();
}


void Maze::setMaze(){
  int i;
  boundary[0][2]=false;
  for(i=2; i>0; i--)
    boundary[1][i]=false;
  boundary[2][1]=false;
  for(i=1; i<7; i++)
    boundary[3][i]=false;
  boundary[4][6]=false;
  for(i=6; i>2; i--)
    boundary[5][i]=false;
  for(i=6; i<11; i++)
    boundary[i][3]=false;
  for(i=2; i>0; i--)
    boundary[10][i]=false;
  for(i=11; i<13; i++)
    boundary[i][1]=false;
}
