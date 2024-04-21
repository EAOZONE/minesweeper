#include "Counter.h"
class Timer : public GameObject{
private:
    Sprite minutes[2];
    int minutesInt[2];
    Sprite seconds[2];
    int secondsInt[2];

public:
    Timer(float x, float y, int numOfCols, int numOfRows){
        this->minutesInt[0] = 0;
        this->minutesInt[1] = 0;
        this->secondsInt[0] = 0;
        this->secondsInt[1] = 0;
        setPosition(x, y);
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/digits.png");
        this->minutes[0] = Sprite(texture);
        this->minutes[1] = Sprite(texture);
        this->seconds[0] = Sprite(texture);
        this->seconds[1] = Sprite(texture);
        this->minutes[0].setPosition(position);
        this->minutes[1].setPosition(position.x+21,position.y);
        this->seconds[0].setPosition((numOfCols*32)-54, 32*(numOfRows+0.5)+16);
        this->seconds[1].setPosition(seconds[0].getPosition().x+21, seconds[0].getPosition().y);
        this->minutes[0].setTextureRect(IntRect(0 + 21 * this->minutesInt[0], 0, 21, 32));
        this->minutes[1].setTextureRect(IntRect(0 + 21 * this->minutesInt[1], 0, 21, 32));
        this->seconds[0].setTextureRect(IntRect(0 + 21 * this->secondsInt[0], 0, 21, 32));
        this->seconds[1].setTextureRect(IntRect(0 + 21 * this->secondsInt[1], 0, 21, 32));
    }
    void update(int seconds, int minutes){
        int secondsUpdate = seconds;
        this->secondsInt[1] = secondsUpdate % 10;
        secondsUpdate = secondsUpdate / 10;
        this->secondsInt[0] = secondsUpdate % 10;
        int minutesUpdate = minutes;
        this->minutesInt[1] = minutesUpdate % 10;
        minutesUpdate = minutesUpdate / 10;
        this->minutesInt[0] = minutesUpdate % 10;
        this->minutes[0].setTextureRect(IntRect(0 + 21 * this->minutesInt[0], 0, 21, 32));
        this->minutes[1].setTextureRect(IntRect(0 + 21 * this->minutesInt[1], 0, 21, 32));
        this->seconds[0].setTextureRect(IntRect(0 + 21 * this->secondsInt[0], 0, 21, 32));
        this->seconds[1].setTextureRect(IntRect(0 + 21 * this->secondsInt[1], 0, 21, 32));
    }
    sf::Sprite getMinutes(int i){
        return minutes[i];
    }
    sf::Sprite getSeconds(int i){
        return seconds[i];
    }
};