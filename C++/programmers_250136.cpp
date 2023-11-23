#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dir_x[4] = {0 ,1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool check_range(int row, int col, int max_row, int max_col){
    if(row < 0 || row >= max_row || col < 0 || col >= max_col)
        return false;
    return true;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<pair<pair<int, int>, int>> dic;
    
    int row_size = land.size();
    int col_size = land[0].size();
    
    //덩어리 찾기
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            //탐색 시작
            if(land[i][j] == 1){
                queue<pair<int, int>> q;
                int start_col = j;
                int end_col = j;
                int count = 0;
                land[i][j] = 0;
                q.push(make_pair(i, j));
                
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    //cout << "cor: " << row << ' ' << col << endl;
                    count++;
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int next_row = row + dir_x[k];
                        int next_col = col + dir_y[k];
                        
                        if(check_range(next_row, next_col, row_size, col_size) &&
                          land[next_row][next_col] == 1){
                            land[next_row][next_col] = 0;
                            start_col = min(start_col, next_col);
                            end_col = max(end_col, next_col);
                            q.push(make_pair(next_row, next_col));
                        }
                    }
                }
                
                dic.push_back(make_pair(make_pair(start_col, end_col), count));
            }
        }
    }
    // for(auto it : dic){
    //     cout << it.first.first << ' ' << it.first.second << ' ' << it.second << endl;
    // }
    for(int i = 0; i < col_size; i++){
        int tmp = 0;
        for(auto it : dic){
            if(it.first.first <= i && it.first.second >= i)
                tmp += it.second;
        }
        answer = max(answer, tmp);
    }
    
    return answer;
}
