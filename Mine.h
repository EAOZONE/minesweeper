#include "GameObject.h"

class Mine : public GameObject {
private:
public:
    Mine(){
        setPosition(0,0);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
        setSprite();
}
    Mine(Vector2f position){
        setPosition(position);
}
    Mine(float x, float y){
        setPosition(x,y);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
        setSprite();
}
};