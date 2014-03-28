#include "Maze.h"

Maze::Maze(){
  int i, j;
  for(i=0; i<WINDOW_X/SPRITE_SIZE[width]; i++){
    for(j=0; j<WINDOW_Y/SPRITE_SIZE[height]; j++)
      boundary[i][j]=true;
  }
}
