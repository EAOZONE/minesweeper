#include "GameObject.h"

class Flag : public GameObject{
public:
    Flag(){
        setPosition(0, 0);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
    }
    Flag(float x, float y){
        setPosition(x, y);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
    }
    void setNewPosition(float x, float y){
        setPosition(x ,y);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
    }
};