#include "GameObject.h"
#include <string>
using namespace std;
class numberTile : public GameObject{
public:
    numberTile(){
        setPosition(0, 0);
    }
    numberTile(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }
    void setNewPosition(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }
    void setNewTexture(string texture){
        setTexture(texture);
        setSprite();
    }
};