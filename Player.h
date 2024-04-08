#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player
{
private:
	Texture texture;
	const int windowHeight = 700;
	const int windowWidth = 700;
public:
	Sprite sprite; 
	float x, y;
	bool canJump = false;
	float tempJump = 0;
	float speed;
	const float jumpSpeed;
	float jumpHeight;

	float gravity = 0.3f;

	Player(float startX, float startY, const string& textureFile) : x(startX), y(startY), canJump(false), speed(0.6f), jumpHeight(330.0f), jumpSpeed (0.7f){
		texture.loadFromFile(textureFile);
		sprite.setTexture(texture);
		sprite.setPosition(startX, startY);
	}

	//Движение персонажа
	void move(float time);
};