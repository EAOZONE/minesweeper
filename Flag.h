#include "numberTile.h"

class Flag : public GameObject{
public:
    Flag(){
        setPosition(0, 0);
        setTexture("../files/images/flag.png");
        setSprite();
    }
    Flag(float x, float y){
        setPosition(x, y);
        setTexture("../files/images/flag.png");
        setSprite();
    }
    void setNewPosition(float x, float y){
        setPosition(x ,y);
        setTexture("../files/images/flag.png");
        setSprite();
    }

};