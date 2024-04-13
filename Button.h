#include "GameObject.h"

class Button : public GameObject {
private:
public:
    Button(){
        setPosition(0,0);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/face_happy.png");
        setSprite();
}
    Button(Vector2f position, int type) {
        this->position = position;
        if (type == 0) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/debug.png");
        } else if (type == 1) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_1.png");
        } else if (type == 2) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_2.png");
        } else if (type == 3) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_3.png");
        }
        setSprite();
    }
    Button(float x, float y, int type){
        setPosition(x, y);
        if (type == 0) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/debug.png");
        } else if (type == 1) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_1.png");
        } else if (type == 2) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_2.png");
        } else if (type == 3) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/test_3.png");
        }
        setSprite();
}
};