#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int paper[10][10];
int ans = -1;
int count_color_paper[6] = {0, 5, 5, 5, 5, 5};

bool is_full() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(paper[i][j] == 1){
                return false;
            }
        }
    }

    return true;
}

bool is_count_able(int row, int col, int paper_count) {

    if(row + paper_count > 10 || col + paper_count > 10){
        return false;
    }


    for(int i = row; i < row + paper_count; i++) {
        for(int j = col; j < col + paper_count; j++) {
            if(paper[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void fill_paper(int row, int col, int paper_count, int target_num) {
    for(int i = row; i < row + paper_count; i++) {
        for(int j = col; j < col + paper_count; j++) {
            paper[i][j] = target_num;
        }
    }
} 

pair<int, int> get_filled_pos() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(paper[i][j] == 1){
                return make_pair(i, j);
            }
        }
    }
}

void get_ans(int used_paper_count) {

    if(is_full()) {

        // for(int i = 1; i < 6; i++) {
        //     cout << count_color_paper[i] << ' ';
        // }
        // cout << endl;

        if(ans == -1) {
            ans = used_paper_count;
        }else{
            ans = min(ans, used_paper_count);
        }
        
    }else {

        // 첫 위치 찾기
        pair<int,int> filled_pos = get_filled_pos();

        for(int paper_count = 1; paper_count < 6; paper_count++) {
            if(
                count_color_paper[paper_count] > 0 &&
                is_count_able(filled_pos.first , filled_pos.second, paper_count)
                ) {

                // cout << filled_pos.first << ' ' << filled_pos.second << ' ' << paper_count << endl;

                //채워주기 및 갯수 차감
                fill_paper(filled_pos.first, filled_pos.second, paper_count, 0);
                count_color_paper[paper_count]--;

                //탐색 진행
                get_ans(used_paper_count + 1);

                //복구
                fill_paper(filled_pos.first, filled_pos.second, paper_count, 1);
                count_color_paper[paper_count]++;

            }
        }

    }
}

int main(void) {

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }

    get_ans(0);

    cout << ans;

}