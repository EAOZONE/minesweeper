#include "DebugButton.h"

class PausePlay : public Button{
private:
    bool pause;
public:
    PausePlay(){
        setPosition(0,0);
        pause = false;
    }
    PausePlay(float x, float y, string texture){
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        pause = false;
    }
    bool ButtonClicked(Vector2i mousePos) {
        // Check if the mouse position is within the bounds of the button
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            // Toggle the pause state
            pause = !pause;

            return true;
        }
        return false;
    }

    void updateButtonTexture() {
        // Update the button texture based on the current pause state
        if (pause) {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/play.png");
        } else {
            setTexture("../Project 3 - Minesweeper Spring 2024/files/images/pause.png");
        }

        // Update the sprite to reflect the new texture
        setSprite();
    }
    bool getPause(){
        return pause;
    }
};