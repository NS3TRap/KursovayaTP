#include "listofrecords.h"

using namespace std;

ListOfRecords::ListOfRecords()
{
    string name;
    int score;

    ifstream in("Data/record.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> name;
            in >> score;
            listOfRecords.push_back(new Record(name, score));
        }
    }
    in.close();     // закрываем файл
}

ListOfRecords::~ListOfRecords(){
    ofstream out;          // поток для записи
    out.open("Data/record.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        iter = listOfRecords.begin();
        while (iter != listOfRecords.end())
        {
            if((*listOfRecords.rbegin()) == *iter)
                out << (**iter).getNickname() << endl << (**iter).getScore();
            else
                out << (**iter).getNickname() << endl << (**iter).getScore() << endl;
            iter++;
        }
    }

    out.close();
    while (!listOfRecords.empty())
    {
        iter = listOfRecords.begin();
        delete *iter;
        listOfRecords.erase(iter);
    }
}

Record* ListOfRecords::getListRecord(unsigned int num){
    if(listOfRecords.size() >= num)
        return listOfRecords[num-1];
    else {
        return new Record("0", 0);
    }
}

bool ListOfRecords::comparator(Record* firstElement, Record *secondElement){ // компаратор для сортировки
    return firstElement->getScore() > secondElement->getScore();
}

void ListOfRecords::sorting(){ // сортировка по убыванию результатов
    sort(listOfRecords.begin(), listOfRecords.end(), comparator);
}

void ListOfRecords::addNewRecord(string nick, int score){
    listOfRecords.push_back(new Record(nick, score));
    sorting();
}

void ListOfRecords::changeScore(string nickname, int newScore){  //true - есть совпадение , false - нет совпадений
    iter = listOfRecords.begin();
    while (iter != listOfRecords.end())
    {
        if((**iter).getNickname() == nickname){
           (**iter).changeScore(newScore);
            return;
        }
        iter++;
    }
}

bool ListOfRecords::cheakRepetition(string cheak){  //true - есть совпадение , false - нет совпадений
    iter = listOfRecords.begin();
    while (iter != listOfRecords.end())
    {
        if((**iter).getNickname() == cheak)
            return true;
        iter++;
    }
    return false;
}

