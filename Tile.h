#include "Flag.h"
#include "States.h"
#include <string>
using namespace std;
using namespace sf;
class Tile : public GameObject{
private:
    type state;
    bool isMine;
    int bombCount;
    vector<Tile*> adjacentTiles;
public:
    numberTile numberSprite = numberTile();
    Flag flagSprite = Flag();
    Mine mineSprite = Mine();
    Tile(){
        setPosition(0, 0);
        isMine = false;
        state = hidden;
        flagSprite.setNewPosition(0, 0);
        numberSprite.setNewPosition(0, 0, "../files/images/tile_revealed.png");
        mineSprite.setNewPosition(0, 0);
    }
    Tile(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        isMine = false;
        state = hidden;
        flagSprite.setNewPosition(x, y);
        numberSprite.setNewPosition(x, y, "../files/images/tile_revealed.png");
        mineSprite.setNewPosition(x, y);
    }

    bool placeFlag(Vector2i mousePosition){
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            state = flag;
            return true;
        }
        return false;
    }
    bool placeFlag(){
        state = flag;
        return true;
    }


    bool removeFlag(Vector2i mousePosition){
        if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            setTexture("../files/images/tile_hidden.png");
            setSprite();
            state = hidden;
            return true;
        }
        return false;
    }
    void openBox(Vector2i mousePosition) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            if(bombCount == 0 || isMine){
                setTexture("../files/images/tile_revealed.png");
                setSprite();
            }
            else{
                setTexture("../files/images/tile_revealed.png");
                setSprite();
                numberSprite.setNewTexture("../files/images/number_"+ to_string(bombCount)+".png");

            }
            state = revealed;
        }
    }
    void openBox(){
        if(bombCount == 0){
            setTexture("../files/images/tile_revealed.png");
            setSprite();
        }
        else{
            setTexture("../files/images/tile_revealed.png");
            setSprite();
            numberSprite.setNewTexture("../files/images/number_"+ to_string(bombCount)+".png");
        }
        state = revealed;
    }
    bool getIsMine(){
        return isMine;
    }
    void setIsMine(bool isMine){
        this->isMine = isMine;
    }
    void setBombCount(int bombCount){
        this->bombCount = bombCount;
    }
    type getState(){
        return state;
    }
    void setState(type state){
        this->state = state;
    }
    int getBombCount(){
        return bombCount;
    }
    sf::Sprite getSprite(){
        return sprite;
    }
    void setOpen(){
        setTexture("../files/images/tile_revealed.png");
        setSprite();
    }

    void backToNormal(){
        if(state == flag){
            setTexture("../files/images/tile_hidden.png");
            setSprite();
        }
        else if(state != hidden) {
            if (bombCount == 0) {
                setTexture("../files/images/tile_revealed.png");
                setSprite();
            } else {
                setTexture("../files/images/tile_revealed.png");
                setSprite();
                numberSprite.setNewTexture("../files/images/number_"+ to_string(bombCount)+".png");
            }
            state = revealed;
        }
        else{
            setTexture("../files/images/tile_hidden.png");
            setSprite();
        }
    }
};