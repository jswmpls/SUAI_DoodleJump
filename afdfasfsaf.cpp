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

    playing(window, player, score, platforms);

    return 0;
}