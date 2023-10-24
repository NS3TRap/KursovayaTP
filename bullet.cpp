#include "bullet.h"

Bullet::Bullet(Vector2f startPosition, int numDir)
{
    this->x = startPosition.x;
    this->y = startPosition.y;
    numDirection = numDir;
    health = 1;
    switch (numDirection) {
    case 1:
        size = Vector2f(12,16);
        objImage.loadFromFile("img/bulletUp.png");
        break;
    case 2:
        size = Vector2f(12,16);
        objImage.loadFromFile("img/bulletDown.png");
        break;
    case 3:
        size = Vector2f(16,12);
        objImage.loadFromFile("img/bulletLeft.png");
        break;
    case 4:
        size = Vector2f(16,12);
        objImage.loadFromFile("img/bulletRight.png");
        break;
    }
    objImage.createMaskFromColor(Color(0,0,1));

    objTexture.loadFromImage(objImage);
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(this->x, this->y);
}

float Bullet::getX(){
    return obj.getPosition().x;
}
float Bullet::getY(){
    return obj.getPosition().y;
}

Vector2f Bullet::getSize(){
    return size;
}

int Bullet::getHealth(){
    return health;
}

RectangleShape Bullet::getRectangleShape(){
    return obj;
}

int Bullet::getNumDirection(){
    return numDirection;
}

void Bullet::Move(){
    if(numDirection == 1)
        obj.move(0,-2);//вперед
    else if(numDirection == 2)
        obj.move(0,2);//вниз
    else if(numDirection == 3)
        obj.move(-2,0);//влево
    else if(numDirection == 4)
        obj.move(2,0);//вправо
}
