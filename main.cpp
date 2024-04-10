#include <iostream>
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include <fstream>

int main(){
    ifstream file("../Project 3 - Minesweeper Spring 2024/files/config.cfg");
    int width;
    int height;
    int numOfBombs;
    if(file.is_open()){
        file>>width;
        file>>height;
        file>>numOfBombs;
    }
    WelcomeWindow welcomeWindow = WelcomeWindow();
    bool startGame = welcomeWindow.events((width*32)+100, height*32, "My window");
    if(startGame){
        GameWindow gameWindow = GameWindow(width, height, numOfBombs, welcomeWindow.getName());
        gameWindow.gamePlay();
    }
    else{
        cout<<"This would not open the game window"<<endl;
    }
}