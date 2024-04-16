#include "PausePlay.h"
class LeaderBoard : public Button{
public:
    LeaderBoard(){
        setPosition(0,0);
    }
    LeaderBoard(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }
    bool buttonPressed(){}
};