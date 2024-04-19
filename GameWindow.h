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
    int numOfCols;
    int numOfRows;
    int numOfBombs;
    string PlayerName;
    sf::Font font;
    bool gameActive;
    bool paused;
    bool leftButtonPressed = false;
    bool rightButtonPressed = false;
public:
    GameWindow(int rows, int cols, int bombs, string name): numOfCols(rows), numOfRows(cols), numOfBombs(bombs), PlayerName(name){
        font.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/font.ttf");
    }
    void gamePlay() {
        sf::RenderWindow window(sf::VideoMode(numOfCols * 32, numOfRows * 32 + 100), "GameScreen");
        Board board = Board(numOfCols, numOfRows, numOfBombs);
        board.setBombs();
        board.calculateNearbyBombs();

        DebugButton debugButton = DebugButton((numOfCols * 32) - 304, 32 * (numOfRows + 0.5), "../Project 3 - Minesweeper Spring 2024/files/images/debug.png");
        PausePlay pausePlayButton = PausePlay((numOfCols * 32) - 240, 32 * (numOfRows + 0.5), "../Project 3 - Minesweeper Spring 2024/files/images/pause.png");
        LeaderBoard leaderBoard = LeaderBoard( (numOfCols * 32) - 176, 32*(numOfRows + 0.5), "../Project 3 - Minesweeper Spring 2024/files/images/leaderboard.png");
        leaderBoard.readTopFive("../Project 3 - Minesweeper Spring 2024/files/leaderboard.txt");
        FaceButton faceButton = FaceButton((numOfCols*16)-32, 32*(numOfRows+0.5), "../Project 3 - Minesweeper Spring 2024/files/images/face_happy.png");
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            gameActive = !board.checkLose() || debugButton.getDebugActive();
            window.clear(sf::Color::White);
            window.draw(debugButton.sprite);
            window.draw(pausePlayButton.sprite);
            window.draw(leaderBoard.sprite);
            window.draw(faceButton.sprite);
            for(int i = 0; i < numOfCols; i++){
                for(int j = 0; j < numOfRows; j++) {
                    window.draw(board.getBoard()[i][j]->sprite);
                }
            }
            if (sf::Mouse().isButtonPressed(Mouse::Right) && !rightButtonPressed) {
                rightButtonPressed = true;
                if (gameActive && !paused) {
                    for (int i = 0; i < numOfCols; i++) {
                        for (int j = 0; j < numOfRows; j++) {
                            board.mouseRightClicked(sf::Mouse().getPosition(window), i, j);
                        }
                    }
                }
            }
            else if(!sf::Mouse().isButtonPressed(Mouse::Right)){
                rightButtonPressed = false;
            }
            if (sf::Mouse().isButtonPressed(Mouse::Left) && !leftButtonPressed){
                leftButtonPressed = true;
                if(faceButton.buttonClicked(sf::Mouse().getPosition(window))){
                    board.reset();
                    board.setBombs();
                    board.calculateNearbyBombs();
                    faceButton.gameActive();
                    gameActive = true;
                }
                leaderBoard.buttonPressed(sf::Mouse().getPosition(window), numOfCols, numOfRows);
                if(debugButton.buttonPressed(sf::Mouse().getPosition(window)) && gameActive && !paused){
                    debugButton.setDebugActive(!debugButton.getDebugActive());
                    for(int bombs = 0; bombs < numOfCols; bombs++){
                        for(int b = 0; b < numOfRows; b++){
                            if(board.getBoard()[bombs][b]->getIsMine()){
                                board.setDebug(bombs, b);
                            }
                        }
                    }
                }
                //TODO: fix pause button as openTile is not working
                else if(gameActive && pausePlayButton.ButtonClicked(sf::Mouse().getPosition(window))) {
                    pausePlayButton.updateButtonTexture();
                    }
                if (pausePlayButton.getPause() && pausePlayButton.getButtonPressed()) {
                    for (int l = 0; l < numOfCols; l++) {
                        for (int m = 0; m < numOfRows; m++) {
                            board.openAll(l, m);
                        }
                    }
                    paused = true;
                } else if(board.getAllOpen() && !pausePlayButton.getPause()) {
                    for (int l = 0; l < numOfCols; l++) {
                        for (int m = 0; m < numOfRows; m++) {
                            board.returnToNormal(l, m);
                        }
                    }
                    paused = false;
                }
                if(!paused && gameActive){
                    for(int i = 0; i < numOfCols; i++) {
                        for (int j = 0; j < numOfRows; j++) {
                            board.openTile(sf::Mouse().getPosition(window), i, j);
                        }
                    }
                }
            }
            else if(!sf::Mouse().isButtonPressed(Mouse::Left)){
                leftButtonPressed = false;
            }
            if(board.checkWin()) {
                board.setAllFlags();
                faceButton.gameWon();
                gameActive = false;
            }
            else if(!gameActive && !debugButton.getDebugActive()){
                faceButton.gameLose();
                board.showAllBombs();
                gameActive = false;
            }
            else if(gameActive){
                faceButton.gameActive();
                gameActive = true;
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