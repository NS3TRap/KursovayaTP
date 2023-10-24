#include "inputrecordscreen.h"

using namespace sf;

InputRecordScreen::InputRecordScreen(RenderWindow* window, int scr): win(window), score(scr)
{
     listOR = new ListOfRecords();
     repetition = false;
     activeWin = true;
     choice = 1;
     // Шрифт
     setCentralPos(win);
     font.loadFromFile("Font/Pixeled.ttf");
     // Title
     text2 = Text("YOUR SCORE:",font);
     text2.setCharacterSize(40);
     text2.setPosition(centralPosition.x - text2.getGlobalBounds().width/2, centralPosition.y/4 - text2.getGlobalBounds().height/2);

     textScore = Text(std::to_string(score), font);
     textScore.setFillColor(Color::Green);
     textScore.setCharacterSize(80);
     textScore.setPosition(centralPosition.x - textScore.getGlobalBounds().width/2,
                           centralPosition.y/4 - textScore.getGlobalBounds().height/2 + 100);

     text = Text("ENTER NICKNAME", font);
     text.setCharacterSize(40);
     text.setPosition(centralPosition.x - text.getGlobalBounds().width/2, centralPosition.y - text.getGlobalBounds().height/2 - 80);
     // Текст бар
     RecTextBox = RectangleShape(Vector2f(550, 70));
     RecTextBox.setOutlineThickness(3);
     RecTextBox.setOutlineColor(Color::Red);
     RecTextBox.setPosition(centralPosition.x - RecTextBox.getGlobalBounds().width/2+2, centralPosition.y - RecTextBox.getGlobalBounds().height/2+2);

     inputLine = Text("", font);
     inputLine.setCharacterSize(20);
     inputLine.setFillColor(Color::Black);
     inputLine.setPosition(RecTextBox.getPosition().x + RecTextBox.getGlobalBounds().width/2 - inputLine.getGlobalBounds().width/2,
                           RecTextBox.getPosition().y + RecTextBox.getGlobalBounds().height/2 - inputLine.getGlobalBounds().height/2);
     // кнопки управления
     textQuestion = Text("THIS NAME ALREADY EXISTS, SAVE IT?", font);
     textQuestion.setCharacterSize(40);
     textQuestion.setPosition(centralPosition.x - textQuestion.getGlobalBounds().width/2,
                              centralPosition.y - textQuestion.getGlobalBounds().height/2 + 200);

     buttonOk = RectangleShape(sizeButton);
     buttonOk.setOutlineThickness(3);
     buttonOk.setOutlineColor(Color::Yellow);
     buttonOk.setPosition(centralPosition.x - buttonOk.getGlobalBounds().width/2+252,
                          centralPosition.y - buttonOk.getGlobalBounds().height/2+402);

     buttonCancel = RectangleShape(sizeButton);
     buttonCancel.setOutlineThickness(3);
     buttonCancel.setOutlineColor(Color::Yellow);
     buttonCancel.setPosition(centralPosition.x - buttonCancel.getGlobalBounds().width/2-252,
                              centralPosition.y - buttonCancel.getGlobalBounds().height/2+402);

     textBO = Text("OK", font);
     textBO.setCharacterSize(25);
     textBO.setFillColor(Color::Black);
     textBO.setPosition(buttonOk.getPosition().x + buttonOk.getGlobalBounds().width/2 - textBO.getGlobalBounds().width/2,
                        buttonOk.getPosition().y + buttonOk.getGlobalBounds().height/2 - textBO.getGlobalBounds().height/2);

     textBC = Text("Cancel", font);
     textBC.setCharacterSize(25);
     textBC.setFillColor(Color::Black);
     textBC.setPosition(buttonCancel.getPosition().x + buttonCancel.getGlobalBounds().width/2 - textBC.getGlobalBounds().width/2,
                        buttonCancel.getPosition().y + buttonCancel.getGlobalBounds().height/2 - textBC.getGlobalBounds().height/2);

}

InputRecordScreen::~InputRecordScreen()
{
    delete listOR;
}

void InputRecordScreen::HandlingKeyPress(){
    if(!repetition){
        if(ev.key.code == Keyboard::Enter){
            repetition = listOR->cheakRepetition(inputLine.getString());
            if(!repetition){
                listOR->addNewRecord(inputLine.getString(),score);
                activeWin = false;
            }
        }else if(97 <= ev.key.code+97 && ev.key.code+97 <= 122 && inputLine.getString().getSize() <= 15){
            inputLine.setString(inputLine.getString() + (char)(ev.key.code+97));
            inputLine.setPosition(RecTextBox.getPosition().x + RecTextBox.getGlobalBounds().width/2 - inputLine.getGlobalBounds().width/2,
                                  RecTextBox.getPosition().y + RecTextBox.getGlobalBounds().height/2 - inputLine.getGlobalBounds().height/2);
        }else if(ev.key.code == Keyboard::BackSpace){
            inputLine.setString(inputLine.getString().substring(0,inputLine.getString().getSize()-1));
            inputLine.setPosition(RecTextBox.getPosition().x + RecTextBox.getGlobalBounds().width/2 - inputLine.getGlobalBounds().width/2,
                                  RecTextBox.getPosition().y + RecTextBox.getGlobalBounds().height/2 - inputLine.getGlobalBounds().height/2);
        }
    }else{
        if(ev.key.code == Keyboard::Enter){
            if(choice == 1)
                repetition = false;
            else{
                listOR->changeScore(inputLine.getString(),score);
                activeWin = false;
            }
        } else if(ev.key.code == Keyboard::Left){
            if(choice == 1)
                choice = 2;
            else
                choice -= 1;
        } else if(ev.key.code == Keyboard::Right){
            if(choice == 2)
                choice = 1;
            else
                choice += 1;
        }
    }
}

void InputRecordScreen::show(){
    while (activeWin) {
        while (win->pollEvent(ev)) {
            if(ev.type == Event::Closed)
                win->close();
            else if(ev.type == Event::KeyReleased){
                HandlingKeyPress();
                if(choice == 1){
                    buttonOk.setOutlineColor(Color::Yellow);
                    buttonCancel.setOutlineColor(Color::Red);
                } else{
                    buttonOk.setOutlineColor(Color::Red);
                    buttonCancel.setOutlineColor(Color::Yellow);
                }
            }
        }
        win->clear();
        win->draw(text2);
        win->draw(textScore);
        win->draw(text);
        win->draw(RecTextBox);
        win->draw(inputLine);
        if(repetition){
            win->draw(textQuestion);
            win->draw(buttonOk);
            win->draw(buttonCancel);
            win->draw(textBO);
            win->draw(textBC);
        }
        win->display();
    }
}
