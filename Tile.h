#include "States.h"
#include "GameObject.h"
#include "MineCounter.h"
#include "Flag.h"

class Tile : public GameObject {
private:

public:
    std::vector<Tile*> adjacentTiles;
    MineCounter* counter;
    bool hasMine;
    State state;
    Flag* flag;
    Tile(){
        this->flag = new Flag();
        this->state = hidden;
        this->hasMine = false;
        GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
        setSprite();
        this->counter = new MineCounter();

    }
    ~Tile(){
        delete flag;
        delete counter;
    }
    Tile(State state, Vector2f position, bool hasMine){
        this->flag = new Flag(position);
        this->state = state;
        this->hasMine = hasMine;
        setPosition(position);
        if(state == hidden){
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
        }
        else{
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
        }
        setSprite();
        this->counter = new MineCounter();
    }
    Tile(State state, float x, float y, bool hasMine){
        this->flag = new Flag(x, y);
        this->state = state;
        this->hasMine = hasMine;
        setPosition(x, y);
        if(state == hidden){
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
        }
        else{
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
        }
        setSprite();
        this->counter = new MineCounter();
    }
    void setTexture(State state){
        if(state == hidden){
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
        }
        else{
            GameObject::setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_revealed.png");
        }
    }
    void setState(State state){
        this->state = state;
        this->setTexture(state);
    }
    void setHasMine(bool hasMine){
        this->hasMine = hasMine;
    }
    void uncoverAdjacent() {
        int count = 0;
        for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
            if (adjacentTiles[i]->hasMine) {
                count++;
            }
        }
        if (count != 0) {
            this->counter->setCount(count);
            this->counter->position = position;
        } else {
            for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
                if (adjacentTiles[i]->state == hidden) {
                    for (unsigned int j = 0; j < adjacentTiles[i]->adjacentTiles.size(); j++) {
                        if (!adjacentTiles[i]->adjacentTiles[j]->hasMine) {
                            if (adjacentTiles[i]->flag->state != revealed) {
                                adjacentTiles[i]->setState(revealed);
                                adjacentTiles[i]->uncoverAdjacent();
                            }
                        }
                    }
                }
            }
        }
    }
};