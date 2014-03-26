#pragma once
#include "Entity.h"

class Player:public Entity{
public:
  Player();
  Player(int, int);
  void gain_gold(int);
  bool spend_gold(int);
};
