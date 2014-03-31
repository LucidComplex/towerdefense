#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "env.h"

class myImage:public sf::Sprite{
public:
  std::string currentImage;
  void setImage(std::string);
};
