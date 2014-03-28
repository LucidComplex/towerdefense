#include "Towers.h"

Towers::Towers(){
  towerquantity=0;
}

void Towers::add_tower(int type){
  Tower add(type, towerquantity++);
  push_back(add);
}
