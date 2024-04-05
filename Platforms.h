#pragma once
#include "Player.h" 
#include "Score.h"
#include "Gameplay.h"

#include <string.h>

class Platforms {
private:
    const int windowHeight;
    const int windowWidth;
    Texture platformTexture;
public:
    struct coordinates {
        int x, y;
    };

    vector <coordinates> platforms;
    Sprite sprite;

    Platforms(int initialX, int initialY, const string& TextureFile) : windowHeight(700), windowWidth(700){
        platformTexture.loadFromFile(TextureFile);
        sprite.setTexture(platformTexture);
        sprite.setPosition(initialX, initialY);

        coordinates platform;
        platform.x = 170;
        platform.y = 630;
        platforms.push_back(platform);

        for (int i = 0; i < 20; i++) {
            platform.x = rand() % windowWidth;
            platform.y = 700 - (700 / 10) * i + 60;
            platforms.push_back(platform);
        }
    }

    void update(Player& player, RenderWindow& window, Score& score); 
};