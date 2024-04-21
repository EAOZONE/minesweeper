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
    sf::Clock clock;
    int minutes = 0;
    int seconds = 0;
    Timer* timer;
    sf::Time totalElapsedTime;
public:
    GameWindow(int rows, int cols, int bombs, string name): numOfCols(rows), numOfRows(cols), numOfBombs(bombs), PlayerName(name){
        font.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/font.ttf");
    }
    void pauseClock(){
        totalElapsedTime += clock.getElapsedTime();
    }
    void resumeClock(){
        clock.restart();
    }
    sf::Time getElapsedTime() const{
        if(paused){
            return totalElapsedTime;
        }
        else{
            return totalElapsedTime + clock.getElapsedTime();
        }
    }
    void gamePlay() {
        sf::RenderWindow window(sf::VideoMode(numOfCols * 32, numOfRows * 32 + 100), "GameScreen");
        Board board = Board(numOfCols, numOfRows, numOfBombs);
        board.setBombs();
        board.calculateNearbyBombs();
        timer = new Timer((numOfCols*32)-97, 32*(numOfRows+0.5)+16, numOfCols, numOfRows);
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
            sf::Time elapsed = clock.getElapsedTime();
            totalElapsedTime += elapsed;
            if (!paused && elapsed.asSeconds() >= 1)
            {
                clock.restart();
                seconds++;
                if (seconds >= 60)
                {
                    minutes++;
                    seconds = 0;
                }
            }
            timer->update(seconds, minutes);
            gameActive = !board.checkLose() || debugButton.getDebugActive();
            window.clear(sf::Color::White);
            window.draw(debugButton.sprite);
            window.draw(pausePlayButton.sprite);
            window.draw(leaderBoard.sprite);
            window.draw(faceButton.sprite);
            for (int i = 0; i < 3; i++) {
                window.draw(board.getCounter(i));
            }
            for(int i = 0; i <2; i++){
                window.draw(timer->getMinutes(i));
                window.draw(timer->getSeconds(i));
            }
            for(int i = 0; i < numOfCols; i++){
                for(int j = 0; j < numOfRows; j++) {
                    window.draw(board.getBoard()[i][j]->sprite);
                    if(board.getBoard()[i][j]->getState() == flag && !paused)
                        window.draw(board.getFlag(i, j));

                    if((!gameActive || debugButton.getDebugActive()) && board.getBoard()[i][j]->getIsMine())
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
                    pauseClock();
                    paused = true;
                } else if(board.getAllOpen() && !pausePlayButton.getPause()) {
                    for (int l = 0; l < numOfCols; l++) {
                        for (int m = 0; m < numOfRows; m++) {
                            board.returnToNormal(l, m);
                        }
                    }
                    resumeClock();
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