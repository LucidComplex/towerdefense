#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Wave.h"
#include "Towers.h"
#include "Grid.h"
#include "mySprite.h"
#include "env.h"  //global vars

class Game{
private:
  bool gameLoop();
  bool playing;

  //sfml window
  sf::RenderWindow window;

  //sfml text
  sf::Font font;
  sf::Text __play;

  //entities
  Player player;
  Wave wave;
  Towers towers;

  //sprites
  mySprite titlesprite;

  //image elements
  sf::Image image;
  sf::Texture texture;

  //background elements
  sf::Sprite bg;

  //start screen bg
  sf::Sprite bgstartscreen;

  //play button
  sf::Sprite playbtn;

  //grid
  Grid grid;

  //for animation
  sf::Clock clock;
  float framecounter;
  float keyframe;
  float framespeed;

  //game functions
  void update();
  bool readEvents();
  void display();
  void updateSprites(mySprite &, int);
  void setSprite(sf::Sprite &, char *);

  std::vector<sf::Texture *> allocatedtextures;

public:
  Game();
  ~Game();
  void start();
};
