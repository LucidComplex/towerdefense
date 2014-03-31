#include "Creep.h"
#include "env.h"

Creep::Creep(){
  speed=4;
  id=0;
  hp=10;
  gold=3;
  dmg=1;
  status=normal;
  current.x=0;
  current.y=0;
}

Creep::Creep(int h, int g, int i, int s, sf::Vector2i start){
  hp=h;
  gold=g;
  dmg=1;
  id=i;
  speed=s;
  status=texture=normal;
  current.x=start.x;
  current.y=start.y;
  setPosition(sf::Vector2f(current.x*SPRITE_SIZE[width], current.y*SPRITE_SIZE[height]));
  creepnormal.loadFromFile("image/creepsprites.png");
  creepcold.loadFromFile("image/creepspritescold.png");
  creeppoison.loadFromFile("image/creepspritespoison.png");
  setSprite(normal);
};
/*
void Creep::changeStatus(int type){
  if(type==normal)
    sf::Sprite::setTexture(Creep::creepnormal);
}
*/
int Creep::get_status(){
  return status;
}

int Creep::get_texture(){
  return texture;
}

void Creep::setSprite(int type){
  sf::Texture *texture=new sf::Texture;
  texture->loadFromImage(creepnormal);
  if(type==normal){
    setTexture(*texture);
  }
  else if(type==slow)
    setTexture(*texture);
  else if(type==poison)
    setTexture(*texture);
}

sf::Image Creep::creepnormal;
sf::Image Creep::creepcold;
sf::Image Creep::creeppoison;
