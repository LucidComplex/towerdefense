#include "Game.h"
#include <iostream>

Game::Game(){
  ///init game vars

  //load font
  if(!font.loadFromFile("fonts/sansation.ttf"))
    return;

  //set startscreen
  startscreen.setFont(font);
  startscreen.setCharacterSize(30);
  startscreen.setPosition(200.f, 150.f);
  startscreen.setColor(sf::Color::White);
  startscreen.setString("Tower Defense");

  //set background
  if(!bgfile.loadFromFile("image/background.png")){
     return;
  }
  bgtexture.loadFromImage(bgfile);
  bg.setTexture(bgtexture);

  //grid
  grid.setGrid(WINDOW_X, WINDOW_Y);
}

void Game::start(){
  window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "Tower Defense");
  while(gameLoop());
  window.close();
}

bool Game::gameLoop(){
  ///main game loop

  if(!readEvents())
    return false;
  display();

  return true;
}

bool Game::readEvents(){
  ///reads events, returns false if program is exited
  sf::Event event;
  while(window.pollEvent(event)){
    if(event.type==sf::Event::Closed){
      playing=false;
      return false;  //exit game loop
    }
    if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Space)
      playing=true;
  }
  return true;
}

void Game::display(){
  ///draw stuff to buffer and display

  window.clear(sf::Color::Black);
  if(playing){
    window.draw(bg);
    for(int i=0; i<WINDOW_X/SPRITE_SIZE[width]; i++){
      for(int j=0; j<WINDOW_Y/SPRITE_SIZE[height]; j++)
        window.draw(grid.grid[i][j]);
    }
  }
  else{
    window.draw(startscreen);
  }
  window.display();
}
