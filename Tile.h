#include "GameObject.h"
#include <string>
using namespace std;
using namespace sf;
class Tile : public GameObject{
private:
public:
    Tile(){
        setPosition(0, 0);
    }
    Tile(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }

    void mousePressed(Vector2i mousePosition){
    if (sf::Mouse::isButtonPressed(Mouse::Right) && sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/flag.png");
            setSprite();

        }
}
};