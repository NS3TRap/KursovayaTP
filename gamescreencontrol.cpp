#include "gamescreen.h"

using namespace sf;
using namespace std;

unsigned int GameScreen::getRowObject(Vector2f objectSize, Vector2f objectPos)
{
    for(unsigned int i = 0; i < listOfWalls.size(); i++){
        if((i*64+3) <= (objectPos.y + objectSize.y / 2) && (objectPos.y + objectSize.y / 2) <= ((i+1)*64+3))
            return i;
    }
    return 0;
}

void GameScreen::desctructorVectMovingObjects(vector<MovingObj*>* vecMovingObjects){
    vector<MovingObj*>::iterator iterVect;
    iterVect = (*vecMovingObjects).begin();
    while (iterVect != (*vecMovingObjects).end())
    {
        (*vecMovingObjects).erase(iterVect);
    }
}

template<typename T> bool GameScreen::isThereAWall(int numDirection, T checkedObject){
    Vector2f objectPos = Vector2f(checkedObject->getX(), checkedObject->getY());
    Vector2f objectSize = checkedObject->getSize();
    Vector2f checkedObjectPos;
    unsigned int rowObject;
    float func;

    rowObject = getRowObject(objectSize, objectPos);

    if(numDirection == 1 || numDirection == 2){
        for(unsigned short i = 0; i < 2; i++){
            iterLOW = listOfWalls[rowObject].begin();
            while (iterLOW != listOfWalls[rowObject].end())
            {
                checkedObjectPos.x = (**iterLOW).getX();
                checkedObjectPos.y = (**iterLOW).getY();
                if((checkedObjectPos.x <= objectPos.x && (checkedObjectPos.x + (**iterLOW).getSize().x) > objectPos.x) ||
                   (checkedObjectPos.x < (objectPos.x + objectSize.x) && (checkedObjectPos.x + (**iterLOW).getSize().x) >= (objectPos.x + objectSize.x)))
                {
                    if(numDirection == 1){
                        func = objectPos.y - (checkedObjectPos.y + (**iterLOW).getSize().y);
                        if(func <= 0 && func > -(**iterLOW).getSize().x){
                            ptrWall = *iterLOW;
                            return true;
                        }
                    } else {
                        func = checkedObjectPos.y - (objectPos.y + objectSize.y);
                        if( func <= 0){
                            ptrWall = *iterLOW;
                            return true;
                        }
                    }
                }
                iterLOW++;
            }
            numDirection == 1 ? rowObject-- : rowObject++;
        }
    } else if(numDirection == 3 || numDirection == 4){
        for(unsigned short i = rowObject-1; i < rowObject +2; i++){
            iterLOW = listOfWalls[i].begin();
            while (iterLOW != listOfWalls[i].end())
            {
                checkedObjectPos.x = (**iterLOW).getX();
                checkedObjectPos.y = (**iterLOW).getY();
                if((checkedObjectPos.y <= objectPos.y && (checkedObjectPos.y + (**iterLOW).getSize().y) > objectPos.y) ||
                   (checkedObjectPos.y < (objectPos.y + objectSize.y) && (checkedObjectPos.y + (**iterLOW).getSize().y) >= (objectPos.y + objectSize.y)))
                {
                    if(numDirection == 3)
                        func = objectPos.x - (checkedObjectPos.x + (**iterLOW).getSize().x);
                    else
                        func = checkedObjectPos.x - (objectPos.x + objectSize.x);
                    if(func <= 0 && func > -(**iterLOW).getSize().x) {
                        ptrWall = *iterLOW;
                        return true;
                    }
                }
                iterLOW++;
            }
        }
    }
    return false;
}

template<typename T> bool GameScreen::isThereAMovObject(int numDirection, T checkedObject){
    Vector2f objectPos = Vector2f(checkedObject->getX(), checkedObject->getY());
    Vector2f objectSize  = checkedObject->getSize();
    Vector2f checkedObjectPos; Vector2f checkedobjectSize;
    vector<MovingObj*> buffObject;
    vector<MovingObj*>::iterator iterBO;
    float func;

    buffObject.push_back(ptrPlayer);
    for(vector<Enemy*>::iterator iter = vecOfEnemy.begin(); iter != vecOfEnemy.end(); iter++)
        buffObject.push_back(*iter);
    for(vector<Bullet*>::iterator iterB = listOfBullets.begin(); iterB != listOfBullets.end(); iterB++)
        buffObject.push_back(*iterB);

    iterBO = buffObject.begin();
    while (iterBO != buffObject.end())
    {
        if((*iterBO) == checkedObject){
            buffObject.erase(iterBO);
            break;
        }
        iterBO++;
    }

    if(numDirection == 1 || numDirection == 2){
        iterBO = buffObject.begin();
        while (iterBO != buffObject.end())
        {
            checkedObjectPos = Vector2f((**iterBO).getX(),(**iterBO).getY());
            checkedobjectSize = (**iterBO).getSize();
            if((checkedObjectPos.x <= objectPos.x && (checkedObjectPos.x + checkedobjectSize.x) > objectPos.x) ||
               (checkedObjectPos.x < (objectPos.x + objectSize.x) && (checkedObjectPos.x + checkedobjectSize.x) >= (objectPos.x + objectSize.x))){
                if(numDirection == 1){
                    func = objectPos.y - (checkedObjectPos.y + checkedobjectSize.y);
                    if( func <= 0 && func > -checkedobjectSize.y ){
                        ptrMovObject = *iterBO;
                        return true;
                    }
                } else {
                    func = checkedObjectPos.y - (objectPos.y + objectSize.y);
                    if( func <= 0 && func > -checkedobjectSize.y ){
                        ptrMovObject = *iterBO;
                        return true;
                    }
                }
            }
            iterBO++;
        }
    } else if(numDirection == 3 || numDirection == 4){
        iterBO = buffObject.begin();
        while (iterBO != buffObject.end())
        {
            checkedObjectPos = Vector2f((**iterBO).getX(),(**iterBO).getY());
            checkedobjectSize = (**iterBO).getSize();
            if((checkedObjectPos.y <= objectPos.y && (checkedObjectPos.y + checkedobjectSize.y) > objectPos.y) ||
               (checkedObjectPos.y < (objectPos.y + objectSize.y) && (checkedObjectPos.y + checkedobjectSize.y) >= (objectPos.y + objectSize.y)))
            {
                if(numDirection == 3)
                    func = objectPos.x - (checkedObjectPos.x + checkedobjectSize.x);
                else
                    func = checkedObjectPos.x - (objectPos.x + objectSize.x);
                if(func <= 0 && func > -checkedobjectSize.x) {
                    ptrMovObject = *iterBO;
                    return true;
                }
            }
           iterBO++;
        }
    }
    return false;
}

void GameScreen::Update(){
    iterRS = vecBoxLives.begin();
    while (iterRS != vecBoxLives.end())
    {
        if((unsigned int)ptrPlayer->getHealth() < vecBoxLives.size() || (unsigned int)ptrBase->getHealth() < vecBoxLives.size()){
            delete (*iterRS);
            vecBoxLives.erase(iterRS);
        } else
        win->draw(**iterRS);

        iterRS++;
    }
    for(unsigned int i = 0; i < listOfWalls.size(); i++){
        iterLOW = listOfWalls[i].begin();
        while (iterLOW != listOfWalls[i].end())
        {
            if((**iterLOW).getHealth() != 0)
                win->draw((**iterLOW).getRectangleShape());
            else{
                if(*iterLOW != ptrBase)
                delete *iterLOW;
                listOfWalls[i].erase(iterLOW);
            }
            iterLOW++;
        }
    }
    win->draw((*ptrPlayer).getRectangleShape());

    iterVOE = vecOfEnemy.begin();
    while (iterVOE != vecOfEnemy.end())
    {
        switch ((*iterVOE)->ChoiceOfEnemyAction()) {
        case 0:
            (*iterVOE)->setNumDirection(1);
            if(!isThereAWall(1, (*iterVOE)) && !isThereAMovObject(1, (*iterVOE)))
                (*iterVOE)->Move();
            else
                (*iterVOE)->setNumberOfAction(1);
            break;
        case 1:
            (*iterVOE)->setNumDirection(2);
            if(!isThereAWall(2,(*iterVOE)) && !isThereAMovObject(2, (*iterVOE)))
                (*iterVOE)->Move();
            else
                (*iterVOE)->setNumberOfAction(0);
            break;
        case 2:
            (*iterVOE)->setNumDirection(3);
            if(!isThereAWall(3,(*iterVOE)) && !isThereAMovObject(3, (*iterVOE)))
               (*iterVOE)->Move();
            else
               (*iterVOE)->setNumberOfAction(3);
            break;
        case 3:
            (*iterVOE)->setNumDirection(4);
            if(!isThereAWall(4,(*iterVOE)) && !isThereAMovObject(4, (*iterVOE)))
                (*iterVOE)->Move();
            else
                (*iterVOE)->setNumberOfAction(2);
            break;
        case 4:
            if((*iterVOE)->getCooldownTime() > 1)
                listOfBullets.push_back((*iterVOE)->Fire());
            break;
        }

        if((**iterVOE).getHealth() != 0)
            win->draw((*iterVOE)->getRectangleShape());
        else{
            delete *iterVOE;
            vecOfEnemy.erase(iterVOE);
            *ptrScore += 50;
            textCountEnemy.setString(String(to_string(--countEnemy)));
            textScore.setString(String(to_string(*ptrScore)));
            textScore.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textScore.getGlobalBounds().width)/2,
                                  130+ textPreScore.getGlobalBounds().height);
            continue;
        }
        iterVOE++;
    }

    if(vecOfEnemy.size() < 2 && countEnemy >= 2){
        vecOfEnemy.push_back(new Enemy(spawnPoint));
        iterVOE = vecOfEnemy.begin();
        if (vecOfEnemy.size() > 1)
            iterVOE++;
        if(isThereAMovObject(4, *iterVOE) || isThereAMovObject(3, *iterVOE) || isThereAMovObject(2, *iterVOE)|| isThereAMovObject(1, *iterVOE)){
            delete *iterVOE;
            vecOfEnemy.erase(iterVOE);
        }
    }

    iterLOB = listOfBullets.begin();
    while (iterLOB != listOfBullets.end())
    {
        if(isThereAWall((*iterLOB)->getNumDirection(), (*iterLOB))){
            ptrWall->changeHealth((*iterLOB)->getNumDirection());
            delete *iterLOB;
            listOfBullets.erase(iterLOB);
            continue;
        } else if(isThereAMovObject((*iterLOB)->getNumDirection(), (*iterLOB))){
            ptrMovObject->changeHealth();
            delete *iterLOB;
            listOfBullets.erase(iterLOB);
            continue;
        } else {
            (*iterLOB)->Move();
            win->draw((*iterLOB)->getRectangleShape());
        }

        iterLOB++;
    }

    if(ptrPlayer->getHealth() == 0 || ptrBase->getHealth() == 0 || countEnemy == 0)
        activeWin = false;
}

void GameScreen::HandlingKeyPress(){
    switch (ev.key.code) {
        case Keyboard::Up:
            ptrPlayer->setNumDirection(1);
            if(!isThereAWall(1, ptrPlayer) && !isThereAMovObject(1, ptrPlayer))
                ptrPlayer->Move();
            break;
        case Keyboard::Down:
            ptrPlayer->setNumDirection(2);
            if(!isThereAWall(2, ptrPlayer) && !isThereAMovObject(2, ptrPlayer))
                ptrPlayer->Move();
            break;
        case Keyboard::Left:
            ptrPlayer->setNumDirection(3);
            if(!isThereAWall(3, ptrPlayer) && !isThereAMovObject(3, ptrPlayer))
                ptrPlayer->Move();
            break;
        case Keyboard::Right:
            ptrPlayer->setNumDirection(4);
            if(!isThereAWall(4, ptrPlayer) && !isThereAMovObject(4, ptrPlayer))
                ptrPlayer->Move();
            break;
        default:
            break;
    }
}
