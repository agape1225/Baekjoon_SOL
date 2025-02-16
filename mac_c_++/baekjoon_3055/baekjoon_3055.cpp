#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dir_row[4] = {0, 1, 0, -1};
int dir_col[4] = {1, 0, -1, 0};

bool check_range(int row, int col, int max_row, int max_col){
    if(row < 0 || row >= max_row || col < 0 || col >= max_col){
        return false;
    }
    return true;
}

vector<vector<char>> set_water(vector<vector<char>> map, int R, int C) {
    vector<pair<int, int>> water_list;
    vector<vector<char>> new_map = map;

    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            if(map[row][col] == '*'){
                water_list.push_back(make_pair(row, col));
            }
        }
    }

    for(auto it : water_list) {
        for(int i = 0; i < 4; i++) {
            int next_row = it.first + dir_row[i];
            int next_col = it.second + dir_col[i];

            if(check_range(next_row, next_col , R, C) && map[next_row][next_col] != 'X' && map[next_row][next_col] != 'D'){
                new_map[next_row][next_col] = '*';
            }
        }
    }

    return new_map;
    
}


int main(void) {
    int R, C;
    int ans = -1;
    cin >> R >> C;

    queue < pair<pair<int, vector<vector<char>>>, pair<int, int>> > q;
    vector<vector<char>> v;
    bool visited[55][55] = {0};
    int start_row, start_col;

    for(int i = 0; i < R; i++) {
        vector<char> v_tmp;
        for(int j = 0; j < C; j++){
            char tmp;
            cin >> tmp;
            if(tmp == 'S'){
                start_row = i;
                start_col = j;
            }
            v_tmp.push_back(tmp);
            
        }
        v.push_back(v_tmp);
    }

    q.push(make_pair(make_pair(0, v), make_pair(start_row, start_col)));
    visited[start_row][start_col] = true;


    while(!q.empty()) {
        vector<vector<char>> current_map = q.front().first.second;
        int current_count = q.front().first.first;
        int current_row = q.front().second.first;
        int current_col = q.front().second.second;

        q.pop();

        // 답 먼저
        if(current_map[current_row][current_col] == 'D'){
            if(ans == -1){
                ans = current_count;
            }else{
                ans = min(ans, current_count);
            }
            
        }

        // 물 먼저 퍼트리기
        current_map = set_water(current_map, R, C);

        // if(current_map[current_row][current_col] == '*'){
        //     continue;
        // }

        // cout << current_row << ' ' << current_col << endl;
        // for(int i = 0; i < R; i++) {
        //     for(int j = 0; j < C; j++){
        //         cout << current_map[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        // cout << endl << endl;

        // 고슴도치 위치 확인 후 q에 push
        for(int i = 0; i < 4; i++) {
            int next_row = current_row + dir_row[i];
            int next_col = current_col + dir_col[i];

            if(check_range(next_row, next_col, R, C) && !visited[next_row][next_col] && (current_map[next_row][next_col] =='.' || current_map[next_row][next_col] == 'D'  )) {
                visited[next_row][next_col] = true;
                q.push(
                    make_pair(
                        make_pair(current_count + 1, current_map),
                        make_pair(next_row, next_col)
                    )
                );
            }
        }

    }

    if(ans == -1){
        cout << "KAKTUS";
    }else{
        cout << ans;
    }

    

    return 0;

}