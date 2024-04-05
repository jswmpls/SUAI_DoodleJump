#include "Platforms.h"

void Platforms::update(Player& player, RenderWindow& window, Score& score) {
    for (coordinates& plat : platforms) {
        sprite.setPosition(plat.x, plat.y);

        //Коллизия персонажа с платформой  
        if (player.x <= plat.x + 60 &&
            player.x >= plat.x - 60 &&
            player.y - 30 < plat.y + 60 - 130 &&
            player.y > plat.y - 60)
        {
            player.canJump = true;
        }

        //Добавление новых платформ 
        if (player.y < platforms[platforms.size() - 1].y + 500)
        {
            coordinates newPlatform;
            newPlatform.x = rand() % windowWidth;
            newPlatform.y = platforms[platforms.size() - 1].y - 700 / 10;
            platforms.push_back(newPlatform);
        }

        //Удаление платформ, вышедших за экран 
        for (vector<coordinates>::iterator it = platforms.begin(); it != platforms.end(); ++it)
        {
            if (player.y < plat.y - 500)
            {
                platforms.erase(it);
                score.updateScore();
                break;
            }
        }

        //Поражение 
        if (player.y > platforms.front().y + 250) {
            loser(window, player, score);
        }

        window.draw(sprite);
    }
}
