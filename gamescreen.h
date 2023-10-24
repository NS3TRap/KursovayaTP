#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screens.h"
#include <vector>
#include "map.h"
#include "object.h"
#include "player.h"
#include "bullet.h"
#include "base.h"
#include "enemy.h"
#include <stdlib.h>
#include <windows.h>
using namespace sf;
using namespace std;

class GameScreen: Screens {
//-Поля-###############################################################################################
private:
    RenderWindow* win; // окно
    bool activeWin;    // активное окно
    int numberMap;     // номер карты
    int* ptrScore;
    //-------------------------------------------------------------
    RectangleShape gameBox;                     // игровое поле
    Text textPreScore,textScore;                // счет игрока
    int countEnemy;
    Text textPreCE,textCountEnemy;              // количество оставшихся врагов
    Texture livesTexture;                       // текстура жизней
    Text textPreLives;                          // текст к картинкам с жизнями
    vector<RectangleShape*> vecBoxLives;        // вектор, который отображает кол-во оставшихся жизней
    vector<RectangleShape*>::iterator iterRS;   // итератор для вектора RectangleShape*
    //-------------------------------------------------------------
    vector<vector<StationaryObj*>> listOfWalls;        // список стен(упорядоченный)
    vector<StationaryObj*>::iterator iterLOW;          // итератор
    StationaryObj* ptrWall;
    Base* ptrBase;
    MovingObj* ptrMovObject;
    vector<Bullet*> listOfBullets;              // список всех пуль
    vector<Bullet*>::iterator iterLOB;          // итератор
    Vector2f spawnPoint;
    vector<Enemy*> vecOfEnemy;                  // вектор врагов
    vector<Enemy*>::iterator iterVOE;           // итератор
    Player* ptrPlayer;                          // указатель на объект игрока
//-Методы-#############################################################################################
public:
    GameScreen(RenderWindow*, int, int*);
    ~GameScreen();
    void show();
private:
    void HandlingKeyPress();              // обработка клавиш
    void Update();                        // обновление состояния объектов
    unsigned int getRowObject(Vector2f, Vector2f );
    template<typename T> bool isThereAWall(int, T);     // проверка на наличие стены
    template<typename T> bool isThereAMovObject(int, T);
    void desctructorVectMovingObjects(vector<MovingObj*>*);
};
#endif // GAMESCREEN_H
