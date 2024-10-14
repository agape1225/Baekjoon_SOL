#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main(void){

    int ans = -1;
    bool board[105][105] = {0};
    bool visited[105][105] = {0};
    int N, M, K;
    queue<pair<int, pair<int, int>>> q;
    int dir_row[4] = {0, 1, 0, -1};
    int dir_col[4] = {1, 0, -1, 0};
    int row, col;

    cin >> N >> M >> K;

    for(int i = 0; i < K; i++){
            cin >> row >> col;
            board[row - 1][col - 1] = true;
    }



    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] && !visited[i][j]){
                
                q.push(make_pair( 1, make_pair(i , j) ));
                visited[i][j] = true;
                int tmp  = 1;

                while(!q.empty()){
                    int count = q.front().first;
                    int row = q.front().second.first;
                    int col = q.front().second.second;

                    q.pop();

                    // ans = max(ans, count);

                    // cout << row << ' ' << col << endl;

                    for(int k = 0; k < 4; k++){
                        int new_row = row + dir_row[k];
                        int new_col = col + dir_col[k];

                        if( new_row > -1 && new_row < N && new_col > -1 && new_col < M && !visited[new_row][new_col] && board[new_row][new_col]){
                            visited[new_row][new_col] = true;
                            tmp++;
                            q.push(make_pair(count + 1, make_pair(new_row, new_col)));
                        }
                    }
                    
                }

                ans = max(ans, tmp);
            }
        }
    }

    cout << ans;

    return 0;
}

