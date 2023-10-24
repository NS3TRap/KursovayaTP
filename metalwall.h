#ifndef METALWALL_H
#define METALWALL_H

#include "stationaryobj.h"

class MetalWall: public StationaryObj
{
//-Методы-#########################################################
public:
    MetalWall(float, float);
    void changeHealth(int) override {}
    void changeHealth() override {}
    Vector2f getSize() override;
    float getX() override;
    float getY() override;
    int getHealth() override;
    bool getTypeDestroy() override;
    RectangleShape getRectangleShape() override;
};

#endif // METALWALL_H
