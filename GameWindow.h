using namespace std;
#include <string>
#include <SFML/Window.hpp>
#include <iostream>
#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class GameWindow{
private:
    int numOfRows;
    int numOfCols;
    int numOfBombs;
    string PlayerName;
    sf::Font font;
public:
    GameWindow(int rows, int cols, int bombs, string name):numOfRows(rows),numOfCols(cols),numOfBombs(bombs),PlayerName(name){
        font.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/font.ttf");
    }
    void gamePlay() {
        sf::RenderWindow window(sf::VideoMode(numOfRows * 32 + 100, numOfCols * 32), "GameScreen");
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            sf::Text something = drawWord("This is the game screen for now", (numOfRows*32+100)/2,(numOfCols*32)/2);
            sf::Text displayName = drawWord("You typed in " + PlayerName, (numOfRows*32+100)/2,(numOfCols*32)/2 + 100);
            window.clear(sf::Color::Blue);
            window.draw(something);
            window.draw(displayName);
            window.display();
        }

    }
    sf::Text drawWord(string word, float pos_x, float pos_y){
        sf::Text text(word, font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        setText(text, pos_x, pos_y);
        return text;
    }
};