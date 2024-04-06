#include "Gameplay.h"

void loser(RenderWindow& window, Player& player, Score& score)
{
	player.gravity = 0;
	player.jumpSpeed = 0;
	player.speed = 0;

	Font font;
	font.loadFromFile("Image/PIXY.ttf");

	Text control;
	control.setFont(font);
	control.setCharacterSize(26);
	control.setFillColor(sf::Color::Black);
	control.setString("Control: \n ESC - exit");

	Texture dopLoseTexture;
	dopLoseTexture.loadFromFile("Image/fonReplay.png");
	Sprite dopLoseSprite(dopLoseTexture);

	dopLoseSprite.setPosition(150, player.y - 330);
	control.setPosition(10, player.y + 250);

	window.clear(Color::Cyan);
	window.draw(dopLoseSprite);
	window.draw(control);
}