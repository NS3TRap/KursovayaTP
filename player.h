#ifndef PLAYER_H
#define PLAYER_H
#include "movingobj.h"
#include "bullet.h"
#include "SFML/System/Clock.hpp"

class Player: public MovingObj
{
private:
    Clock cooldown;
public:
    Player(Vector2f);
    //-----GET-----------------------------------
    float getX() override;
    float getY() override;
    Vector2f getSize() override;
    RectangleShape getRectangleShape() override;
    int getNumDirection() override;
    int getHealth() override;
    float getCooldownTime();
    //-----SET-----------------------------------
    void setNumDirection(int) override;
    void changeHealth() override;
    //-----ACTION--------------------------------
    void Move() override;
    Bullet* Fire();
};

#endif // PLAYER_H
