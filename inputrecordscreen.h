#ifndef INPUTRECORDSCREEN_H
#define INPUTRECORDSCREEN_H

#include "screens.h"
#include "listofrecords.h"
#include <string>

using namespace sf;

class InputRecordScreen: public Screens
{
//-Поля-###########################################################
private:
    RenderWindow* win; // окно
    bool activeWin;
    int score;
    //Объекты формы
    Text text; // Текст титульника вкладки
    Text text2; // текст к счету
    Text textScore; // счет
    //_______________________________________________________________________________
    ListOfRecords* listOR; // список рекордов
    RectangleShape RecTextBox;// поле ввода
    Text inputLine; // текст ввода
    //_______________________________________________________________________________
    Text textQuestion;
    RectangleShape buttonOk;//кнопка ок
    RectangleShape buttonCancel;//кнопка отмены
    Text textBO, textBC;// текст к кнопкам
    bool repetition;
    int choice;
//-Методы-#########################################################
public:
    InputRecordScreen(RenderWindow*, int);
    ~InputRecordScreen();
    void show();
private:
    void HandlingKeyPress();
};

#endif // INPUTRECORDSCREEN_H
