#include "PausePlay.h"
#include <fstream>
#include <sstream>
#include <iomanip>

class LeaderBoard : public Button {
private:
    string leaderBoard;
    sf::Font font;
    map<string, int> leaderBoardTimes;
    bool updated = false;
public:
    LeaderBoard() {
        setPosition(0, 0);
    }

    LeaderBoard(float x, float y, string texture) {
        setPosition(x, y);
        setTexture(texture);
        setSprite();
        font.loadFromFile("../Project 3 - Minesweeper Spring 2024/files/font.ttf");
    }

    void readTopFive(string file) {
        leaderBoard = "";
        ifstream input_file(file);
        string line;
        if (!input_file.is_open()) {
            cerr << "Error opening the file.";
        }
        int numOfIters = 1;
        while (getline(input_file, line)) {
            istringstream iss(line);
            string name;
            string minutes;
            string seconds;
            getline(iss, minutes, ':');
            getline(iss, seconds, ',');
            getline(iss, name);
            leaderBoardTimes[name] = stoi(minutes+seconds);
            leaderBoard += to_string(numOfIters);
            leaderBoard += ".";
            leaderBoard += "\t";
            leaderBoard += name;
            leaderBoard += "\t";
            leaderBoard += minutes;
            leaderBoard += ":";
            leaderBoard += seconds;
            leaderBoard += "\n\n";
            numOfIters++;

        }
    }
    void buttonPressed(Vector2i mousePos, int numOfCols, int numOfRows) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            sf::RenderWindow window(sf::VideoMode(numOfCols * 16, numOfRows * 16 + 50), "Leaderboard");
            while (window.isOpen()) {
                sf::Event event{};
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    sf::Text leaderBoardLine = drawWord("LeaderBoard", numOfCols*8, numOfRows*8-120, 20);
                    sf::Text leaderBoardContents = drawWord(leaderBoard, numOfCols*8, numOfRows*8 + 20, 18);
                    window.clear(sf::Color::Blue);
                    window.draw(leaderBoardLine);
                    window.draw(leaderBoardContents);
                    window.display();
                }
            }
        }
    }
    sf::Text drawWord(const string& word, float pos_x, float pos_y, int size){
        sf::Text text(word, font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::White);
        setText(text, pos_x, pos_y);
        return text;
    }
    void checkTime(int minutes, int seconds, string name){
        updated = true;
        leaderBoardTimes[" "+name] = stoi(to_string(minutes)+ to_string(seconds));
        std::vector<std::pair<string, int>> vec(leaderBoardTimes.begin(), leaderBoardTimes.end());

        // Sort the vector based on the values
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        vec.pop_back();
        leaderBoardTimes.clear();
        for(const auto& pair: vec){
            leaderBoardTimes[pair.first] = pair.second;
            cout<<pair.first<< ":"<<pair.second<<endl;
        }
        rewriteLeaderboardFile();
        readTopFive("../Project 3 - Minesweeper Spring 2024/files/leaderboard.txt");
    }

    void rewriteLeaderboardFile(){
        ofstream output_file("../Project 3 - Minesweeper Spring 2024/files/leaderboard.txt");
        for(const auto& pair : leaderBoardTimes){
            output_file<<setw(2)<<setfill('0')<<pair.second/100 <<":"<<setw(2)<<setfill('0')<<pair.second%100<<","<<pair.first<<endl;
        }
        output_file.close();
    }
    bool getUpdated(){
        return updated;
    }

};