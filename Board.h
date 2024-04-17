#include "Leaderboard.h"


class Board{
private:
    vector<vector<Tile*>> board;
    int numOfRows;
    int numOfCols;
    int numOfBombs;
    int mouseState = 0;
    bool bombExploded;
public:
    Board(int numOfRows, int numOfCols, int numOfBombs){
        this->numOfRows = numOfRows;
        this->numOfCols = numOfCols;
        this->numOfBombs = numOfBombs;
    board.resize(numOfRows, vector<Tile*>(numOfCols, nullptr));
        for(int i = 0; i < numOfRows; i++){
            for(int j = 0; j<numOfCols; j++){
                board[i][j] = new Tile(i*32, j*32, "../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
            }
        }
}
~Board(){
        for(int i = 0; i <numOfRows; i++){
            for(int j = 0; j<numOfCols; j++){
                delete board[i][j];
            }
        }
    }
void setBombs(){
    int bombsPlaced = 0;
    while (bombsPlaced < numOfBombs){
        int row = rand() % numOfRows;
        int col = rand() % numOfCols;
        if(!board[row][col]->getIsMine()){
            board[row][col]->setIsMine(true);
            bombsPlaced++;
        }
        else{
            board[row][col]->setIsMine(false);
            bombsPlaced--;
        }

    }
}
void calculateNearbyBombs(){
    for(int i = 0; i <numOfRows; i++){
        for(int j = 0; j<numOfCols; j++){
            int bombCount = 0;
            int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for(int k = 0; k<8; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx >= 0 && nx < numOfRows && ny >= 0 && ny < numOfCols){
                    if(board[nx][ny]->getIsMine()){
                        bombCount++;
                    }
                }
            }
            board[i][j]->setBombCount(bombCount);
        }
    }
    }
    void mouseRightClicked(Vector2i mousePos, int i, int j) {
            if (board[i][j]->getState() == hidden) {
                board[i][j]->placeFlag(mousePos);
            } else if (board[i][j]->getState() == flag) {
                board[i][j]->removeFlag(mousePos);
            }
    }
    void openTile(Vector2i mousePos, int i, int j) {
        if (board[i][j]->getState() == hidden && board[i][j]->getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            board[i][j]->openBox(mousePos);
            if (board[i][j]->getBombCount() == 0 && !board[i][j]->getIsMine()) {
                openOtherTiles(i, j);
                board[i][j]->setState(revealed);
            }
            else if(board[i][j]->getIsMine()){
                bombExploded = true;
            }
        }
    }
    void openOtherTiles(int i, int j) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < numOfRows && ny >= 0 && ny < numOfCols){
                if(board[nx][ny]->getState() == hidden && !board[nx][ny]->getIsMine()){
                    board[nx][ny]->openBox();
                    if (board[nx][ny]->getBombCount() == 0) {
                        openOtherTiles(nx, ny);
                    }
                }
            }
        }
    }

    bool checkWin(){
        for(int i = 0; i < numOfRows; i++){
            for(int j = 0; j < numOfCols; j++){
                if(!board[i][j]->getIsMine()){
                    if(board[i][j]->getState() == hidden){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void setAllFlags(){
        for(int i = 0; i < numOfRows; i++){
            for(int j =0; j < numOfCols; j++){
                if(board[i][j]->getIsMine()){
                    board[i][j]->placeFlag();
                }
            }
        }
    }
    const vector<vector<Tile*>>& getBoard() const{
        return board;
    }
    void setMouseState(int mouseState){
        this->mouseState = mouseState;
    }
    int getMouseState(){
        return mouseState;
    }
    bool getBombExploded(){
        return bombExploded;
    }
    void setDebug(int i, int j){
        if(board[i][j]->getState() == hidden) {
            board[i][j]->setTexture("../Project 3 - Minesweeper Spring 2024/files/images/mine.png");
            board[i][j]->setSprite();
            board[i][j]->setState(revealed);
        }
        else if(board[i][j]->getState() == revealed){
            board[i][j]->setTexture("../Project 3 - Minesweeper Spring 2024/files/images/tile_hidden.png");
            board[i][j]->setSprite();
            board[i][j]->setState(hidden);
        }
    }
    void openAll(int i, int j){
        board[i][j]->setOpen();
    }
    void returnToNormal(int i, int j){
        board[i][j]->backToNormal();

    }
};