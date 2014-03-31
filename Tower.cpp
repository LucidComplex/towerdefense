#include "Tower.h"

Tower::Tower(int type, int towerid, sf::Vector2f pos){
  if(type==normal){
    dmg=4;
    range=100;
    attackspeed=3;
    gold=10;
  }
  else if(type==poison){
    dmg=4;
    range=60;
    attackspeed=2;
    gold=16;
  }
  else if(type==slow){
    dmg=2;
    range=100;
    attackspeed=3;
    gold=15;
  }
  id=towerid;
  rangecircle.setRadius(range);
  rangecircle.setPosition(0, 0);
  setSprite("image/tower_normal.png");
  setPosition(pos);
}

void Tower::upgrade(){
  dmg+=1.5*dmg;
  range+=0.5*range;
  attackspeed+=attackspeed;
  gold+=1.1*gold;
}
