#include <iostream>
#include "Wave.h"
#include "env.h"

bool Wave::populate_wave(){
  ///populates wave ONLY when wave is cleared
  ///returns true if successful populate, else false
  if(size()>0)
    return false;
  else{
    int i=0;
    std::cout<<std::endl<<"New wave!"<<std::endl;
    while(i<WAVE_SIZE){
      Creep x;  //add some modifiers here later
      push_back(x);
      i++;
    }
  }
  return true;
}

void Wave::kill(Creep &x){

  unsigned int eraseid=x.id;
  //move id numbers to fill in killed creep before erase
  erase(begin()+eraseid);  //"kill" creep
  unsigned int i=eraseid+1;
  while(i<size()){
    at(i).id--;
    i++;
  }

  std::cout<<std::endl<<"Creep kill!"<<std::endl;
}

void Wave::creep_health_check(){
 ///checks every creep in vector for dead creeps
 ///if dead creep is found, remove from vector

  unsigned int i=0;
  while(i<size()){
    Creep &checkcreep=at(i);
    if(checkcreep.get_hp()<=0){
//      player.gain_gold(checkcreep.get_gold());
      kill(checkcreep);
      std::cout<<std::endl<<size();
    }
    i++;
  }
}

Wave::Wave(){
  populate_wave();
}
