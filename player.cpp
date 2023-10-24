#include "player.h"

Player::Player(Vector2f startPosition)
{
    this->x = startPosition.x;
    this->y = startPosition.y;
    size = Vector2f(64,64);
    health = 3;
    objImage.loadFromFile("img/tankPlayerUp.png");
    objImage.createMaskFromColor(Color(0,0,1));

    objTexture.loadFromImage(objImage);
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(this->x, this->y);

    cooldown.restart();
}

float Player::getX(){
    return obj.getPosition().x;
}
float Player::getY(){
    return obj.getPosition().y;
}

void Player::changeHealth(){
    health--;
}

Vector2f Player::getSize(){
    return size;
}

RectangleShape Player::getRectangleShape(){
    return obj;
}

int Player::getNumDirection(){
    return numDirection;
}

void Player::setNumDirection(int numDir){
    numDirection = numDir;
    if(numDirection == 1){
        objImage.loadFromFile("img/tankPlayerUp.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 2){
        objImage.loadFromFile("img/tankPlayerDown.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 3){
        objImage.loadFromFile("img/tankPlayerLeft.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 4){
        objImage.loadFromFile("img/tankPlayerRight.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    }
}

void Player::Move(){
    if(numDirection == 1)
        obj.move(0,-2);//вперед
    else if(numDirection == 2)
        obj.move(0,2);//вниз
    else if(numDirection == 3)
        obj.move(-2,0);//влево
    else if(numDirection == 4)
        obj.move(2,0);//вправо
}

int Player::getHealth(){
    return health;
}

float Player::getCooldownTime(){
    return cooldown.getElapsedTime().asSeconds();
}

Bullet* Player::Fire(){
        cooldown.restart();
        if(numDirection == 1)
            return new Bullet(Vector2f(obj.getPosition().x + (size.x / 2), obj.getPosition().y), numDirection);
        else if(numDirection == 2)
            return new Bullet(Vector2f(obj.getPosition().x + (size.x / 2), obj.getPosition().y + size.y), numDirection);
        else if(numDirection == 3)
            return new Bullet(Vector2f(obj.getPosition().x, obj.getPosition().y + (size.y / 2)), numDirection);
        else if(numDirection == 4)
            return new Bullet(Vector2f(obj.getPosition().x + size.x, obj.getPosition().y + (size.y / 2)), numDirection);
        return NULL;
}
