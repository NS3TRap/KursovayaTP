#ifndef MOVINGOBJ_H
#define MOVINGOBJ_H
#include "object.h"

class MovingObj: public Object
{
//-Поля-###########################################################
protected:
    int numDirection;
    int health;
//-Методы-#########################################################
public:
    MovingObj();
    int virtual getNumDirection() = 0;
    void virtual setNumDirection(int) = 0;
    void virtual Move() = 0;
    void virtual changeHealth() = 0;
    int virtual getHealth() = 0;
};

#endif // MOVINGOBJ_H
