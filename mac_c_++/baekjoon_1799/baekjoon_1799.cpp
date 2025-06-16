#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> board(15, vector<int> (15));
queue<vector<vector<int>>, int> q;
int N;

int main(void) {

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout <<  board[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;

}