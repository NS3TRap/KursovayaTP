#ifndef BASE_H
#define BASE_H

#include "stationaryobj.h"

using namespace sf;

class Base: public StationaryObj
{
//-Методы-#########################################################
public:
    Base(float, float);
    void changeHealth(int) override;
    void changeHealth() override;
    Vector2f getSize() override;
    float getX() override;
    float getY() override;
    int getHealth() override;
    bool getTypeDestroy() override;
    RectangleShape getRectangleShape() override;
};

#endif // BASE_H
