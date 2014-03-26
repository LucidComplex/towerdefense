#include "Player.h"

Player::Player(){
  gold=40;
  hp=30;
}

Player::Player(int g, int h){
  gold=g;
  hp=h;
}

void Player::gain_gold(int g){
  gold+=g;
}

bool Player::spend_gold(int g){
  if(gold-g<0)
    return false;
  gold-=g;
  return true;
}
