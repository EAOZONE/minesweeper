#include "Tile.h"

class Button : public GameObject{
    Button(){
        setPosition(0,0);
    }
    Button(float x, float y, string texture){
        setPosition(0, 0);
        setTexture(texture);
        setSprite();
    }
};