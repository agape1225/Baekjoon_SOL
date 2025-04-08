// 스킬
// 지워지기
// 이동
// 폭발 (끝까지)
// 변화

#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int board[50][50] = {0};
pair<int, int> commans[100];
int N, M;
int ans[3] = {0};

void set_skill_result(int d, int s) {
    int shark_row = ((N + 1) / 2) - 1;
    int shark_col = ((N + 1) / 2) - 1;

    if(d == 1){
        // up

        int col = shark_col;
        for(int i = 0; i < s; i++) {
            board[shark_row - (1 + i)][col] = 0;
        }


    }else if(d == 2) {
        // down
        int col = shark_col;
        for(int i = 0; i < s; i++) {
            board[shark_row + (1 + i)][col] = 0;
        }

    }else if(d == 3) {
        // left
        int row = shark_row;
        for(int i = 0; i < s; i++) {
            board[shark_row][shark_col - (i + 1)] = 0;
        }

    }else if(d == 4) {
        // right
        int row = shark_row;
        for(int i = 0; i < s; i++) {
            board[shark_row][shark_col + (i + 1)] = 0;
        }

    }
}

// row, col 위치의 다음 위치를 가지고 온다.
pair<int, int> get_next_pos(int row, int col) {

    int next_row, next_col;
    int shark_row = ((N + 1) / 2) - 1;
    int shark_col = ((N + 1) / 2) - 1;

    int size = max(abs(shark_row - row), abs(shark_col - col)) * 2 + 1;

    // cout << shark_row << ' ' << shark_col << endl;

    int start_row = shark_row - (size / 2);
    int start_col = shark_col - (size / 2);

    int end_row = start_row + size - 1;
    int end_col = start_col + size - 1;

    // cout << start_row << ' ' << end_row << endl;
    // cout << start_col << ' ' << end_col << endl;

    if(row == 0 && col == 0) {
        return make_pair(-1, -1);
    }

    if(row == start_row) {
        next_row = row;
        next_col = col - 1;
    }else if(row == end_row) {
        if(col == end_col) {
            next_row = row - 1;
            next_col = col;
        }else {
            next_row = row;
            next_col = col + 1;
        }
    }else if(col == start_col) {
        if(row == end_row) {
            next_row = row;
            next_col = col + 1;
        }else {
            next_row = row + 1;
            next_col = col;
        }
    }else if(col == end_col) {
        if(row  == end_row) {
            next_row = row - 1;
            next_col = col;
        }else {
            next_row = row - 1;
            next_col  = col;
        }
    }
    return make_pair(next_row, next_col);
}

void move_bizs() {
    pair<int,int> tmp = get_next_pos(((N + 1) / 2) - 1, ((N + 1) / 2) - 1);
    int current_row = tmp.first;
    int current_col = tmp.second;
    

    while(!(current_row == -1 && current_col == -1)) {
        // cout << current_row << ' ' << current_col << endl;
        

        tmp = get_next_pos(current_row, current_col);
        int next_row = tmp.first;
        int next_col = tmp.second;


        if(board[current_row][current_col] == 0) {

            int next_row_tmp = next_row;
            int next_col_tmp = next_col;
            
            //다음 구슬의 위치를 찾는다
            while(!(next_row_tmp == -1 && next_col_tmp == -1) && board[next_row_tmp][next_col_tmp] == 0) {
                tmp = get_next_pos(next_row_tmp, next_col_tmp);
                next_row_tmp = tmp.first;
                next_col_tmp = tmp.second;
            }

            if(next_row_tmp != -1 && next_col_tmp != -1) {
                if(board[next_row_tmp][next_col_tmp] != 0) {
                    board[current_row][current_col] = board[next_row_tmp][next_col_tmp];
                    board[next_row_tmp][next_col_tmp] = 0;
                }

                current_row = next_row;
                current_col = next_col;
            }else {
                return;
            }

        }else {
            current_row = next_row;
            current_col = next_col;
        }
    }
}

pair<pair<int, int>, pair<int, int>> get_count_info(int row, int col) {
    int current_row = row;
    int current_col = col;

    int biz_num = board[current_row][current_col];
    int count = 1;

    pair<int, int> tmp = get_next_pos(current_row, current_col);
    int next_row = tmp.first;
    int next_col = tmp.second;

    while(!(next_row == -1 && next_col == -1) && board[next_row][next_col] == biz_num) {
        count++;
        tmp = get_next_pos(next_row, next_col);
        next_row = tmp.first;
        next_col = tmp.second;

        // cout << next_row << ' ' << next_col << endl;
    }

    return make_pair(
        make_pair(biz_num, count),
        make_pair(next_row, next_col)
    );
}

bool explor_bizs() {
    pair<int,int> tmp = get_next_pos(((N + 1) / 2) - 1, ((N + 1) / 2) - 1);
    int current_row = tmp.first;
    int current_col = tmp.second;
    bool is_explor = false;


    while(!(current_row == -1 && current_col == -1)) {

        // 연속으로 count
        pair<pair<int, int>, pair<int, int>> count_info = get_count_info(current_row, current_col);

        if(count_info.first.first != 0 && count_info.first.second >= 4) {
            is_explor = true;
            // cout << count_info.first.first << endl;
            ans[count_info.first.first - 1] += count_info.first.second;
            //전부 0으로 만들기
            int tmp_row = current_row;
            int tmp_col = current_col;

            for(int i = 0; i < count_info.first.second; i++) {
                board[tmp_row][tmp_col] = 0;
                tmp = get_next_pos(tmp_row, tmp_col);

                tmp_row = tmp.first;
                tmp_col = tmp.second;
            }
        }

        current_row = count_info.second.first;
        current_col = count_info.second.second;
    }
    return is_explor;
}

void set_bizs() {

    int new_board[50][50] = {0};
    pair<int,int> tmp = get_next_pos(((N + 1) / 2) - 1, ((N + 1) / 2) - 1);
    int new_row = tmp.first;
    int new_col = tmp.second;

    int tmp_row = tmp.first;
    int tmp_col = tmp.second;

    while(!(tmp_row == -1 && tmp_col == -1)) {
        pair<pair<int, int>, pair<int, int>> count_info = get_count_info(tmp_row, tmp_col);
        if(count_info.first.first == 0) {
            break;
        }

        tmp_row = count_info.second.first;
        tmp_col = count_info.second.second;

        int A = count_info.first.second;
        int B = count_info.first.first;

        new_board[new_row][new_col] = A;
        tmp = get_next_pos(new_row, new_col);

        new_row = tmp.first;
        new_col = tmp.second;

        if(new_row == -1 && new_col == -1){
            break;
        }

        new_board[new_row][new_col] = B;
        tmp = get_next_pos(new_row, new_col);

        new_row = tmp.first;
        new_col = tmp.second;

        if(new_row == -1 && new_col == -1){
            break;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main(void) {
    int d, s;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;


    // int count = 0;

    // pair<int, int> tmp = get_next_pos(N / 2, N / 2);

    // while(tmp.first != -1 && tmp.second != -1) {
    //     cout << tmp.first << ' ' << tmp.second << endl << endl;
    //     tmp = get_next_pos(tmp.first , tmp.second);
    //     count ++;
    //     if(count == 50) {
    //         break;
    //     }
    // }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> d >> s;
        commans[i] = make_pair(d, s);
    }

    for(int i = 0; i < M; i++) {
        
        d = commans[i].first;
        s = commans[i].second;

        set_skill_result(d, s);

        // get_next_pos(0, 2);

        move_bizs();
        while(explor_bizs()) {
            move_bizs();
        }

        // explor_bizs();

        set_bizs();

        // for(int row = 0; row < N; row++) {
        //     for(int col = 0; col < N; col++) {
        //         cout << board[row][col] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    int ans_count = 0;
    for(int i = 0; i < 3; i++) {
        ans_count += ans[i] * (i + 1);
    }

    cout << ans_count;


    return 0;

}