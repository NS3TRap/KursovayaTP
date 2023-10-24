#include "metalwall.h"

MetalWall::MetalWall(float X, float Y)
{
    this->x = X;
    this->y = Y;
    destroyable = false;
    size = Vector2f(64,64);
    health = 3;

    objImage.loadFromFile("img/metalWall.png");

    objTexture.loadFromImage(objImage);
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(this->x, this->y);
}

int MetalWall::getHealth(){
    return health;
}

bool MetalWall::getTypeDestroy(){
    return destroyable;
}

float MetalWall::getX(){
    return obj.getPosition().x;
}

float MetalWall::getY(){
    return obj.getPosition().y;
}

Vector2f MetalWall::getSize(){
    return size;
}

RectangleShape MetalWall::getRectangleShape(){
    return obj;
}
