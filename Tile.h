#include "GameObject.h"
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
    Tile(){
        setPosition(0, 0);
        isMine = false;
        state = hidden;
    }
    Tile(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        isMine = false;
        state = hidden;
    }

    void placeFlag(Vector2i mousePosition){
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
            setSprite();
            state = flag;
        }
    }
    void placeFlag(){
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
        setSprite();
        state = flag;
    }
    void removeFlag(Vector2i mousePosition){
        if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
            setSprite();
            state = hidden;

        }
    }
    void openBox(Vector2i mousePosition) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            if (isMine) {
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
                setSprite();
            }
            else if(bombCount == 0){
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
                setSprite();
            }
            else{
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/number_"+ to_string(bombCount)+".png");
                setSprite();
            }
            state = revealed;
        }
    }
    void openBox(){
        if(bombCount == 0){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
            setSprite();
        }
        else{
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/number_"+ to_string(bombCount)+".png");
            setSprite();
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
        setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
        setSprite();
    }

    void backToNormal(){
        if(state == flag){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
            setSprite();
        }
        else if(state != hidden) {
            if (isMine) {
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
                setSprite();
            } else if (bombCount == 0) {
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
                setSprite();
            } else {
                setTexture(
                        "../Project 3 - Minesweeper Spring 2024/files/images/number_" + to_string(bombCount) + ".png");
                setSprite();
            }
            state = revealed;
        }
        else{
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
            setSprite();
        }
    }
};