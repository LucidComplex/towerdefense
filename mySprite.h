#pragma once
#include <SFML/Graphics.hpp>
#include "env.h"

class mySprite:public sf::Sprite{
public:
  sf::Vector2i source;
  mySprite();

  //methods
  void set_source(int, int);
  void set_stance(int);
  int end_;
};
