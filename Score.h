#pragma once
#include <SFML/Graphics.hpp> 
#include <fstream>

#include "PLayer.h" 
using namespace sf;
using namespace std;

class Score {
public:
    int score;
    int record;
    ofstream fileScore;
    Font font;
    Text scoreText;

    Score() {
        score = 0;

        font.loadFromFile("Image/PIXY.ttf");
        scoreText.setFont(font);
        scoreText.setCharacterSize(36);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setString("Score: " + std::to_string(score));
    }

    void updateScore();
    void saveRecordToFile();
    void updateRecord();
    int getRecord();
};