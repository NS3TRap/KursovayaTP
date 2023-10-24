#include "screens.h"

Screens::Screens()
{
    // Шрифт
    font.loadFromFile("Font/Pixeled.ttf");

    // Размер кнопок
    sizeButton = Vector2f(430, 70);
}

void Screens::setCentralPos(RenderWindow* win){
    // Центровка текста
    centralPosition = Vector2f(win->getSize().x/2 , win->getSize().y /2);
}
