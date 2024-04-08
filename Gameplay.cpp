#include "Gameplay.h"

void loser(RenderWindow& window, Player& player, Score& score)
{
	//Останавливаем движения персонажа
	player.gravity = 0;
	player.speed = 0;

	//Загружаем фон
	Font font;
	font.loadFromFile("Image/PIXY.ttf");

	Text control, recordText;

	//Текст управления
	control.setFont(font);
	control.setCharacterSize(26);
	control.setFillColor(Color::Black);
	control.setString("Control: \n ESC - exit");
	control.setPosition(10, player.y + 270);

	//Рекорд
	recordText.setFont(font);
	recordText.setCharacterSize(32);
	recordText.setFillColor(Color::Black);
	recordText.setString("Record: " + to_string(score.getRecord()));
	recordText.setPosition(270, player.y + 100);

	Texture dopLoseTexture;
	dopLoseTexture.loadFromFile("Image/fonReplay.png");
	Sprite dopLoseSprite(dopLoseTexture);

	dopLoseSprite.setPosition(150, player.y - 330);

	window.clear(Color::Cyan);
	window.draw(dopLoseSprite);
	window.draw(control);
	window.draw(recordText);
}