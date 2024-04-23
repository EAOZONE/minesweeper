#include <iostream>
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include <fstream>

int main(){
    ifstream file("../files/config.cfg");
    int width;
    int height;
    int numOfBombs;
    if(file.is_open()){
        file>>width;
        file>>height;
        file>>numOfBombs;
    }
    WelcomeWindow welcomeWindow = WelcomeWindow((width*32)+100, height*32, "My window");
    bool startGame = welcomeWindow.events();
    if(startGame){
        GameWindow gameWindow = GameWindow(width, height, numOfBombs, welcomeWindow.getName());
        gameWindow.gamePlay();
    }
    else{
        cout<<"This would not open the game window"<<endl;
    }
}