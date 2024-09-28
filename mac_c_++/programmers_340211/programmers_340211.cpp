#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

bool is_system_end(vector<pair<int, pair<int, int>>> coordinate){
    for(auto it : coordinate){
        if(it.second.first != -1 || it.second.second != -1)
            return false;
    }
    return true;   
}

int count_crash(vector<pair<int, pair<int, int>>> coordinate){
    int board[105][105] = {0};
    int count = 0;
    
    for(auto it : coordinate){
        if(it.second.first != -1 && it.second.second)
            board[it.second.first][it.second.second]++;
    }
    
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            if(board[i][j] > 1){
                count++;
            }
        }
    }
    return count;
}

vector<pair<int, pair<int, int>>> update_coordinate(
    vector<pair<int, pair<int, int>>> coordinate, 
    vector<vector<int>> points, 
    vector<vector<int>> routes)
    {
    
    vector<pair<int, pair<int, int>>> new_coordinate;
    
    for(int i = 0; i < coordinate.size(); i++){
        
        int cur_target_index = coordinate[i].first;
        int cur_row = coordinate[i].second.first;
        int cur_col = coordinate[i].second.second;

        if(cur_target_index != -1){
            int target_point = routes[i][cur_target_index];
            int target_row = points[target_point - 1][0];
            int target_col = points[target_point - 1][1];
        
            if(cur_row != target_row){
                
                if(cur_row < target_row)
                    cur_row++;
                else
                    cur_row--;
            
            }else if(cur_col != target_col){
                if(cur_col < target_col)
                    cur_col++;
                else
                    cur_col--;  
            }
            
            if(cur_row == target_row && cur_col == target_col){
                cur_target_index++;

                if(cur_target_index == routes[i].size())
                    cur_target_index = -1;
            }
        }else{
            cur_row = -1;
            cur_col = -1;
        }
        new_coordinate.push_back(make_pair(cur_target_index, make_pair(cur_row, cur_col)));
    }
    
    return new_coordinate;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, pair<int, int>>> coordinate;
    
    // 로봇 배치
    for(int i = 0; i < routes.size(); i++){
        int start_point = routes[i][0];
        int r = points[start_point - 1][0];
        int c = points[start_point - 1][1];
        coordinate.push_back(make_pair(1 , make_pair(r, c)));
    }
    
    while(!is_system_end(coordinate)){
        
        //result count
        int count = count_crash(coordinate);
        answer += count;
        
        //update coordinate
        coordinate = update_coordinate(coordinate, points, routes);        
    }
    
    return answer;
}