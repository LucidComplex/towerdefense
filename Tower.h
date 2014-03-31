#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "mySprite.h"
#include "env.h"

class Tower:public Entity, public mySprite{
private:
  int range;
  int attackspeed;
public:
  Tower();
  Tower(int, int, sf::Vector2f);
  int id;
  void get_range();
  void get_attackspeed();
  void upgrade();
  sf::CircleShape rangecircle;
};
