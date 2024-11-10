#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int board[1005][1005];
int visited[1005][1005];
int N, M;
int H, W, start_row, start_col, end_row, end_col;
vector<pair<int, int>> walls;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool check_range(int row, int col){
    if(row < 0 || row >= N || col < 0 || col >= M){
        return false;
    }

    if(row + H - 1 >= N || col + W - 1>= M)
        return false;
    
    if(visited[row][col] == true){
        return false;
    }
    // for(int i = row; i < row + H; i++){
    //     for(int j = col; j < col + W; j++){

    //         if(i >= N || j >= M){
    //             return false;
    //         }

    //         if(board[i][j] == 1){
    //             return false;
    //         }
            
    //     }
    // }

    for(auto it : walls){
        if(row <= it.first && it.first< row + H && col <= it.second && it.second < col + W)
            return false;
    
    }

    return true;
    
}

int main() {

    
    queue<pair<pair<int, int>, int>> q;
    int ans = -1;
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];

            if(board[i][j] == 1){
                walls.push_back(make_pair(i, j));
            }
        }
    }

    cin >> H >> W >> start_row >> start_col >> end_row >> end_col;
    start_row--;
    start_col--;
    end_row--;
    end_col--;

    visited[start_row][start_col] = true;
    q.push(make_pair(make_pair(start_row, start_col) , 0));

    while(!q.empty()){

        int row = q.front().first.first;
        int col = q.front().first.second;
        int count = q.front().second;

        q.pop();

        if(row == end_row && col == end_col){
            if(ans == -1){
                ans = count;
            }else{
                ans = min(ans, count);
            }
            cout << ans;
            return 0;
            // continue;
        }

        for(int i = 0; i < 4; i++){
            int new_row = row + dir_x[i];
            int new_col = col + dir_y[i];

            if(check_range(new_row, new_col)){

                // cout << new_row << ' ' << new_col << endl;
                
                visited[new_row][new_col] = true;
                q.push(make_pair(make_pair(new_row, new_col) , count + 1));
            }
        }
        
        
    }

    cout << ans;
    
    
    return 0;
}
