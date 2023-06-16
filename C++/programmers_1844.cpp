#include<vector>
#include <queue>
#include <utility>


using namespace std;

bool check_range(int x, int y, int row_size, int col_size){
    
    if(x < 0 || x >= row_size || y < 0 || y > col_size)
        return false;
    return true;
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    vector<vector<int>> visited;
    
    int x_dir[4] = {0, 1, 0, -1};
    int y_dir[4] = {1, 0, -1, 0};
    
    int row_size = maps.size();
    int col_size = maps[0].size();
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < row_size; i++){
        vector<int> buff;
        for(int j = 0; j < col_size; j++){
            buff.push_back(-1);
        }
        visited.push_back(buff);
    }
    
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    
    while(!q.empty()){
        
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int buff_row = row + x_dir[i];
            int buff_col = col + y_dir[i];
            if(check_range(buff_row, buff_col, row_size, col_size) && visited[buff_row][buff_col] == -1 && maps[buff_row][buff_col]){
                visited[buff_row][buff_col] = visited[row][col] + 1;;
                q.push(make_pair(buff_row, buff_col));
            }
        }
        
    }
    
    
    answer = visited[row_size - 1][col_size - 1];
    
    return answer;
}
