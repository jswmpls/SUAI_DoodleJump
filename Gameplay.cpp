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

void playing(RenderWindow& window, Player& player, Score& score, Platforms& platforms)
{
	const int heightBack = 700;
	const int widthBack = 700;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //Время 
		time /= 800;
		clock.restart();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Закрытие окна
				window.close();
		}

		window.setView(View(FloatRect(0, player.y - heightBack / 2, widthBack, heightBack))); //Камера
		window.clear(Color::Cyan); //Фон
		player.move(time); //Движения персонажа 
		window.draw(player.sprite); //Персонаж 
		platforms.update(player, window, score); //Платформы 
		window.draw(score.scoreText); // Счёт
		score.scoreText.setPosition(10, player.y - 350);
		window.display();
	}
}