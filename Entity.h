#pragma once

class Entity{
protected:
  int gold;
  int hp;
  int dmg;
public:
  int get_gold();
  int get_hp();
  int get_dmg();
  void attack(Entity &);
};
