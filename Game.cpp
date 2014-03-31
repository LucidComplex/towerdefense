#include <iostream>
#include "Game.h"

Game::Game(){
  ///init game vars

  //load font
  if(!font.loadFromFile("fonts/sansation.ttf"))
    return;

  //gold display
  playergold.setFont(font);
  playergold.setCharacterSize(30);
  playergold.setPosition(500.f, 20.f);

  //set background
  bg.setImage("image/background.png");

  //start screen bg
  bgstartscreen.setImage("image/startscreen.png");

  //title sprite
  titlesprite.setSprite("image/play.png");
  titlesprite.setPosition(780.f, 385.f);
  titlesprite.set_source(0, 0);

  //for animation
  framecounter=0;
  keyframe=70;
  framespeed=500;
  creepspawndelay=0;

  //play button
  playbutton.setSprite("image/playbutton.png");
  playbutton.setPosition(338.f, 210.f);
  playbutton.setTextureRect(sf::IntRect(0, 0, 140, 80));

  //portal
  portal.setSprite("image/Portal.png");
  portal.setPosition(12*SPRITE_SIZE[width], 2*SPRITE_SIZE[height]); //set position to correct place

  towers.add_tower(normal);
  buildmode=true;
}

void Game::update(){
  //update vars for animation

  //count frame
  framecounter+=framespeed*clock.restart().asSeconds();


  //for smooth motion
  if(playing && framecounter>=50){
    unsigned int i=0;
    while(i<wave.size())
      wave.at(i++).move(1, 0);
  }

  if(framecounter>=keyframe){
    framecounter=0;
    updateSprites(titlesprite, 4);

    //spawn creeps only when playing or game started
    if(playing){
      creepspawndelay++;
      if(creepspawndelay==7){
        creepspawndelay=0;
        wave.spawn_creep();
      }
      player.gain_gold(wave.creep_sanity_check());  //checks creeps if dead or alive and gives player gold on kill
    }

    unsigned int i=0;
    while(i<wave.size()){
      updateSprites(wave.at(i++), 4);
    }
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
    sf::Vector2i mousecoords=sf::Mouse::getPosition(window);  //store mouse coordinates

    //close event
    if(event.type==sf::Event::Closed){
      playing=false;
      return false;  //exit game loop
    }

    /*
    if(event.type==sf::Event::MouseMoved &&
       ((event.mouseMove.x>338 && event.mouseMove.x<530) &&
        (event.mouseMove.y>210 && event.mouseMove.y<240) &&
        playing)){

    }
    */

    //play button
    if(((mousecoords.x>352 && mousecoords.x<474) && (mousecoords.y>238 && mousecoords.y<290)) && !playing){
      if(event.type==sf::Event::MouseButtonPressed)
        playing=true;
    }

    //start wave



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
    if(buildmode)
      window.draw(grid);

    window.draw(wave);
    window.draw(portal);
    window.draw(playergold);
    //window.draw(towers[0].rangecircle);
    //window.draw(towers[0]);

  }
  else{
    window.draw(bgstartscreen);

    //draw bottom corner sprite
    window.draw(titlesprite);
    //draw play button
    window.draw(playbutton);

  }
  window.display();
}

void Game::updateSprites(mySprite &sprite, int end_){
  ///update sprite, animates it
  sprite.source.x++;
  if(sprite.source.x*SPRITE_SIZE[width]>=SPRITE_SIZE[width]*end_)
    sprite.source.x=0;
  sprite.setTextureRect(sf::IntRect(sprite.source.x*SPRITE_SIZE[width], sprite.source.y*SPRITE_SIZE[height],
                            SPRITE_SIZE[width], SPRITE_SIZE[height]));
}
