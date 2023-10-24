#ifndef LISTOFRECORDS_H
#define LISTOFRECORDS_H
#include <vector>
#include <record.h>
#include <algorithm>
#include <iostream>
#include <fstream>

class ListOfRecords
{
private:
    vector<Record*> listOfRecords; //вектор рекордсменов
    vector<Record*>::iterator iter; // итератор для вектора
public:
    ListOfRecords(); // конструктор
    ~ListOfRecords(); // деструктор
    void addNewRecord(string, int); // добавление нового рекорда
    bool cheakRepetition(string); // проверка на повторение имени
    void changeScore(string, int);
    Record* getListRecord(unsigned int); // возвращает отсортированного пользователся под указанным числом(топ 10)
private:
    void sorting(); // сортировка по убыванию
    static bool comparator(Record*, Record*); // компаратор для сортировки
};

#endif // LISTOFRECORDS_H
