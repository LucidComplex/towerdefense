#include "Entity.h"

int Entity::get_gold(){
  return gold;
}
int Entity::get_hp(){
  return hp;
}
int Entity::get_dmg(){
  return dmg;
}
void Entity::attack(Entity &x){
  x.hp-=dmg;
}
