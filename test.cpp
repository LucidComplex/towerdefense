#include "Wave.h"
#include "Towers.h"

int main(){
  Wave wave;
  wave.populate_wave();
  Towers towers;
  towers.add_tower();
  towers[0].attack(wave[0]);
}
