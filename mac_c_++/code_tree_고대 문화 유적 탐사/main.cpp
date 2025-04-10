#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int map[5][5];
    int count = 0;
    int index = 0;
    int value = 0;
    int dir = -1;
    vector<int> history;


} info;

int his_number[305] = {0};
int K, M;

queue<info> q;

void copy_info (info &info1, info &info2) {
    info1.count = info2.count;
    info1.index = info2.index;
    info1.value = info2.value;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            info1.map[i][j] = info2.map[i][j];
        }
    }

    for(auto it : info2.history) {
        info1.history.push_back(it);
    }
}

void set_new_map(int stand_row, int stand_col, int degree, info &new_info) {
    int new_map[5][5] = {0};

    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            new_map[row][col] = new_info.map[row][col];
        }
    }


    if(degree == 0) {
        // 90
        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col - 1];
        new_map[stand_row ][stand_col + 1] = new_info.map[stand_row - 1][stand_col];
        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col + 1];

        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col + 1];
        new_map[stand_row + 1][stand_col] = new_info.map[stand_row ][stand_col + 1];
        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col + 1];

        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col + 1];
        new_map[stand_row][stand_col - 1] = new_info.map[stand_row + 1][stand_col];
        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col - 1];

        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col - 1];
        new_map[stand_row - 1][stand_col] = new_info.map[stand_row][stand_col - 1];
        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col - 1];

    }else if(degree == 1) {

        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col - 1];
        new_map[stand_row + 1][stand_col] = new_info.map[stand_row - 1][stand_col];
        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col + 1];

        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col + 1];
        new_map[stand_row][stand_col - 1] = new_info.map[stand_row ][stand_col + 1];
        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col + 1];

        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row + 1][stand_col + 1];
        new_map[stand_row - 1][stand_col] = new_info.map[stand_row + 1][stand_col];
        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col - 1];

        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col - 1];
        new_map[stand_row ][stand_col + 1] = new_info.map[stand_row][stand_col - 1];
        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row - 1][stand_col - 1];


    }else if(degree == 2) {

        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col - 1];
        new_map[stand_row][stand_col - 1] = new_info.map[stand_row - 1][stand_col];
        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col + 1];

        new_map[stand_row - 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col + 1];
        new_map[stand_row - 1][stand_col] = new_info.map[stand_row ][stand_col + 1];
        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col + 1];

        new_map[stand_row - 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col + 1];
        new_map[stand_row ][stand_col + 1] = new_info.map[stand_row + 1][stand_col];
        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col - 1];


        new_map[stand_row + 1][stand_col + 1] = new_info.map[stand_row + 1][stand_col - 1];
        new_map[stand_row + 1][stand_col] = new_info.map[stand_row][stand_col - 1];
        new_map[stand_row + 1][stand_col - 1] = new_info.map[stand_row - 1][stand_col - 1];

    }

    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            new_info.map[row][col] = new_map[row][col];
        }
    }

    
}

bool update_target(info &curr_info) {
    bool visited[5][5] = {0};
    bool flag = false;
    int total = 0;
    

    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int target_number = curr_info.map[i][j];
            if(target_number == -1) {
                continue;
            }
            vector<pair<int, int>> history;
            

            visited[i][j] = true;
            history.push_back(make_pair(i, j));
            queue<pair<int,int>> q;

            q.push(make_pair(i, j));


            while(!q.empty()) {
                int curr_row = q.front().first;
                int curr_col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int new_row = curr_row + dir_x[i];
                    int new_col = curr_col + dir_y[i];

                    if(0 <= new_row && new_row < 5 && 0 <= new_col && new_col < 5) {
                        if(!visited[new_row][new_col] && curr_info.map[new_row][new_col] == target_number) {
                            visited[new_row][new_col] = true;
                            q.push(make_pair(new_row, new_col));
                            history.push_back(make_pair(new_row, new_col));
                        }
                    }
                }
            }

            if(history.size() > 2) {
                flag = true; 
                curr_info.value += history.size();
                total += history.size();
                for(auto it : history) {
                    curr_info.map[it.first][it.second] = -1;
                }
            }

        }
    }
    // curr_info.history.push_back(total);
    return flag;
}

void set_new_piece(info &curr_info) {
    for(int col = 0; col < 5; col++) {
        for(int row = 4; row >= 0; row--) {
            if(curr_info.map[row][col] == -1) {
                curr_info.map[row][col] = his_number[curr_info.index];
                curr_info.index++;
            }
        }
    }
}

int main() {
    // Please write your code here.
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    info ans;
    int ans_list[15] = {0};
    int max_index = 0;

    info start;

    cin >> K >> M;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> start.map[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> his_number[i];
    }


    // bfs 탐색 시작
    q.push(start);

    while(!q.empty()) {
        info curr_info = q.front();
        // for(int i = 0; i < 5; i++) {
        //     for(int j = 0; j < 5; j++) {
        //         cout << curr_map.map[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        q.pop();
        // cout << curr_info.count << endl;

        if(curr_info.count == K) {
            // cout << curr_info.value << ' ' << curr_info.history.size() << endl;
            if(curr_info.value > ans.value) {
                // ans = curr_info;
                
                copy_info(ans, curr_info);
            }
            continue;
        }
        // info new_info;
        // copy_info(new_info, curr_info);
        // set_new_map(2, 2, 0, new_info);
        // update_target(new_info);
        // cout << new_info.value << endl;
        // set_new_piece(new_info);
        // update_target(new_info);
        // cout << new_info.value << endl;
        // set_new_piece(new_info);
        // update_target(new_info);
        // cout << new_info.value << endl;

        // for(int row = 0; row < 5; row++) {
        //     for(int col = 0; col < 5; col++) {
        //         cout << new_info.map[row][col] << ' ';
        //     }
        //     cout << endl;
        // }

        // break;

        info tmp;

        for(int stand_row = 1; stand_row < 4; stand_row++) {
            for(int stand_col = 1; stand_col < 4; stand_col++) {
                for(int degree = 0; degree < 3; degree++) {
                    info new_info;
                    bool flag = false;
                    copy_info(new_info, curr_info);
                    new_info.count++;
                    if(new_info.count > 1){
                        // cout << new_info.value << endl << endl;
                    }
                    // new_info.map = curr_info.map;

                    // int value = 0;
                    set_new_map(stand_row, stand_col, degree, new_info);
            

                    while(update_target(new_info)) {
                        flag = true;
                        set_new_piece(new_info);
                        // new_info.value += value;
                    }
                    // cout << stand_row << ' ' << stand_col << degree << endl;
                    
                    // cout << new_info.value << endl << endl;

                    // int diff = new_info.value

                    if(flag) {
                        if(tmp.value < new_info.value) {
                            // cout << new_info.value << endl;
                            copy_info(tmp, new_info);
                        }
                        // new_info.history.push_back(new_info.value - curr_info.value);
                        // ans_list[new_info.count] += new_info.value - curr_info.value;
                        // max_index = max(max_index, new_info.count);
                        // q.push(new_info);
                        // cout << new_info.value - curr_info.value << endl;
                    }
                }
            }
        }

        if(tmp.count != 0) {
            ans_list[tmp.count] = tmp.value - curr_info.value;
            copy_info(ans, tmp);
            // cout << ans.count << endl;
            q.push(ans);
        }

        // break;
    }

    if(ans.count  > 0) {
        // cout << ans.count << endl;
        for(int i = 1; i <= ans.count; i++) {
            cout << ans_list[i] << ' ';
        }
        // cout << ans.value << endl;
        // for(auto it : ans.history) {
        //     cout << it << ' ';
        // }
    }


    return 0;
}