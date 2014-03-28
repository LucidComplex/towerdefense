#include "mySprite.h"

mySprite::mySprite(){
  source.x=0;
  source.y=0;
  //sprite
  setPosition(140.f, 200.f);
  set_source(0, idle);
  //set rectangle window
  setTextureRect(sf::IntRect(source.x*SPRITE_SIZE[width], source.y*SPRITE_SIZE[height],
                                    SPRITE_SIZE[width], SPRITE_SIZE[height]));
}

void mySprite::set_source(int x, int y){
  source.x=x;
  source.y=y;
}

void mySprite::set_stance(int stance){
  set_source(0, stance);
}
