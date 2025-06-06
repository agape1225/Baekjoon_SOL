#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
char inpt_map[1005][1005];
int ans[1005][1005] = {0};
bool visited[1005][1005] = {0};

bool check_range(int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= M){
        return false;
    }
    return true;
}

int dir_row[4] = {1,0,-1,0};
int dir_col[4] = {0,1,0,-1};

void set_cache() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] || inpt_map[i][j] == '1'){
                continue;
            }
            visited[i][j] = true;
            int count = 1;
            queue<pair<int, int>> q;
            set<pair<int,int>> one_pos_list;
            q.push(make_pair(i, j));

            while(!q.empty()) {
                int current_row = q.front().first;
                int current_col = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int next_row = current_row + dir_row[k];
                    int next_col = current_col + dir_col[k];

                    if(check_range(next_row, next_col)) {

                        if(inpt_map[next_row][next_col] == '0') {
                            if(!visited[next_row][next_col]) {
                                // cout << next_row << ' ' << next_col << '\n';
                                count++;
                                visited[next_row][next_col] = true;
                                q.push(make_pair(next_row, next_col));
                            }

                        }else {
                            one_pos_list.insert(make_pair(next_row, next_col));
                            // if(!visited[next_row][next_col]) {
                            //     // visited[next_row][next_col] = true;
                                
                            // }
                            
                        }
                    }
                }
            }

            // cout << endl << count << endl;

            for(auto it: one_pos_list) {
                ans[it.first][it.second] = (ans[it.first][it.second] + count) % 10;
            }
            
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> inpt_map[i][j];
            if(inpt_map[i][j] == '1') {
                ans[i][j] = 1;
            }
        }
    }

    set_cache();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << ans[i][j] << ' ';
        }
        cout <<'\n';
    }

    return 0;

}