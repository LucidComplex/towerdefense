#pragma once
#include <vector>
#include "Creep.h"
#include <SFML/Graphics.hpp>

class Wave:public std::vector<Creep>{
public:
  bool populate_wave();
  void creep_health_check();
  void kill(Creep &);
  Wave();
};
