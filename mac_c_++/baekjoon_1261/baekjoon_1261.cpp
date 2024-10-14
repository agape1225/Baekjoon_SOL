#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int dir_x[4] = {0, 0, 1, -1};
    int dir_y[4] = {1, -1, 0, 0};
    int cache[105][105];
    string board[105];
    queue<pair<int, int>> q;
    int N, M;

    cin >> M >> N;

    for(int i = 0; i < N; i++){
        cin >> board[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cache[i][j] = 105 * 105 + 1;
        }
    }

    q.push(make_pair(0, 0));
    cache[0][0] = 0;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        int dis = cache[row][col];
        q.pop();

        for(int i = 0; i < 4; i++){
            int new_row = row + dir_x[i];
            int new_col = col + dir_y[i];

            if(new_row > -1 && new_row < N && new_col > -1 && new_col < M){
                if(board[new_row][new_col] == '1'){
                    if(cache[new_row][new_col] > dis + 1){
                        cache[new_row][new_col] = dis + 1;
                        q.push(make_pair(new_row, new_col));
                    }

                }else{

                    if(cache[new_row][new_col] > dis){
                        cache[new_row][new_col] = dis;
                        q.push(make_pair(new_row, new_col));
                    }

                }
            }
        }
    }

    cout << cache[N -1 ][M - 1];

    return 0;
    
}
