#include "Creep.h"
#include "env.h"

Creep::Creep(){
  speed=4;
  id=0;
  hp=10;
  gold=3;
  dmg=1;

}

Creep::Creep(int h, int g, int d, int i, int s){
  hp=h;
  gold=g;
  dmg=d;
  id=i;
  speed=s;
}
