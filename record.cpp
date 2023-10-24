#include "record.h"

string Record::getNickname(){
    return nickname;
}

int Record::getScore(){
    return score;
}

void Record::changeScore(int newScore){
    score = newScore;
}
