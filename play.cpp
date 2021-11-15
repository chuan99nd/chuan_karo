#include "player.cpp"
class Game {
    public:
        Player* p1;
        Player* p2;
        Game(int N, Player* pl1, Player* pl2){
            ChessBoard board = ChessBoard(N);
            p1 = pl1;
            p2 = pl2;
            p1->board = &board;
            p2->board = &board;
        };
        
        void play(){
            ChessBoard* board = p1->board;
            printf("Start game %d!\n", board->N);
            board->reset();
            while (true) {
                p1->nextMove();
                board->showBoard();
                if (board->checkWin(p1->playerNo)){
                    printf("Player %d win\n", p1->playerNo);
                    break;
                }
                p2->nextMove();
                board->showBoard();
                if (board->checkWin(p2->playerNo)){
                    printf("Player %d win\n", p2->playerNo);
                    break;
                }
            }
        }
};
int main(){
    Human p1 = Human(1);
    Human p2 = Human(2);
    Game game(boardDemension, &p1, &p2);
    game.play();
}