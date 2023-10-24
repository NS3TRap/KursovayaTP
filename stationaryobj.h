#ifndef STATIONARYOBJ_H
#define STATIONARYOBJ_H

#include "object.h"

class StationaryObj: public Object
{
//-Поля-###########################################################
protected:
    bool destroyable;
    int health;
//-Методы-#########################################################
public:
    StationaryObj() {}
    void virtual changeHealth() = 0;
    void virtual changeHealth(int) = 0;
    int virtual getHealth() = 0;
    bool virtual getTypeDestroy() = 0;
};

#endif // STATIONARYOBJ_H
