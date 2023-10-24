#ifndef BULLET_H
#define BULLET_H
#include "movingobj.h"

class Bullet : public MovingObj
{
public:
    Bullet(Vector2f,int);
    ~Bullet() override {}
    //-----GET-----------------------------------
    float getX() override;
    float getY() override;
    Vector2f getSize() override;
    RectangleShape getRectangleShape() override;
    int getNumDirection() override;
    int getHealth() override;
    //-----SET-----------------------------------
    void setNumDirection(int) override {}
    void changeHealth() override {}
    //-----ACTION--------------------------------
    void Move() override;
};

#endif // BULLET_H
