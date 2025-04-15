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
            if(target_number == -1 || visited[i][j]) {
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
    
    info start;
    int ans_index = 0;
    info ans[20];
    int ans_list[20] = {0};

    cin >> K >> M;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> start.map[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> his_number[i];
    }

    // ans[0] = start;

    copy_info(ans[0], start);

    for(int k = 1; k <= K; k++) {
        info tmp;
        for(int degree = 0; degree < 3; degree++) {
        for(int stand_row = 1; stand_row < 4; stand_row++) {
            for(int stand_col = 1; stand_col < 4; stand_col++) {
                for(int stand_row = 1; stand_row < 4; stand_row++) {
                    info new_info;
                    bool flag = false;
                    copy_info(new_info, ans[k - 1]);
                    new_info.count++;
                    set_new_map(stand_row, stand_col, degree, new_info);
            

                    if(update_target(new_info)) {
                        flag = true;
                        set_new_piece(new_info);
                    }

                    if(flag) {
                        if(tmp.value < new_info.value) {
                            copy_info(tmp, new_info);
                        }
                    }
                }
            }
        }

        if(tmp.count != 0) {

            while(update_target(tmp)) {
                set_new_piece(tmp);
            }

            cout << tmp.value - ans[k - 1].value << ' ';
            ans_list[k] = tmp.value - ans[k - 1].value;
            ans_index = k;
            copy_info(ans[k], tmp);
        }else {
            break;
        }
    }
            ans_list[k] = tmp.value - ans[k - 1].value;
            ans_index = k;
            copy_info(ans[k], tmp);
        }
    }

    if(ans_index  > 0) {
        for(int i = 1; i <= ans_index; i++) {
            cout << ans_list[i] << ' ';
        }
    }
    return 0;
}
