#include "enemy.h"
using namespace std;

Enemy::Enemy(Vector2f startPosition)
{
    this->x = startPosition.x;
    this->y = startPosition.y;
    numDirection = 1;
    size = Vector2f(64,64);
    health = 3;
    objImage.loadFromFile("img/tankEnemyUp.png");
    objImage.createMaskFromColor(Color(0,0,1));

    objTexture.loadFromImage(objImage);
    obj = RectangleShape(size);
    obj.setTexture(&objTexture);
    obj.setPosition(this->x, this->y);

    cooldown.restart();
    cooldownAction.restart();
}

int Enemy::getHealth(){
    return health;
}

float Enemy::getCooldownTime(){
    return cooldown.getElapsedTime().asSeconds();
}

float Enemy::getCooldownTimeAction(){
    return cooldownAction.getElapsedTime().asSeconds();
}

void Enemy::changeHealth(){
    health--;
}

float Enemy::getX(){
    return obj.getPosition().x;
}
float Enemy::getY(){
    return obj.getPosition().y;
}

Vector2f Enemy::getSize(){
    return size;
}

RectangleShape Enemy::getRectangleShape(){
    return obj;
}

int Enemy::getNumDirection(){
    return numDirection;
}

void Enemy::setNumDirection(int numDir){
    numDirection = numDir;
    if(numDirection == 1){
        objImage.loadFromFile("img/tankEnemyUp.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 2){
        objImage.loadFromFile("img/tankEnemyDown.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 3){
        objImage.loadFromFile("img/tankEnemyLeft.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    } else if(numDirection == 4){
        objImage.loadFromFile("img/tankEnemyRight.png");
        objImage.createMaskFromColor(Color(0,0,1));
        objTexture.loadFromImage(objImage);
    }
}

void Enemy::Move(){
    if(numDirection == 1)
        obj.move(0,-1);//вперед
    else if(numDirection == 2)
        obj.move(0,1);//вниз
    else if(numDirection == 3)
        obj.move(-1,0);//влево
    else if(numDirection == 4)
        obj.move(1,0);//вправо
}

Bullet* Enemy::Fire(){
        cooldown.restart();
        if(numDirection == 1)
            return new Bullet(Vector2f(obj.getPosition().x + (size.x / 2), obj.getPosition().y - 1), numDirection);
        else if(numDirection == 2)
            return new Bullet(Vector2f(obj.getPosition().x + (size.x / 2), obj.getPosition().y + size.y + 1), numDirection);
        else if(numDirection == 3)
            return new Bullet(Vector2f(obj.getPosition().x - 1, obj.getPosition().y + (size.y / 2)), numDirection);
        else if(numDirection == 4)
            return new Bullet(Vector2f(obj.getPosition().x + size.x + 1, obj.getPosition().y + (size.y / 2)), numDirection);
        return NULL;
}

int Enemy::getNumberOfAction(){
    return numberOfAction;
}

void Enemy::setNumberOfAction(int num){
    numberOfAction = num;
}

void Enemy::CooldownRestart(){
    cooldownAction.restart();
}

int Enemy::ChoiceOfEnemyAction(){
    SYSTEMTIME st;
    int randNum = numberOfAction;
    if(getCooldownTimeAction() > 1.0f){
        GetLocalTime(&st);
        srand(st.wMilliseconds);
        randNum = rand() % 5;
        setNumberOfAction(randNum);
        CooldownRestart();
    }
    return randNum;
}
