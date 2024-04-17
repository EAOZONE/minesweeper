#include "Leaderboard.h"

class FaceButton : public Button{
public:
    FaceButton(){
        setPosition(0, 0);
    }
    FaceButton(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }
    void gameWon(){
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/face_win.png");
        setSprite();
    }
    void gameLose(){
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/face_lose.png");
        setSprite();
    }
    void gameActive(){
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/face_happy.png");
        setSprite();
    }
};