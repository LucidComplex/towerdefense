#pragma once
#include <vector>
#include "Creep.h"
#include "Towers.h" //for remove vector
#include <SFML/Graphics.hpp>

class Wave:public std::vector<Creep>, public sf::Drawable{
public:
  bool spawn_creep();
  int creep_sanity_check();
  void kill(Creep &);
  virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};
