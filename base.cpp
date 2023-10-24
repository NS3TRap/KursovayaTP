#include "base.h"

Base::Base(float x, float y)
{
    destroyable = true;
    size = Vector2f(64,64);
    health = 3;

    objTexture.loadFromFile("img/base.png");
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(x, y);
}

void Base::changeHealth(){
    health -= 1;
}

void Base::changeHealth(int i){
    health -= i;
}

float Base::getX(){
    return obj.getPosition().x;
}

float Base::getY(){
    return obj.getPosition().y;
}

Vector2f Base::getSize(){
    return size;
}

int Base::getHealth(){
    return health;
}

bool Base::getTypeDestroy(){
    return destroyable;
}

RectangleShape Base::getRectangleShape(){
    return obj;
}
