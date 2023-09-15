#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool check_square(vector<vector<int>> board, int start_row, int start_col, int size){
    int index_row = start_row + size ;
    int index_col = start_col + size ;
    
    //cout << index_row << ' ' << index_col << ' ' << size << endl;
    for(int i = start_col; i < index_col; i++){
        //cout << index_row << ' ' << i << "--" << endl;
        if(board[index_row][i] == 0)
            return false;
    }
    
    for(int i = start_row; i < index_row; i++){
        
        //cout << i << ' ' << index_col << "--" << endl;
        if(board[i][index_col] == 0)
            return false;
    }
    
    if(board[index_row][index_col] == 0)
        return false;
    
    //cout << "---------------------------" << endl;
    
    return true;
}

//백트레킹 해야할듯
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row_size = board.size();
    int col_size = board[0].size();
    
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            
            if(board[i][j] == 1 && row_size - i > answer && col_size - j > answer){
                int tmp = 1;
                int len_size = min(row_size - i, col_size - j);
                
                for(int len = 1; len < len_size; len++){
                    //cout << len << " : " << endl;
                    if(check_square(board, i, j , len)){
                        tmp++;
                    }
                    answer = max(answer, tmp);
                }
            }
        }
    }
    
    return answer * answer;
}
