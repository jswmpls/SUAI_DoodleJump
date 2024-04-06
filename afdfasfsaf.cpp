#include "Gameplay.h"

using namespace sf;
using namespace std;

int main()
{
    const int heightBack = 700;
    const int widthBack = 700;

    RenderWindow window(VideoMode(widthBack, heightBack), "Doodle jump!"); //Создание окна
    Image icon; //Установка иконки для окна
    icon.loadFromFile("Image/icon.png");
    window.setIcon(33, 32, icon.getPixelsPtr());

    Player player(200, 500, "Image/pers.png"); //Идентифицируем класс Player
    Platforms platforms(200, 600, "Image/platformMin.png"); //Идентифицируем класс Platforms
    Score score; //Идентифицируем класс Score
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

    return 0;
}