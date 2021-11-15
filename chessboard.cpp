#include <bits/stdc++.h>
#define forIJ(i, j, N) for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)
#define forI(i, N) for(int i = 0; i < N; ++i)
using namespace std;

// Default 0 empty
//         1 first player
//         2 second player

int firstPlayer = 1;
int secondPlayer = 2;
int boardDemension = 9;
class ChessBoard {     
  public:             
    int N;        // Board demension
    int board[100][100];  // Board
    // direction --, |, \, /
    int dx[4] = {1, 0, 1, -1};
    int dy[4] = {0, 1, 1, 1};
    ChessBoard(int n) {
        N = n;
        forIJ(i, j, N) {
            board[i][j] = 0;
        };
    }

    void showBoard() {
        forIJ(i, j, N){
            printf("%d ", board[i][j]);
            if (j==N-1) printf("\n");
        };
    }

    bool checkWin(int player) {
        // Check --
        forI(i, N){
            int count = 0;
            forI(j, N) {
                if (board[i][j] == player) ++count;
                else count = 0;
                if (count == 5) return true;
            }
        }
        // Check |
        forI(j, N) {
            int count = 0;
            forI(i, N) {
                if (board[i][j] == player) ++count;
                else count = 0;
                if (count == 5) return true;
            }
        }
        // Check \,
        forI(d, N){
            int j = d;
            int i = 0;
            int count = 0;
            for (; j < N; ++j, ++i){
                if (board[i][j] == player) ++count;
                else count = 0;
                if (count == 5) return true;
            }
        }
        forI(d, N){
            int i = d;
            int j = 0;
            int count = 0;
            for (; i < N; ++j, ++i){
                if (board[i][j] == player) ++count;
                else count = 0;
                if (count == 5) return true;
            }
        }
        // Check /
        for (int d=2*N-2; d>=0; --d){
            int count = 0;
            int j;
            for (int i = max(0, d+1-N); i < N; ++i) {
                j = d -i;
                if (board[i][j] == player) ++count;
                else count = 0;
                if (count == 5) return true;
            }
        }
        return false;
    }
};

ChessBoard getBoard1(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[0][1] = 1;
    board.board[0][2] = 1;
    board.board[0][3] = 1;
    board.board[0][4] = 1;
    board.board[0][5] = 1;
    return board;
}

ChessBoard getBoard2(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[1][1] = 1;
    board.board[2][2] = 1;
    board.board[3][3] = 1;
    board.board[4][4] = 1;
    board.board[5][5] = 1;
    return board;
}

ChessBoard getBoard3(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[2][1] = 1;
    board.board[3][2] = 1;
    board.board[4][3] = 1;
    board.board[5][4] = 1;
    board.board[6][5] = 1;
    return board;
}

ChessBoard getBoard4(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[0][1] = 1;
    board.board[1][2] = 1;
    board.board[2][3] = 1;
    board.board[3][4] = 1;
    board.board[4][5] = 1;
    return board;
}

ChessBoard getBoard5(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[0][4] = 1;
    board.board[1][5] = 1;
    board.board[2][6] = 1;
    board.board[3][7] = 1;
    board.board[4][8] = 1;
    return board;
}

ChessBoard getBoard6(){
    ChessBoard board(boardDemension);
    board.board[0][0] = 2;
    board.board[0][4] = 1;
    board.board[1][5] = 1;
    board.board[2][6] = 1;
    board.board[3][7] = 1;
    board.board[4][8] = 1;
    return board;
}

ChessBoard getBoard7(){
    ChessBoard board(boardDemension);
    board.board[6][3] = 2;
    board.board[1][8] = 1;
    board.board[2][7] = 1;
    board.board[3][6] = 1;
    board.board[4][5] = 1;
    board.board[5][4] = 1;
    return board;
}

ChessBoard getBoard8(){
    ChessBoard board(boardDemension);
    board.board[0][8] = 2;
    board.board[1][7] = 1;
    board.board[2][6] = 1;
    board.board[3][5] = 1;
    board.board[4][4] = 1;
    board.board[5][3] = 1;
    return board;
}
int main(){
    ChessBoard board = getBoard8();
    board.showBoard();
    cout << board.checkWin(1);
}