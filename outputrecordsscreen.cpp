#include "outputrecordsscreen.h"

using namespace sf;

OutputRecordsScreen::OutputRecordsScreen(RenderWindow* window): win(window){
    listOR = new ListOfRecords();
    Text* textBuffNick;
    Text* textBuffScore;
    Text* textBuffNumber;
    // Шрифт
    setCentralPos(win);
    font.loadFromFile("Font/Pixeled.ttf");
    // Текст кнопок
    textBB = Text("Back", font);
    textBB.setCharacterSize(40);
    textBB.setFillColor(Color::Black);

    buttonBack.setSize(sizeButton);
    buttonBack.setOutlineThickness(3);
    buttonBack.setOutlineColor(Color::Red);
    buttonBack.setPosition(centralPosition.x - buttonBack.getGlobalBounds().width/2 + 3,
                           centralPosition.y - buttonBack.getGlobalBounds().height/2 + 450);
    textBB.setPosition(buttonBack.getPosition().x - textBB.getGlobalBounds().width/2 + buttonBack.getGlobalBounds().width/2 + 3,
                       buttonBack.getPosition().y - textBB.getGlobalBounds().height/2 + buttonBack.getGlobalBounds().height/2 + 3);

    table.setSize(Vector2f(800,700));
    table.setOutlineThickness(3);
    table.setOutlineColor(Color::Blue);
    table.setPosition(centralPosition.x - table.getGlobalBounds().width/2+2, centralPosition.y - table.getGlobalBounds().height/2+2);

    title = Text("RECORDS TABLE", font);
    title.setCharacterSize(40);
    title.setPosition(centralPosition.x - title.getGlobalBounds().width/2,
                      table.getPosition().y - title.getGlobalBounds().height - 80);

    textNumber = Text("Num", font);
    textNumber.setCharacterSize(25);
    textNumber.setFillColor(Color::Black);
    textNumber.setPosition(table.getPosition().x + 48,
                           table.getPosition().y - textNumber.getGlobalBounds().height/2 + table.getGlobalBounds().height/11 + 2);

    textNickname = Text("Nickname", font);
    textNickname.setCharacterSize(25);
    textNickname.setFillColor(Color::Black);
    textNickname.setPosition(table.getPosition().x - textNickname.getGlobalBounds().width/2+table.getGlobalBounds().width/2,
                             table.getPosition().y - textNickname.getGlobalBounds().height/2 + table.getGlobalBounds().height/11 + 2);

    textScore = Text("Score", font);
    textScore.setCharacterSize(25);
    textScore.setFillColor(Color::Black);
    textScore.setPosition(table.getPosition().x - textScore.getGlobalBounds().width+table.getGlobalBounds().width - 48,
                          table.getPosition().y - textScore.getGlobalBounds().height/2 + table.getGlobalBounds().height/11 + 2);

     for(unsigned int i = 1; i < 11; i++){
         textBuffNumber = new Text(to_string(i),font);
         textBuffNumber->setCharacterSize(20);
         textBuffNumber->setFillColor(Color::Black);
         textBuffNumber->setPosition(table.getPosition().x + 48 + textNumber.getGlobalBounds().width/2,
                                     table.getPosition().y - textBuffNumber->getGlobalBounds().height/2 + (i+1)*table.getGlobalBounds().height/12);

         listRecordsNum.push_back(textBuffNumber);

         textBuffNick = new Text(listOR->getListRecord(i)->getNickname(),font);
         textBuffNick->setCharacterSize(20);
         textBuffNick->setFillColor(Color::Black);
         textBuffNick->setPosition(textNickname.getPosition().x + textNickname.getGlobalBounds().width/2 - textBuffNick->getGlobalBounds().width/2,
                                   table.getPosition().y - textBuffNick->getGlobalBounds().height/2 + (i+1)*table.getGlobalBounds().height/12);

         listRecordsNick.push_back(textBuffNick);

         textBuffScore = new Text(to_string(listOR->getListRecord(i)->getScore()),font);
         textBuffScore->setCharacterSize(20);
         textBuffScore->setFillColor(Color::Black);
         textBuffScore->setPosition(textScore.getPosition().x + textScore.getGlobalBounds().width/2 - textBuffScore->getGlobalBounds().width/2,
                                    table.getPosition().y - textBuffScore->getGlobalBounds().height/2 + (i+1)*table.getGlobalBounds().height/12);

         listRecordsScore.push_back(textBuffScore);
    }
         delete listOR;
}
OutputRecordsScreen::~OutputRecordsScreen(){    
    while (!listRecordsNum.empty())
    {
        iter = listRecordsNum.begin();
        delete *iter;
        listRecordsNum.erase(iter);
    }
    while (!listRecordsNick.empty())
    {
        iter = listRecordsNick.begin();
        delete *iter;
        listRecordsNick.erase(iter);
    }
    while (!listRecordsScore.empty())
    {
        iter = listRecordsScore.begin();
        delete *iter;
        listRecordsScore.erase(iter);
    }
}
void OutputRecordsScreen::displayList(vector<Text *> vec){
    iter = vec.begin();
       while (iter != vec.end())
       {
           win->draw(**iter);
           iter++;
       }
}

void OutputRecordsScreen::show(){
    while (win->isOpen()) {
        while (win->pollEvent(ev)) {
            if(ev.type == Event::Closed)
                win->close();
            else if(ev.type == Event::KeyReleased){
                if(ev.key.code == Keyboard::Enter)
                    return;
            }
        }
        win->clear();
        win->draw(title);
        win->draw(table);
        win->draw(textNumber);
        win->draw(textNickname);
        win->draw(textScore);
        win->draw(buttonBack);
        displayList(listRecordsNum);
        displayList(listRecordsNick);
        displayList(listRecordsScore);
        win->draw(textBB);
        win->display();
    }
}
