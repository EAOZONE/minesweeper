using namespace std;
#include <string>
#include <SFML/Window.hpp>
#include <iostream>
#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
void setText(sf::Text &text, float x, float y){
    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}
class WelcomeWindow {
private:
    int sizeOfName;
    string name;
    sf::Font font;
public:
    WelcomeWindow():sizeOfName(10){
        font.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/font.ttf");
    }
    bool events(float x, float y, const string& name_){
        sf::RenderWindow window(sf::VideoMode(x, y), name_);
        while(window.isOpen()){
            sf::Event event{};
            while(window.pollEvent(event)){
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return false;
                }
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace){
                    if(!name.empty()) {
                        name.pop_back();
                    }
                }
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                    if(!name.empty()) {
                        window.close();
                        //Open game window
                        return true;
                    }
                }
                if(event.type == sf::Event::TextEntered){
                    if(event.text.unicode < 128 && isalpha(static_cast<char>(event.text.unicode))){
                        if(name.size() < sizeOfName){
                            if(name.empty()){
                                name += toupper(static_cast<char>(event.text.unicode));
                            }
                            else{
                                name += tolower(static_cast<char>(event.text.unicode));
                            }
                        }
                    }
                }
            }
            sf::Text text = drawWord(name + "|", x / 2, y / 2 - 45, 18);
            sf::Text instructions = drawWord("WELCOME TO MINESWEEPER!", x / 2, (y / 2) - 150, 24);
            sf::Text instructions_1 = drawWord("Enter your name:", x / 2, (y / 2) - 75, 20);
            instructions.setStyle(sf::Text::Underlined);
            text.setStyle(sf::Text::Bold);
            instructions.setStyle(sf::Text::Bold);
            instructions_1.setStyle(sf::Text::Bold);
            window.clear(sf::Color::Blue);
            window.draw(instructions);
            window.draw(instructions_1);
            window.draw(text);
            window.display();
        }
    }
    sf::Text drawWord(const string& word, float pos_x, float pos_y, int size){
        sf::Text text(word, font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::White);
        setText(text, pos_x, pos_y);
        return text;
    }
    string getName(){
        return name;
    }
};