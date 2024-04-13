#include "GameObject.h"
class Tile : public GameObject{
private:
public:
    Vector2f position;
    Texture texture;
    Sprite sprite;
    Tile(){
        setPosition(0, 0);
    }
    Tile(Vector2f position, Texture texture){
        this->position = position;
        this->texture = texture;
        setSprite();
    }
};