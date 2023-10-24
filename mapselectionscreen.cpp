#include "mapselectionscreen.h"
#include <iostream>

MapSelectionScreen::MapSelectionScreen(RenderWindow* window): win(window)
{
    activeWin = true;
    choice = 1;
    score = 0;
    // Шрифт
    setCentralPos(win);
    font.loadFromFile("Font/Pixeled.ttf");
    //___________________________________________________________________
    // Title
    title = Text("MAP SELECTION",font);
    title.setCharacterSize(40);
    title.setPosition(centralPosition.x - title.getGlobalBounds().width/2, centralPosition.y/4 - title.getGlobalBounds().height/2);
    // Карта 1
    mapTexture1.loadFromFile("img/map1.png");

    Map1 = RectangleShape(Vector2f(512, 512));
    Map1.setOutlineThickness(3);
    Map1.setOutlineColor(Color::Red);
    Map1.setTexture(&mapTexture1);
    Map1.setPosition(82, centralPosition.y - Map1.getGlobalBounds().height/2+2);

    textMap1 = Text("Map 1", font);
    textMap1.setCharacterSize(40);
    textMap1.setFillColor(Color::Black);
    textMap1.setPosition(Map1.getPosition().x + Map1.getGlobalBounds().width/2 - textMap1.getGlobalBounds().width/2,
                         Map1.getPosition().y + Map1.getGlobalBounds().height/2 - textMap1.getGlobalBounds().height/2);
    // Карта 2(некст аптдейт)
    Map2 = RectangleShape(Vector2f(512, 512));
    Map2.setOutlineThickness(3);
    Map2.setOutlineColor(Color::Yellow);
    Map2.setPosition(centralPosition.x - Map2.getGlobalBounds().width/2+2, centralPosition.y - Map2.getGlobalBounds().height/2+2);

    textMap2 = Text("Map 2(NEXT UPDATE)", font);
    textMap2.setCharacterSize(30);
    textMap2.setFillColor(Color::Black);
    textMap2.setPosition(Map2.getPosition().x + Map2.getGlobalBounds().width/2 - textMap2.getGlobalBounds().width/2,
                         Map2.getPosition().y + Map2.getGlobalBounds().height/2 - textMap2.getGlobalBounds().height/2);
    // Карта 3(некст апдейт)
    Map3 = RectangleShape(Vector2f(512, 512));
    Map3.setOutlineThickness(3);
    Map3.setOutlineColor(Color::Yellow);
    Map3.setPosition((2*centralPosition.x) - 82 - Map3.getGlobalBounds().width, centralPosition.y - Map3.getGlobalBounds().height/2+2);

    textMap3 = Text("Map 3(NEXT UPDATE)", font);
    textMap3.setCharacterSize(30);
    textMap3.setFillColor(Color::Black);
    textMap3.setPosition(Map3.getPosition().x + Map3.getGlobalBounds().width/2 - textMap3.getGlobalBounds().width/2,
                         Map3.getPosition().y + Map3.getGlobalBounds().height/2 - textMap3.getGlobalBounds().height/2);
    // Кнопка назад
    buttonBack = RectangleShape(sizeButton);
    buttonBack.setOutlineThickness(3);
    buttonBack.setOutlineColor(Color::Yellow);
    buttonBack.setPosition(centralPosition.x - buttonBack.getGlobalBounds().width/2+3,
                           centralPosition.y - buttonBack.getGlobalBounds().height/2+402);

    textBB = Text("BACK", font);
    textBB.setCharacterSize(25);
    textBB.setFillColor(Color::Black);
    textBB.setPosition(buttonBack.getPosition().x + buttonBack.getGlobalBounds().width/2 - textBB.getGlobalBounds().width/2,
                       buttonBack.getPosition().y + buttonBack.getGlobalBounds().height/2 - textBB.getGlobalBounds().height/2);

}
void MapSelectionScreen::HandlingKeyPress(){
    if(ev.key.code == Keyboard::Enter){
        switch (choice) {
        case 1:
            gameScreen = new GameScreen(win, choice, &score);
            gameScreen->show();
            delete gameScreen;
            inputRS = new InputRecordScreen(win, score);
            inputRS->show();
            delete inputRS;
            score = 0;
            break;
        case 2:
            //map2
            break;
        case 3:
            //map3
            break;
        case 0:
            activeWin = false;
            break;
        }
    }else if(ev.key.code == Keyboard::Left){
        if(choice == 1)
            choice = 3;
        else
            choice -= 1;
    } else if(ev.key.code == Keyboard::Right){
        if(choice == 3)
            choice = 1;
        else
            choice += 1;
    } else if(ev.key.code == Keyboard::Up){
        if(choice >= 1)
            choice = 0;
        else
            choice = 1;
    } else if(ev.key.code == Keyboard::Down){
        if(choice == 0)
            choice = 1;
        else
            choice = 0;
    }
}

void MapSelectionScreen::show(){
    while (activeWin) {
        while (win->pollEvent(ev)) {
            if(ev.type == Event::Closed)
                win->close();
            else if(ev.type == Event::KeyReleased){
                HandlingKeyPress();
                switch (choice) {
                    case 1:
                        Map1.setOutlineColor(Color::Red);
                        Map2.setOutlineColor(Color::Yellow);
                        Map3.setOutlineColor(Color::Yellow);
                        buttonBack.setOutlineColor(Color::Yellow);
                        break;
                    case 2:
                        Map1.setOutlineColor(Color::Yellow);
                        Map2.setOutlineColor(Color::Red);
                        Map3.setOutlineColor(Color::Yellow);
                        buttonBack.setOutlineColor(Color::Yellow);
                        break;
                    case 3:
                        Map1.setOutlineColor(Color::Yellow);
                        Map2.setOutlineColor(Color::Yellow);
                        Map3.setOutlineColor(Color::Red);
                        buttonBack.setOutlineColor(Color::Yellow);
                        break;
                    case 0:
                        Map1.setOutlineColor(Color::Yellow);
                        Map2.setOutlineColor(Color::Yellow);
                        Map3.setOutlineColor(Color::Yellow);
                        buttonBack.setOutlineColor(Color::Red);
                        break;
                }
            }
        }
        win->clear();
        win->draw(title);
        win->draw(Map1);
        win->draw(Map2);
        win->draw(Map3);
        win->draw(textMap1);
        win->draw(textMap2);
        win->draw(textMap3);
        win->draw(buttonBack);
        win->draw(textBB);
        win->display();
    }
}
