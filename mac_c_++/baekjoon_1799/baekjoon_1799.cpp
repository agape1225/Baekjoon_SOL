#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> board(15, vector<int> (15));
queue<vector<vector<int>>, int> q;
int N;
int col[15] = {0};
int ans = 0;

int black_ans = 0;
int white_ans = 0;

void get_ans() {

}

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

    get_ans(1);

    cout << ans;

    return 0;

}