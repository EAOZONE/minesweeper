#include "Button.h"

class DebugButton : public Button{
private:
    bool debugActive = false;
public:
    DebugButton(){
        setPosition(0, 0);
    }
    DebugButton(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }
    bool buttonPressed(Vector2i mousePos){
        if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
            return true;
        }
        return false;
    }
    bool getDebugActive(){
        return debugActive;
    }
    void setDebugActive(bool debugActive){
        this->debugActive = debugActive;
    }
};