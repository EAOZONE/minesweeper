#include "FaceButton.h"
#include "iostream"

class Counter : public GameObject{
private:
    Sprite sprites[3];
    int digits[3];
public:
    Counter(){

    }
    Counter(float x, float y, int numOfBombs, int numOfRows) {
        int update = numOfBombs;
        digits[2] = update % 10;
        update = update / 10;
        digits[1] = update % 10;
        update = update / 10;
        digits[0] = update % 10;
        sf::Texture texture;
        texture.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/images/digits.png");
        this->sprites[0] = Sprite(texture);
        this->sprites[1] = Sprite(texture);
        this->sprites[2] = Sprite(texture);
        this->sprites[0].setPosition(33, 32 * (numOfRows + .5) + 16);
        this->sprites[1].setPosition(54, 32 * (numOfRows + .5) + 16);
        this->sprites[2].setPosition(75, 32 * (numOfRows + .5) + 16);
        this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
        this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
        this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
    }
        void subtract() {
        if (this->digits[2] != 0 && this->digits[1] != 0 && this->digits[0] != 10) {
            this->digits[2]--;
        } else if (this->digits[2] == 0 && this->digits[1] != 0 && this->digits[0] != 10) {
            this->digits[2] = 9;
            this->digits[1]--;
        } else if (this->digits[1] == 0 && this->digits[0] == 0 && this->digits[2] != 0) {
            this->digits[2]--;
        } else if (this->digits[2] == 0 && this->digits[1] == 0 && this->digits[0] == 0) {
            this->digits[0] = 10;
            this->digits[1] = 0;
            this->digits[2]++;
        } else if (this->digits[0] == 10 && this->digits[2] != 9) {
            this->digits[2]++;
        } else if (this->digits[0] == 10 && this->digits[2] == 9) {
            this->digits[2] = 0;
            this->digits[1]++;
        } else if (this->digits[0] == 10 && this->digits[2] == 0 && this->digits[1] > 0) {
            this->digits[2]++;
        }
            this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
            this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
            this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
    }
    void add(){
        if (this->digits[2] != 9 && this->digits[0] != 10) {
            this->digits[2]++;
        } else if (this->digits[2] == 9 && this->digits[0] != 10){
            this->digits[2] = 0;
            this->digits[1]++;
        } else if (this->digits[2] <= 9 && this->digits[0] == 10 && this->digits[1] == 0) {
            this->digits[2]--;
            if (this->digits[2] == 0) {
                this->digits[0] = 0;
            }
        } else if (this->digits[2] == 0 && this->digits[0] == 10 && this->digits[1] > 0) {
            this->digits[2] = 9;
            this->digits[1]--;
        } else if (this->digits[2] != 9 && this->digits[0] == 10 && this->digits[1] > 0) {
            this->digits[2]--;
        }
        this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
        this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
        this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
    }
    Sprite* getDigits(){
        return sprites;
    }
};