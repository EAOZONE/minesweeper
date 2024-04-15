#include "Tile.h"

class Button : public GameObject{
public:
    Button(){
        setPosition(0,0);
    }
    Button(float x, float y, string texture){
        setPosition(0, 0);
        setTexture(texture);
        setSprite();
    }
};