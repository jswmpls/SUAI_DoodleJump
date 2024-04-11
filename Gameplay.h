#pragma once

#include "PLayer.h" 
#include "Platforms.h"
#include "Score.h"

#include <SFML/Graphics.hpp>

//Вызывается при поржении 
void loser(RenderWindow& window, Player& player, Score& score);