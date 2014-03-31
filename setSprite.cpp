#include "Game.h"

void Game::setSprite(sf::Sprite &sprite, std::string filename){
  sf::Image image;
  sf::Texture *texture=new sf::Texture;
  if(!image.loadFromFile(filename))
    throw "Can not read file.";
  texture->loadFromImage(image);
  sprite.setTexture(*texture);
  allocatedtextures.push_back(texture);
}
