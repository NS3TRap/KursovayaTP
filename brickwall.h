#ifndef BRICKWALL_H
#define BRICKWALL_H

#include "stationaryobj.h"

class BrickWall: public StationaryObj
{
//-Методы-#########################################################
public:
    BrickWall(float, float);
    void changeHealth(int) override;
    void changeHealth() override;
    Vector2f getSize() override;
    float getX() override;
    float getY() override;
    int getHealth() override;
    bool getTypeDestroy() override;
    RectangleShape getRectangleShape() override;
private:
    void changeSize(int);
};

#endif // BRICKWALL_H
