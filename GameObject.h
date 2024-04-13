#include <SFML/Graphics.hpp>
using namespace sf;
class GameObject {
private:
public:
    Vector2f position;
    Texture texture;
    Sprite sprite;
    void setTexture(Texture texture){
        this->texture = texture;
        setSprite();
    }
    void setTexture(std::string textureFile){
        texture.loadFromFile(textureFile);
        setSprite();
    }
    void setPosition(Vector2f position){
        this->position = position;

    }
    void setPosition(float x, float y){
        this->position.x = x;
        this->position.y = y;
    }
    void setSprite(){
        this->sprite = Sprite(this->texture);
        this->sprite.setPosition(this->position.x, this->position.y);
    }
};