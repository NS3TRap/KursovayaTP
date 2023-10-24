#ifndef ENEMY_H
#define ENEMY_H
#include "movingobj.h"
#include "bullet.h"
#include <stdlib.h>
#include <windows.h>

using namespace std;

class Enemy : public MovingObj
{
private:
    Clock cooldown;
    Clock cooldownAction;
    int numberOfAction;
public:
    Enemy(Vector2f);
    //-----GET-----------------------------------
    float getX() override;
    float getY() override;
    Vector2f getSize() override;
    RectangleShape getRectangleShape() override;
    int getNumDirection() override;
    int getHealth() override;
    float getCooldownTime();
    float getCooldownTimeAction();
    int getNumberOfAction();
    //-----SET-----------------------------------
    void setNumDirection(int) override;
    void changeHealth() override;
    void setNumberOfAction(int);
    //-----ACTION--------------------------------
    void Move() override;
    int ChoiceOfEnemyAction();           // выбор действия у врага
    void CooldownRestart();
    Bullet* Fire();
};

#endif // ENEMY_H
