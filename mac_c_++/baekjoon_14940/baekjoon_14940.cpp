#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

    int board[1005][1005];
    bool visited[1005][1005] = {0};
    long long ans[1005][1005];

bool check_range(int row, int col, int max_row, int max_col){
    if(row < 0 || row >= max_row || col < 0 || col >= max_col)
        return false;
    return true;
}

int main(void){

    int N, M;
    queue<pair<int, int>> q;
    int start_pos, end_pos;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];

            if(board[i][j] == 2){
                start_pos = i;
                end_pos = j;
            }
        }
    }

    visited[start_pos][end_pos] = true;
    ans[start_pos][end_pos] = 0;
    q.push(make_pair(start_pos, end_pos));

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int next_row = row + dir_x[i];
            int next_col = col + dir_y[i];

            if(check_range(next_row, next_col, N, M) && !visited[next_row][next_col] && board[next_row][next_col] != 0){

                visited[next_row][next_col] = true;
                ans[next_row][next_col] = ans[row][col] + 1;

                q.push(make_pair(next_row, next_col));

            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            int num = ans[i][j];

            if(board[i][j] == 2){
                
            }else if(board[i][j] == 0){
                num = 0;
            }else if(num == 0){
                num = -1;
            }

            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}