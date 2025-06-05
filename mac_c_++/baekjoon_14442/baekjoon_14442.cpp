#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int visited[1005][1005][15] = {0};
char board[1005][1005] = {0};

int dir_row[4] = {0, 1, 0, -1};
int dir_col[4] = {1, 0, -1, 0};

bool check_range(int row, int col, int N, int M) {
    if(row < 0 || row >= N || col < 0 || col >= M) {
        return false;
    }
    return true;
}

int main(void) {
    int N, M, K;
    int ans = -1;
    queue<pair<pair<int, int> ,pair<int,int>>> q;
    cin >> N >> M >> K;

    // cout << "2";
    

    for(int row = 0; row < N; row++) {
        string tmp;
        cin >> tmp;
        for(int col = 0; col < M; col++) {
            board[row][col] = tmp[col];
        }
    }

    // cout << " 1";

    visited[0][0][0] = true;
    q.push(make_pair(make_pair(0, 1), make_pair(0, 0)));

    while (!q.empty()){

        int break_count = q.front().first.first;
        int count = q.front().first.second;
        int current_row = q.front().second.first;
        int current_col = q.front().second.second;

        q.pop();

        // cout << count << endl;

        if(current_row == N - 1 && current_col == M - 1) {
            ans = count;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int next_row = current_row + dir_row[i];
            int next_col = current_col + dir_col[i];

            if(check_range(next_row, next_col, N, M)) {
                if(board[next_row][next_col] == '1') {
                    if(break_count + 1 <= K) {
                        
                        if(!visited[next_row][next_col][break_count + 1]) {
                            visited[next_row][next_col][break_count + 1] = true;
                            q.push(
                                make_pair(
                                    make_pair(break_count + 1, count + 1),
                                    make_pair(next_row, next_col)
                                )
                            );
                        }

                    }
                }else {
                    if(!visited[next_row][next_col][break_count]){
                        visited[next_row][next_col][break_count] = true;
                        q.push(
                                make_pair(
                                    make_pair(break_count, count + 1),
                                    make_pair(next_row, next_col)
                                )
                            );
                    }

                }
            }
        }

    }

    cout << ans;

    return 0;
    
}