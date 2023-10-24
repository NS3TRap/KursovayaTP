#ifndef OUTPUTRECORDSSCREEN_H
#define OUTPUTRECORDSSCREEN_H

#include <screens.h>
#include <listofrecords.h>
#include <vector>

using namespace sf;

class OutputRecordsScreen: public Screens
{
//-Поля-###########################################################
private:
    RenderWindow* win; // окно
    //Объекты формы
    Text title; // Текст титульника вкладки
    //_______________________________________________________________________________
    // все связанное с выводом рекордов
    ListOfRecords* listOR; // список рекордов
    vector<Text*> listRecordsNum; // вектор указателей типа Text для вывода рекордсменов
    vector<Text*> listRecordsNick;
    vector<Text*> listRecordsScore;
    vector<Text*>::iterator iter;
    Text textNumber, textNickname, textScore; // названия
    RectangleShape table; //прямоугольник для таблицы
    //_______________________________________________________________________________
    // контроллеры
    RectangleShape buttonBack;//кнопка назад
    Text textBB;// текст к кнопке
//-Методы-#########################################################
public:
    OutputRecordsScreen(RenderWindow*);
    ~OutputRecordsScreen();
    void show();
private:
    void displayList(vector<Text*>);
};

#endif // OUTPUTRECORDSSCREEN_H
