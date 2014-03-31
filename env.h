#pragma once
#include <SFML/Graphics.hpp>

enum coords{width, height};
enum anim{idle, move_, attack, die};
enum types{normal, slow, poison};

const extern float WINDOW_X;
const extern float WINDOW_Y;
const extern float SPRITE_SIZE[2];
const extern unsigned int WAVE_SIZE;
