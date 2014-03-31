#include <iostream>
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include "env.h"

bool Wave::spawn_creep(){
  ///spawns a creep ONLY when wave is not WAVE_SIZE
  ///returns true if successful spawn, else false
  if(size()==WAVE_SIZE)
    return false;
  else{
    std::cout<<std::endl<<"Creep spawned!"<<std::endl;
    int hp=10, gold=3, speed=2;
    sf::Vector2i start(0, 2);
    Creep x(hp, gold, size(), speed, start);  //add some modifiers here later
    push_back(x);
  }
  return true;
}

void Wave::kill(Creep &x){

  unsigned int eraseid=x.id;
  //move id numbers to fill in killed creep before erase
  delete x.getTexture();  //free allocated texture
  erase(begin()+eraseid);  //"kill" creep
  unsigned int i=eraseid+1;
  while(i<size()){
    at(i).id--;
    i++;
  }
}

int Wave::creep_sanity_check(){
 ///checks every creep in vector for dead creeps
 ///if dead creep is found, remove from vector
 ///also updates their skin according to status
 ///returns amount of gold earned

  unsigned int i=0;
  int gain=0;
  while(i<size()){
    Creep &checkcreep=at(i);
    if(checkcreep.get_hp()<=0){
      gain+=checkcreep.get_gold();
      kill(checkcreep);
      std::cout<<std::endl<<size();
    }

    //checks if status is the same to save resources
    if(checkcreep.get_status()==slow && checkcreep.get_texture()!=slow){
      checkcreep.setSprite(slow);
      checkcreep.speed-=0.5*checkcreep.speed;
    }
    else if(checkcreep.get_status()==poison && checkcreep.get_texture()!=poison)
      checkcreep.setSprite(poison);
    else if(checkcreep.get_status()==normal && checkcreep.get_texture()!=normal)
      checkcreep.setSprite(normal);

    i++;
  }
  return gain;
}

void Wave::draw(sf::RenderTarget &target, sf::RenderStates state) const{
  unsigned int i=0;
  while(i<size()){
    target.draw(at(i++));
  }
}
