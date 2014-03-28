#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "env.h"

class Tower:public Entity, public sf::Sprite{
private:
  int range;
  int attspeed;
  int id;
public:
  Tower();
  Tower(int, int);
};
