#include "Towers.h"

Towers::Towers(){
  towerquantity=0;
}

void Towers::add_tower(int type){
  sf::Vector2f pos(0, 6);
  Tower add(type, towerquantity++, pos);
  push_back(add);
}

void Towers::remove_tower(Tower &x){

  unsigned int eraseid=x.id;
  //move id numbers to fill in killed creep before erase
  erase(begin()+eraseid);  //"kill" creep
  unsigned int i=eraseid+1;
  while(i<size()){
    at(i).id--;
    i++;
  }
}
