#ifndef USERINTERFACESCREEN_H
#define USERINTERFACESCREEN_H

#include "outputrecordsscreen.h"
#include "mapselectionscreen.h"//del
#include "screens.h"
#include <iostream>

using namespace sf;
using namespace std;

class UserInterfaceScreen: public Screens
{
//-Поля-###########################################################
private:
    RenderWindow* win; // окно
    OutputRecordsScreen* ptrOutputRS; // указатель на экран вывода рекордов
    MapSelectionScreen* ptrMapSelectionScreen;//del
    //различные объекты формы
    Text label, label2, creatorsText, textBS, textBR, textBE;
    RectangleShape buttonStart, buttonRecords, buttonExit;
    int choice = 1;
//-Методы-#########################################################
public:
    UserInterfaceScreen();
    ~UserInterfaceScreen() {}
    void interact();
private:
    void changeColor(int ch);
};

#endif // USERINTERFACESCREEN_H
