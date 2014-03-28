#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "mySprite.h"
#include "Maze.h"

class Creep:public Entity, public sf::Sprite{
public:
  int speed;
  int id;
  Creep();
  Creep(int, int, int, int, int);
  mySprite creepsprite;

};
