#include <string>
#include <vector>

using namespace std;

bool is_range(int max_row, int max_col, int row, int col){
    if(row < 0 || row >= max_row || col < 0 || col >= max_col)
        return false;
    return true;
}

int get_ans(vector<vector<string>> board, int h, int w){
    int dir_x[4] = {1, 0, -1, 0};
    int dir_y[4] = {0, 1, 0, -1};
    
    int count = 0;
    
    for(int i = 0; i < 4; i++){
        int row = h + dir_x[i];
        int col = w + dir_y[i];
        
        if(is_range(board.size(), board[0].size(), row, col)){
            if(board[h][w] == board[row][col])
                count++;
        }
    }
    
    return count;
    
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    answer = get_ans(board, h, w);
    
    return answer;
}
