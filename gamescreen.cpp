#include "gamescreen.h"

using namespace sf;
using namespace std;

GameScreen::GameScreen(RenderWindow* window, int choiceMap, int* score): win(window), numberMap(choiceMap), ptrScore(score){
    activeWin = true;
    countEnemy = 8;
    // Шрифт
    setCentralPos(win);
    font.loadFromFile("Font/Pixeled.ttf");
    livesTexture.loadFromFile("img/heart.png");
    //##################################-Элементы окна-#########################################
    // Игровая зона
    gameBox = RectangleShape(Vector2f(1472,1024));
    gameBox.setOutlineThickness(3);
    gameBox.setOutlineColor(Color::Red);
    gameBox.setFillColor(Color::Black);
    gameBox.setPosition(3, 3);
    // Счет игрока
    textPreScore = Text("SCORE:", font);
    textPreScore.setCharacterSize(30);
    textPreScore.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textPreScore.getGlobalBounds().width)/2, 100);

    textScore = Text("0", font);
    textScore.setCharacterSize(30);
    textScore.setFillColor(Color::Green);
    textScore.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textScore.getGlobalBounds().width)/2,
                          130+ textPreScore.getGlobalBounds().height);
    // Кол-во оставшихся врагов
    textPreCE = Text("REMAINING ENEMIES:", font);
    textPreCE.setCharacterSize(22);
    textPreCE.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textPreCE.getGlobalBounds().width)/2,
                          textScore.getPosition().y + 100);

    textCountEnemy = Text(String(to_string(countEnemy)), font);
    textCountEnemy.setCharacterSize(30);
    textCountEnemy.setFillColor(Color::Red);
    textCountEnemy.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textCountEnemy.getGlobalBounds().width)/2,
                               textPreCE.getPosition().y + 50);
    // Оставшиеся жизни
    textPreLives = Text("REMAINING LIVES:", font);
    textPreLives.setCharacterSize(22);
    textPreLives.setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - textPreLives.getGlobalBounds().width)/2,
                             textCountEnemy.getPosition().y + 100);

    vecBoxLives.push_back(new RectangleShape(Vector2f(64,64)));
    vecBoxLives[0]->setTexture(&livesTexture);
    vecBoxLives[0]->setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - vecBoxLives[0]->getGlobalBounds().width)/2 - 80,
                               textPreLives.getPosition().y + 50);
    vecBoxLives.push_back(new RectangleShape(Vector2f(64,64)));
    vecBoxLives[1]->setTexture(&livesTexture);
    vecBoxLives[1]->setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - vecBoxLives[1]->getGlobalBounds().width)/2,
                               textPreLives.getPosition().y + 50);
    vecBoxLives.push_back(new RectangleShape(Vector2f(64,64)));
    vecBoxLives[2]->setTexture(&livesTexture);
    vecBoxLives[2]->setPosition((win->getSize().x + gameBox.getGlobalBounds().width + 6 - vecBoxLives[2]->getGlobalBounds().width)/2 + 80,
                               textPreLives.getPosition().y + 50);

    Map* mapLoad = new Map(choiceMap);
    mapLoad->setElementsToVector(&listOfWalls, &vecOfEnemy);
    ptrPlayer = new Player(mapLoad->getStartPlayerPosition());
    ptrPlayer->setNumDirection(1);
    ptrBase = mapLoad->getBasePtr();
    spawnPoint = mapLoad->getSpawnPoint();
    delete mapLoad;
}

GameScreen::~GameScreen(){
    while (!vecBoxLives.empty())
    {
        iterRS = vecBoxLives.begin();
        delete *iterRS;
        vecBoxLives.erase(iterRS);
    }
    while(!listOfWalls.empty()){
        while (!listOfWalls[0].empty())
        {
          iterLOW = listOfWalls[0].begin();
          delete *iterLOW;
          listOfWalls[0].erase(iterLOW);
        }
        listOfWalls.erase(listOfWalls.begin());
    }
    while (!vecOfEnemy.empty())
    {
        iterVOE = vecOfEnemy.begin();
        delete *iterVOE;
        vecOfEnemy.erase(iterVOE);
    }

    while (!listOfBullets.empty())
    {
        iterLOB = listOfBullets.begin();
        delete *iterLOB;
        listOfBullets.erase(iterLOB);
    }

    delete ptrPlayer;
}

void GameScreen::show(){
    while (activeWin) {
        while (win->pollEvent(ev)) {
            if(ev.type == Event::Closed)
                win->close();
            else if(ev.type == Event::KeyPressed){
                HandlingKeyPress();
            }
            else if(ev.type == Event::KeyReleased){
                if(ev.key.code == Keyboard::Enter && ptrPlayer->getCooldownTime() > 1)
                    listOfBullets.push_back(ptrPlayer->Fire());
            }
        }
        win->clear();
        win->draw(gameBox);
        win->draw(textPreScore);
        win->draw(textScore);
        win->draw(textPreCE);
        win->draw(textCountEnemy);
        win->draw(textPreLives);
        Update();
        win->display();
    }
}
