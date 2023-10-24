#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Object
{
//-Поля-###########################################################
protected:
    Vector2f size; // размер объекта
    float x;
    float y;
    //---------------------------------------
    RectangleShape obj;
    Image objImage;
    Texture objTexture;
//-Методы-#########################################################
public:
    Object() {}
    virtual ~Object() {}
    float virtual getX() = 0;
    float virtual getY() = 0;
    Vector2f virtual getSize() = 0;
    RectangleShape virtual getRectangleShape() = 0;
};

#endif // OBJECT_H
