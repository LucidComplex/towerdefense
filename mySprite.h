#pragma once
#include <SFML/Graphics.hpp>
#include "env.h"

class mySprite:public sf::Sprite{
public:
  mySprite();
  sf::Vector2i source;

  //methods
  void set_source(int, int);
  void set_stance(int);
  int end_;
  void setSprite(const std::string &);
};
