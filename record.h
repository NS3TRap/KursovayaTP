#ifndef RECORD_H
#define RECORD_H
#include <iostream>

using namespace std;

class Record
{
private:
    string nickname;
    int score;
public:
    Record(string nick, int s):nickname(nick), score(s) {}
    string getNickname();
    int getScore();
    void changeScore(int);
};

#endif // RECORD_H
