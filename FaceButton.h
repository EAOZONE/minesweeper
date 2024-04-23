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
    bool buttonClicked(Vector2i mousePos){
        if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
            return true;
        }
        return false;
    }
    void gameWon(){
        setTexture("../files/images/face_win.png");
        setSprite();
    }
    void gameLose(){
        setTexture("../files/images/face_lose.png");
        setSprite();
    }
    void gameActive(){
        setTexture("../files/images/face_happy.png");
        setSprite();
    }
};