#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wave.h"
#include "Towers.h"
#include "Grid.h"
#include "env.h"  //global vars

class Game{
private:
  bool gameLoop();
  bool playing;

  //sfml window
  sf::RenderWindow window;

  //sfml text
  sf::Font font;
  sf::Text startscreen;

  //entities
  Player player;
  Wave wave;
  Towers towers;

  //background elements
  sf::Image bgfile;
  sf::Texture bgtexture;
  sf::Sprite bg;

  //grid
  Grid grid;

  bool readEvents();
  void display();

public:
  Game();
  void start();
};
