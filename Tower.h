#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Tower:public Entity, public sf::Sprite{
private:
  int range;
public:
  Tower();
  Tower(int);
};
