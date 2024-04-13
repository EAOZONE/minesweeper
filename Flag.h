#include "GameObject.h"
#include "States.h"

class Flag : public GameObject {
private:

public:
    State state;
    void setState(State state){
        this->state = state;
    }
    Flag(){
        setPosition(0,0);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
        setState(hidden);
    }
    Flag(Vector2f position){
        setPosition(position);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
        setState(hidden);
    }
    Flag(float x, float y){
        setPosition(x, y);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
        setState(hidden);
    }
};