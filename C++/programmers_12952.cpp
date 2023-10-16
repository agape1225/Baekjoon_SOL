#include <string>
#include <vector>
#include <cmath>

using namespace std;

int board[12];
int answer = 0;
int max_row;

bool check_board(int row) {
    for (int i = 0; i < row; i++) {
        if (board[i] == board[row] || row - i == abs(board[row] - board[i]))
            return false;

    }
    return true;
}

void nQueen(int row) {

    if (row == max_row)
        answer++;
    else {
        for (int i = 0; i < max_row; i++) {
            board[row] = i;
            if (check_board(row)) {
                nQueen(row + 1);
            }
        }
    }
}

int solution(int n) {
    max_row = n;

    nQueen(0);

    return answer;
}