#include "GameObject.h"

class MineCounter : public GameObject {
private:

public:
    int count;
    Texture textures[8];
    Sprite sprites[8];
    MineCounter(){
        setPosition(0,0);
        this->count = 0;
        for(unsigned int i = 0; i < 8; i++){
            try {
                this->textures[i].loadFromFile("../Project 3 - Minesweeper Spring 2024/files/images/number_" + std::to_string(i + 1) + ".png");
            } catch (std::exception e) {}
            this->sprites[i] = Sprite(this->textures[i]);
            this->sprites[i].setPosition(position.x, position.y);
        }
    }
    MineCounter(float x, float y){
        setPosition(x,y);
        this->count = 0;
        for (unsigned int i = 0; i < 8; i++) {
            try {
                this->textures[i].loadFromFile("../Project 3 - Minesweeper Spring 2024/files/images/number_" + std::to_string(i + 1) + ".png");
            } catch (std::exception e) {}
            this->sprites[i] = Sprite(this->textures[i]);
            this->sprites[i].setPosition(position.x, position.y);
        }
    }
    MineCounter(int count, float x, float y){
        setPosition(x,y);
        this->count = count;
        for (unsigned int i = 0; i < 8; i++) {
            try {
                this->textures[i].loadFromFile("../Project 3 - Minesweeper Spring 2024/files/images/number_" + std::to_string(i + 1) + ".png");
            } catch (std::exception e) {}
            this->sprites[i] = Sprite(this->textures[i]);
            this->sprites[i].setPosition(position.x, position.y);
        }
    }
    void setCount(int count){
        this->count = count;
    }
};