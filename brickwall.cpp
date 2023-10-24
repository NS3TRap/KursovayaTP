#include "brickwall.h"

BrickWall::BrickWall(float X, float Y)
{
    this->x = X;
    this->y = Y;
    destroyable = true;
    size = Vector2f(64,64);
    health = 4;
    objImage.loadFromFile("img/brickWall.png");

    objTexture.loadFromImage(objImage);
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(this->x, this->y);
}

int BrickWall::getHealth(){
    return health;
}

bool BrickWall::getTypeDestroy(){
    return destroyable;
}

void BrickWall::changeSize(int numDiirection){
    int numberOfFile;
    switch (numDiirection) {
    case 1: // сверху
        size.y -= 16;
        numberOfFile = size.y;
        objImage.loadFromFile("img/brickWall"+ std::to_string(numberOfFile) +"H.png");
        objTexture.loadFromImage(objImage);
        obj.setTexture(&objTexture, true);
        obj.setSize(size);
        break;
    case 2: // снизу
        size.y -= 16;
        numberOfFile = size.y;
        objImage.loadFromFile("img/brickWall"+ std::to_string(numberOfFile) +"H.png");
        objTexture.loadFromImage(objImage);
        obj.setTexture(&objTexture, true);
        obj.setSize(size);
        obj.setPosition(obj.getPosition().x, obj.getPosition().y+16);
        break;
    case 3: // слева
        size.x -= 16;
        numberOfFile = size.x;
        objImage.loadFromFile("img/brickWall"+ std::to_string(numberOfFile) +"W.png");
        objTexture.loadFromImage(objImage);
        obj.setTexture(&objTexture, true);
        obj.setSize(size);
        break;
    case 4: // справа
        size.x -= 16;
        numberOfFile = size.x;
        objImage.loadFromFile("img/brickWall"+ std::to_string(numberOfFile) +"W.png");
        objTexture.loadFromImage(objImage);
        obj.setTexture(&objTexture, true);
        obj.setSize(size);
        obj.setPosition(obj.getPosition().x+16, obj.getPosition().y);
        break;
    }
}

void BrickWall::changeHealth(int numDiirection){
    health -= 1;
    if(health != 0)
        changeSize(numDiirection);
}

void BrickWall::changeHealth(){

}

float BrickWall::getX(){
    return obj.getPosition().x;
}

float BrickWall::getY(){
    return obj.getPosition().y;
}

Vector2f BrickWall::getSize(){
    return size;
}

RectangleShape BrickWall::getRectangleShape(){
    return obj;
}
