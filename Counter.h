#include "FaceButton.h"
#include "iostream"

class Counter : public GameObject{
private:
    Sprite sprites[3];
    int digits[3];
    int numOfBombs;
public:
    Counter(int numOfBombs, int numOfCols) {
        this->numOfBombs = numOfBombs;
        int update = numOfBombs;
        this->digits[2] = update % 10;
        update = update / 10;
        this->digits[1] = update % 10;
        update = update / 10;
        this->digits[0] = update % 10;
        setPosition(33, (numOfCols+.5)*32 + 16);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/digits.png");
        this->sprites[0] = Sprite(texture);
        this->sprites[1] = Sprite(texture);
        this->sprites[2] = Sprite(texture);
        this->sprites[0].setPosition(position);
        this->sprites[1].setPosition(position.x+21, position.y);
        this->sprites[2].setPosition(position.x+42, position.y);
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
    void reset(){
        int update = numOfBombs;
        this->digits[2] = update % 10;
        update = update / 10;
        this->digits[1] = update % 10;
        update = update / 10;
        this->digits[0] = update % 10;
        this->sprites[0].setTextureRect(IntRect(0 + 21 * this->digits[0], 0, 21, 32));
        this->sprites[1].setTextureRect(IntRect(0 + 21 * this->digits[1], 0, 21, 32));
        this->sprites[2].setTextureRect(IntRect(0 + 21 * this->digits[2], 0, 21, 32));
    }
    Sprite getDigits(int i){
        return this->sprites[i];
    }
};