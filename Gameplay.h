#pragma once

#include "PLayer.h" 
#include "Platforms.h"
#include "Score.h"

#include <SFML/Graphics.hpp>

//���������� ��� �������� 
void loser(RenderWindow& window, Player& player, Score& score);

void playing(RenderWindow& window, Player& player, Score& score, Platforms& platforms);