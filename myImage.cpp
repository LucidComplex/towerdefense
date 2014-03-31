#include <memory>
#include "myImage.h"

void myImage::setImage(std::string filename){
  sf::Image image;
  sf::Texture *texture=new sf::Texture;
  currentImage=filename;  //store image filename to string useful in creep_sanity_check()
  if(!image.loadFromFile(filename))
    throw;
  texture->loadFromImage(image);
  setTexture(*texture);
}
