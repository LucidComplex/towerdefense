#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "mySprite.h"
#include "env.h"

class Creep:public Entity, public mySprite{
private:
  static sf::Image creepnormal;
  static sf::Image creepcold;
  static sf::Image creeppoison;
  int status;
  int texture;
  sf::Vector2i current;
  void initImages();
public:
  int speed;
  int id;
  void changeStatus(int);
  int get_status();
  int get_texture();
  void setSprite(int);
  Creep();
  Creep(int, int, int, int, sf::Vector2i);
//  void move();
};
