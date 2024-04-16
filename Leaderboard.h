#include "PausePlay.h"
#include <fstream>
#include <sstream>

class LeaderBoard : public Button {
private:
    map<string, string> leaderBoard;
public:
    LeaderBoard() {
        setPosition(0, 0);
    }

    LeaderBoard(float x, float y, string texture) {
        setPosition(x, y);
        setTexture(texture);
        setSprite();
    }

    void readTopFive(string file) {
        ifstream input_file(file);
        string line;
        if (!input_file.is_open()) {
            cerr << "Error opening the file.";
        }
        while (getline(input_file, line)) {
            istringstream iss(line);
            string name, number;
            getline(iss, number, ',');
            getline(iss, name);
            leaderBoard[name] = number;
        }
    }
    void buttonPressed(Vector2i mousePos){
    if(sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        for(const auto& pair : leaderBoard){
            cout<<pair.first<<": "<<pair.second;
        }
    }
    }

};