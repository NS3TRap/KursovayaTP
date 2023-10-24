#include "userinterfacescreen.h"
#include <fstream>

using namespace sf;
using namespace std;

UserInterfaceScreen::UserInterfaceScreen(){
//###############################-ТЕКСТ-##############################################################################################
    // Окно
    win = new RenderWindow(VideoMode(400,400), "SFML", Style::Fullscreen); //указатель на окно
    win->setFramerateLimit(50); //FPS = 60
    win->setMouseCursorVisible(false); // Убран курсор
    setCentralPos(win);
    // Текст
    label = Text("Crime", font);
    label.setCharacterSize(100);
    label2 = Text("City", font);
    label2.setCharacterSize(100);

    label.setPosition(centralPosition.x - label.getGlobalBounds().width /2,
                      centralPosition.y - label.getGlobalBounds().height/2 - 200);

    label2.setPosition(centralPosition.x - label2.getGlobalBounds().width /2,
                       centralPosition.y - label2.getGlobalBounds().height/2 - 50);

    creatorsText = Text("Creators:\nNikita Sorokin\nFedor Safronov\nAnna Kemova\nSemen Zabirohin\nAnton Gubar",font);
    creatorsText.setCharacterSize(20);
    creatorsText.setPosition(centralPosition.x * 2 - label2.getGlobalBounds().width + 50, 10);
//###############################-КНОПКИ-############################################################################################
    // Текст кнопок
    textBS = Text("Start game", font);
    textBS.setCharacterSize(40);
    textBS.setFillColor(Color::Black);
    textBR = Text("Records", font);
    textBR.setCharacterSize(40);
    textBR.setFillColor(Color::Black);
    textBE = Text("Exit", font);
    textBE.setFillColor(Color::Black);
    textBE.setCharacterSize(40);

    // Кнопка Старт
    buttonStart.setSize(sizeButton);
    buttonStart.setOutlineThickness(3);
    buttonStart.setPosition(centralPosition.x - buttonStart.getGlobalBounds().width/2 + 3,
                            centralPosition.y - buttonStart.getGlobalBounds().height/2 + 150);

    textBS.setPosition(buttonStart.getPosition().x - textBS.getGlobalBounds().width/2 + buttonStart.getGlobalBounds().width/2 + 3,
                       buttonStart.getPosition().y - textBS.getGlobalBounds().height/2 + buttonStart.getGlobalBounds().height/2 + 3);
    // Кнопка Рекордов
    buttonRecords.setSize(sizeButton);
    buttonRecords.setOutlineThickness(3);
    buttonRecords.setPosition(centralPosition.x - buttonRecords.getGlobalBounds().width/2 + 3,
                              centralPosition.y - buttonRecords.getGlobalBounds().height/2 + 250);

    textBR.setPosition(buttonRecords.getPosition().x - textBR.getGlobalBounds().width/2 + buttonRecords.getGlobalBounds().width/2 + 3,
                       buttonRecords.getPosition().y - textBR.getGlobalBounds().height/2 + buttonRecords.getGlobalBounds().height/2 + 3);
    // Кнопка Выхода
    buttonExit.setSize(sizeButton);
    buttonExit.setOutlineThickness(3);
    buttonExit.setPosition(centralPosition.x - buttonExit.getGlobalBounds().width/2 + 3,
                           centralPosition.y - buttonExit.getGlobalBounds().height/2 + 350);

    textBE.setPosition(buttonExit.getPosition().x - textBE.getGlobalBounds().width/2 + buttonExit.getGlobalBounds().width/2 + 3,
                       buttonExit.getPosition().y - textBE.getGlobalBounds().height/2 + buttonExit.getGlobalBounds().height/2 + 3);

    // Изначально выбран старт игры
    changeColor(1);
}

void UserInterfaceScreen::changeColor(int ch){ //Смена цвета в зависимости от выбранной клавиши
    switch (ch) {
        case 1:
            buttonStart.setOutlineColor(Color::Red);
            buttonRecords.setOutlineColor(Color::Yellow);
            buttonExit.setOutlineColor(Color::Yellow);
            break;
        case 2:
            buttonStart.setOutlineColor(Color::Yellow);
            buttonRecords.setOutlineColor(Color::Red);
            buttonExit.setOutlineColor(Color::Yellow);
            break;
        case 3:
            buttonStart.setOutlineColor(Color::Yellow);
            buttonRecords.setOutlineColor(Color::Yellow);
            buttonExit.setOutlineColor(Color::Red);
            break;
    }
}

void UserInterfaceScreen::interact(){
    while (win->isOpen()) {
        while (win->pollEvent(ev)) {
            if(ev.type == Event::Closed)
                win->close();
//##################################-ОБРАБОТКА-КЛАВИШ-#################################################################################
            else if(ev.type == Event::KeyReleased){
                if(ev.key.code == Keyboard::Down){
                    if(choice == 3)
                        choice = 1;
                    else
                        choice += 1;
                }
                else if(ev.key.code == Keyboard::Up){
                    if(choice == 1)
                        choice = 3;
                    else
                        choice -= 1;
                }
                else if(ev.key.code == Keyboard::Enter){
                    switch (choice) {
                        case 1:
                            ptrMapSelectionScreen = new MapSelectionScreen(win);
                            ptrMapSelectionScreen->show();
                            delete ptrMapSelectionScreen;
                            break;
                        case 2:
                            ptrOutputRS = new OutputRecordsScreen(win);
                            ptrOutputRS->show();
                            delete ptrOutputRS;
                            break;
                        case 3:
                            win->close();
                            break;
                    }
                }
                changeColor(choice);
            }
        }
//##################################-ОТРИСОВКА-ОБЪЕКТОВ-#################################################################################
        win->clear();
        win->draw(label);
        win->draw(label2);
        win->draw(creatorsText);
        win->draw(buttonStart);
        win->draw(buttonRecords);
        win->draw(buttonExit);
        win->draw(textBS);
        win->draw(textBR);
        win->draw(textBE);
        win->display();
    }
}
