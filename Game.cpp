#include "Game.h"
#include <iostream>

Game::Game(){
  ///init game vars

  //load font
  if(!font.loadFromFile("fonts/sansation.ttf"))
    return;

  //temp play button
  __play.setFont(font);
  __play.setCharacterSize(30);
  __play.setPosition(360.f, 210.f);
  __play.setColor(sf::Color::Black);
  __play.setString("PLAY");

  //set background
  setSprite(bg, "image/background.png");

  //start screen bg
  setSprite(bgstartscreen, "image/startscreen.png");

  //grid
  grid.setGrid(WINDOW_X, WINDOW_Y);

  //play button
  if(!image.loadFromFile("image/play.png"))
    return;
  texture.loadFromImage(image);
  playbtn.setTexture(texture);
  playbtn.setPosition(140.f, 200.f);

  //title sprite
  titlesprite.setTexture(texture);
  titlesprite.setPosition(780.f, 385.f);
  titlesprite.source.x=0;
  titlesprite.source.y=0;

  ///set rectangle window
  //title sprite
  titlesprite.setTextureRect(sf::IntRect(titlesprite.source.x*SPRITE_SIZE[width], titlesprite.source.y*SPRITE_SIZE[height], SPRITE_SIZE[width], SPRITE_SIZE[height]));

  //for animation
  framecounter=0;
  keyframe=100;
  framespeed=500;

}

void Game::update(){
  //update vars for animation

  framecounter+=framespeed*clock.restart().asSeconds();
  if(framecounter>=keyframe){
    framecounter=0;

    updateSprites(titlesprite, 4);
  }
}

void Game::start(){
  window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Tower Defense");
  while(gameLoop());
  window.close();
}

bool Game::gameLoop(){
  ///main game loop

  update();
  if(!readEvents())
    return false;
  display();

  return true;
}

bool Game::readEvents(){
  ///reads events, returns false if program is exited
  sf::Event event;
  while(window.pollEvent(event)){

    //close event
    if(event.type==sf::Event::Closed){
      playing=false;
      return false;  //exit game loop
    }

    //start game event
    if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Space)
      playing=true;
    //pause event
    if(event.type==sf::Event::MouseLeft)
      playing=false;

    /*
    if(event.type==sf::Event::MouseMoved &&
       ((event.mouseMove.x>338 && event.mouseMove.x<530) &&
        (event.mouseMove.y>210 && event.mouseMove.y<240) &&
        playing)){

    }
    */

    //play button
    sf::Vector2i mousecoords=sf::Mouse::getPosition(window);
    if(event.type==sf::Event::MouseButtonPressed &&
       ((mousecoords.x>338 && mousecoords.x<530) &&
        (mousecoords.y>210 && mousecoords.y<240)) &&
       !playing)
      playing=true;

    std::cout<<std::endl<<"X: "<<sf::Mouse::getPosition(window).x<<" "<<"Y: "<<sf::Mouse::getPosition(window).y;
    //std::cout<<std::endl<<
  }
  return true;
}

void Game::display(){
  ///draw stuff to buffer and display

  window.clear(sf::Color::Black);
  if(playing){
    window.draw(bg);

    //draw grid
    for(int i=0; i<WINDOW_X/SPRITE_SIZE[width]; i++){
      for(int j=0; j<WINDOW_Y/SPRITE_SIZE[height]; j++)
        window.draw(grid.grid[i][j]);
    }

  }
  else{
    window.draw(bgstartscreen);

    //draw test
    window.draw(titlesprite);
    window.draw(__play);

  }
  window.display();
}

void Game::updateSprites(mySprite &sprite, int end_){
  ///update sprite, animates it
  sprite.source.x++;
  if(sprite.source.x*SPRITE_SIZE[width]>=SPRITE_SIZE[width]*end_)
    sprite.source.x=0;
  sprite.setTextureRect(sf::IntRect(titlesprite.source.x*SPRITE_SIZE[width], titlesprite.source.y*SPRITE_SIZE[height],
                            SPRITE_SIZE[width], SPRITE_SIZE[height]));
}

void Game::setSprite(sf::Sprite &sprite, char *filename){
  sf::Image image;
  sf::Texture *texture=new sf::Texture;
  if(!image.loadFromFile(filename))
    throw "Can not read file.";
  texture->loadFromImage(image);
  sprite.setTexture(*texture);
  allocatedtextures.push_back(texture);
}

Game::~Game(){
  while(allocatedtextures.size()){
    delete allocatedtextures[0];
    allocatedtextures.erase(allocatedtextures.begin());
  }
}
