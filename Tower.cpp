#include "Tower.h"

Tower::Tower(int type, int towerid){
  if(type==normal){
    dmg=4;
    range=5;
    attspeed=3;
    gold=10;
  }
  else if(type==poison){
    dmg=4;
    range=3;
    attspeed=2;
    gold=16;
  }
  else if(type==slow){
    dmg=2;
    range=5;
    attspeed=3;
    gold=15;
  }
  id=towerid;
}
