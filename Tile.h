#include "GameObject.h"
#include <string>
using namespace std;
using namespace sf;
class Tile : public GameObject{
private:
public:
    bool isMine;
    Tile(){
        setPosition(0, 0);
        isMine = false;
    }
    Tile(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        isMine = false;
    }

    void placeFlag(Vector2i mousePosition){
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
            setSprite();
        }
    }
    void openBox(Vector2i mousePosition) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            if (isMine) {
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
                setSprite();
            }
            else{
                setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
                setSprite();
            }
        }
    }
    void setIsMine(bool isMine){
        this->isMine = isMine;
    }
};