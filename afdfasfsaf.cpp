#include "Gameplay.h"

using namespace sf;
using namespace std;

int main()
{
    const int heightBack = 700;
    const int widthBack = 700;

    RenderWindow window(sf::VideoMode(widthBack, heightBack), "SFML works!"); 

    Player player(200, 500, "Image/pers.png");
    Platforms platforms(200, 600, "Image/platformMin.png");
    Score score;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); //Время 
        time /= 800;
        clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Закрытие окна
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

    return 0;
}