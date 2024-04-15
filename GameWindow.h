using namespace std;
#include <string>
#include <SFML/Window.hpp>
#include <iostream>
#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "Board.h"

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
        sf::RenderWindow window(sf::VideoMode(numOfRows * 32, numOfCols * 32+100), "GameScreen");
        Board board = Board(numOfRows, numOfCols, numOfBombs);
        board.setBombs();
        board.calculateNearbyBombs();
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear(sf::Color::White);
            for(int i = 0; i < numOfRows; i++){
                for(int j = 0; j<numOfCols; j++) {
                    window.draw(board.getBoard()[i][j]->sprite);
                    if (sf::Mouse().isButtonPressed(Mouse::Right)) {
                        board.mouseRightClicked(sf::Mouse().getPosition(window), i, j);
                    }
                    else if (sf::Mouse().isButtonPressed(Mouse::Left)){
                        board.openTile(sf::Mouse().getPosition(window), i, j);
                    }
                }
            }

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