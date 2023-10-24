#ifndef MAPSELECTIONSCREEN_H
#define MAPSELECTIONSCREEN_H

#include "screens.h"
#include "gamescreen.h"
#include "inputrecordscreen.h"

class MapSelectionScreen: public Screens
{
//-Поля-###########################################################
private:
    RenderWindow* win; // окно
    bool activeWin;
    int choice;
    int score;
    //Объекты формы
    Text title; // Текст титульника вкладки
    //_____________________________________________________________
    Texture mapTexture1;
    RectangleShape Map1;
    RectangleShape Map2;
    RectangleShape Map3;
    Text textMap1, textMap2, textMap3;
    //_____________________________________________________________
    RectangleShape buttonBack;
    Text textBB;
    //_____________________________________________________________
    GameScreen* gameScreen;
    InputRecordScreen* inputRS;
//-Методы-#########################################################
public:
    MapSelectionScreen(RenderWindow*);
    void show();
private:
    void HandlingKeyPress();
};

#endif // MAPSELECTIONSCREEN_H
