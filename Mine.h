#include "GameObject.h"
using namespace std;
class Mine : public GameObject{
public:
    Mine(){
        setPosition(0, 0);
        setTexture("../files/images/mine.png");
        setSprite();
    }
    Mine(float x, float y){
        setPosition(x, y);
        setTexture("../files/images/mine.png");
        setSprite();
    }
    void setNewPosition(float x, float y){
        setPosition(x, y);
        setTexture("../files/images/mine.png");
        setSprite();
    }
};