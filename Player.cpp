#include "Player.h"

void Player::move(float time)
{
    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        if (x <= 5)
            x = windowWidth - 5;
        else
            x -= (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        if (x >= (windowWidth - 5))
            x = 5;
        else
            x += (speed * time);
    }

    if (canJump) {
        y -= (jumpSpeed * time); 
        jumpHeight -= speed; 

        if (jumpHeight <= 0) {
            canJump = false;
            jumpSpeed = 0.7f;
            jumpHeight = 300.0f;
        }
    }

    y += (gravity * time);

    sprite.setPosition(x, y);
}
