#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Wave.h"
#include "Towers.h"
#include "Grid.h"
#include "mySprite.h"
#include "myImage.h"
#include "myString.h"
#include "env.h"  //global vars

class Game{
private:
  bool gameLoop();

  bool playing;
  bool wavestart;
  bool buildmode;

  //sfml window
  sf::RenderWindow window;

  //sfml text
  sf::Font font;

  //entities
  Player player;
  Wave wave;
  Towers towers;

  //title sprite
  mySprite titlesprite;

  //money text
  sf::Text playergold;

  //image elements
  sf::Image image;
  sf::Texture texture;

  //background elements
  myImage bg;

  //start screen bg
  myImage bgstartscreen;

  //grid
  Grid grid;

  //play button
  mySprite playbutton;

  //portal
  mySprite portal;

  //for animation
  sf::Clock clock;
  float framecounter;
  float keyframe;
  float framespeed;

  //for creep
  int creepspawndelay;

  //game functions
  void update();
  bool readEvents();
  void display();
  void updateSprites(mySprite &, int);

public:
  Game();
  void start();
};
