#include <bits/stdc++.h>
#include "chessboard.cpp"
using namespace std;
class Player {
    public:
        ChessBoard* board;
        int playerNo;
        Player() {};
        Player(int player){
            playerNo = player;
        };
        virtual void nextMove() {
             printf("Virtual\n");
        }; 
};

class Human : public Player {
    public:
        explicit Human(int x) : Player(x){}
        void nextMove(){
            int x, y;
            do {
                printf("Player %d: ", playerNo);
                cin >> x >> y;
            } while (!board->checkValidPoint(x, y));
            board->board[x][y] = playerNo;
        };
};