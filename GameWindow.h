using namespace std;
#include <string>
#include <SFML/Window.hpp>
#include <iostream>
#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "Tile.h"

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
        Tile* board[numOfRows][numOfCols];
        sf::RenderWindow window(sf::VideoMode(numOfRows * 32, numOfCols * 32+100), "GameScreen");
        for(int i = 0; i < numOfRows; i++){
            for(int j = 0; j<numOfCols; j++){
                board[i][j] = new Tile(i*32, j*32, "../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
            }
        }
        int bombsPlaced = 0;
        while (bombsPlaced < numOfBombs){
            int row = rand() % numOfRows;
            int col = rand() % numOfCols;
            if(!board[row][col]->isMine){
                board[row][col]->setIsMine(true);
            }
            else{
                board[row][col]->setIsMine(false);
            }
            bombsPlaced++;
        }
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear(sf::Color::Blue);
            for(int i = 0; i < numOfRows; i++){
                for(int j = 0; j<numOfCols; j++) {
                    window.draw(board[i][j]->sprite);
                    if (sf::Mouse().isButtonPressed(Mouse::Right)) {
                        board[i][j]->placeFlag(sf::Mouse().getPosition(window));
                    }
                    else if (sf::Mouse().isButtonPressed(Mouse::Left)){
                        board[i][j]->openBox(sf::Mouse().getPosition(window));
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