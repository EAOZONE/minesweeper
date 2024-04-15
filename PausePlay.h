#include "DebugButton.h"

class PausePlay : public Button{
private:
    bool pause;
public:
    PausePlay(){
        setPosition(0,0);
        pause = false;
    }
    PausePlay(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        pause = false;
    }
    bool ButtonClciked(Vector2i mousePos){
        if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
            if(pause) {
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/play.png");
                setSprite();
                pause = false;
            }
            else{
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/pause.png");
                setSprite();
                pause = true;
            }

            return true;
        }
        return false;
    }
    bool getPause(){
        return pause;
    }
};