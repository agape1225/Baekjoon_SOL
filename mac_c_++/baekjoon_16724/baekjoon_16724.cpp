#include <iostream>
#include <algorithm>

using namespace std;

int board[1005][1005];
int visited[1005][1005] = {0};
int visited_tmp[1005][1005] = {0};
int R, C;


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    int index = 0;

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < C; j++) {
            board[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!visited[i][j]) {
                
                // bool visited_tmp[1005][1005] = {0};
                int row = i;
                int col = j;

                ans++;
                index++;

                while(!visited[row][col]) {
                    visited_tmp[row][col] = index;
                    visited[row][col] = true;
                    // adjust coor
                if(board[row][col] == 'U') {
                    row--;
                }else if(board[row][col] == 'D') {
                    row++;
                }
                else if(board[row][col] == 'R') {
                    col++;
                }
                else if(board[row][col] == 'L') {
                    col--;
                }
                }

                if(visited_tmp[row][col] != visited_tmp[i][j]) {
                    ans--;
                }
                
            }
        }
    }

    cout << ans;
    return 0;
    
}