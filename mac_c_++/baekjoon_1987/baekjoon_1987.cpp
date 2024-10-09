#include <iostream>
#include <string>

using namespace std;

int R, C;
char board[25][25] = {0};
bool visited[26] = {0};
int ans = -1;

int dir_x[4] = {0 ,1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int get_index(char c){
    return 'A' - c;
}

bool check_range(int row, int col){
    return row >= 0 && row < R && col >= 0 && col < C;
}

void dfs(int row, int col, int count){
    ans = max(ans, count);

    for(int i = 0; i < 4; i++){
        int new_x = dir_x[i] + row;
        int new_y = dir_y[i] + col;

        if(check_range(new_x, new_y)){
            char next_char = board[new_x][new_y];
            int index = get_index(next_char);
            if(!visited[index]){
                visited[index] = true;
                dfs(new_x, new_y, count + 1);
                visited[index] = false;
            }
        }
    }

}

int main(void){
    
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    visited[get_index(board[0][0])] = true;
    dfs(0, 0, 1);

    cout << ans;

    return 0;

}