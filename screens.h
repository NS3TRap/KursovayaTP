#ifndef SCREENS_H
#define SCREENS_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Screens
{
//#####-ПОЛЯ-#################
protected:
    Vector2f centralPosition; //вектор для цетровки текста
    Vector2f sizeButton; //ширина и длинна кнопки
    Event ev; // объект эвентов
    Font font;
//#####-МЕТОДЫ-###############
public:
    Screens();
    void setCentralPos(RenderWindow*);
};

#endif // SCREENS_H
