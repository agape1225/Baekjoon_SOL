#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <queue>

int dir_row[4] = {0, 1, 0, -1};
int dir_col[4] = {1, 0, -1, 0};

using namespace std;

bool check_range(int row, int col, int row_size, int col_size) {
    if(row < 0 || row >= row_size || col < 0 || col >= col_size) {
        return false;
    }
    return true;
}

void set_all_board(int board[55][55], int row_size, int col_size, int alphabet) {

    for(int row = 0; row < row_size; row++) {
        for(int col = 0; col < col_size; col++) {
            if(board[row][col] == alphabet) {
                board[row][col] = 0;
            }
        }
    }
    
}

void set_single_board(int board[55][55], int row_size, int col_size, int target_number) {
    
    bool visited[55][55] = {0};
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    
    while(!q.empty()) {
        
        int current_row = q.front().first;
        int current_col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_row = current_row + dir_row[i];
            int next_col = current_col + dir_col[i];
            
            if(check_range(next_row, next_col, row_size, col_size) && 
               !visited[next_row][next_col]) {
                if(board[next_row][next_col] == 0) {
                    visited[next_row][next_col] = true;
                    q.push(make_pair(next_row, next_col));
                }else if(board[next_row][next_col] == target_number) {
                    board[next_row][next_col] = 0;
                    visited[next_row][next_col]  = true;
                }
            }
        }
        
    }

    // for(int row = 0; row < row_size; row++) {
    //     for(int col = 0; col < col_size; col++) {
    //         if(board[row][col] == alphabet) {
    //             board[row][col] = 0;
    //         }
    //     }
    // }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int board[55][55] = {0};
    int row_size = storage.size() + 2;
    int col_size = storage[0].size() + 2;
    
    for(int row = 1; row <= storage.size(); row++) {
        for(int col = 1; col <= storage[0].size(); col++) {
            board[row][col] = storage[row - 1][col - 1];
        }
    }
    
    for(auto it : requests) {
        
        if(it.size() == 2) {
            set_all_board(board, row_size, col_size, it[0]);
                
        }else {
            set_single_board(board, row_size, col_size, it[0]);
        }
    }
    
    for(int row = 0; row < row_size; row++) {
        for(int col = 0; col < col_size; col++) {
            if(board[row][col] > 0) {
                answer++;
            }
            // cout << board[row][col] << ' ';
        }
        // cout << endl;
    }
    
    
    
    
    
    
    return answer;
}