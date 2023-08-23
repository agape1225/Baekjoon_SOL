#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans;
int count_zero = 0;
int count_one = 0;

bool is_tree(int start_row, int start_col, int size) {
    int standard = ans[start_row][start_col];

    for (int i = start_row; i < start_row + size; i++) {
        for (int j = start_col; j < start_col + size; j++) {
            if (standard != ans[i][j])
                return false;
        }
    }
    return true;
}

void get_ans(int start_row, int start_col, int size) {
    if (size > 1) {
        if (is_tree(start_row, start_col, size)) {
            if (ans[start_row][start_col]) {
                count_one++;
            }
            else {
                count_zero++;
            }
        }
        else {
            get_ans(start_row, start_col, size / 2);
            get_ans(start_row + (size / 2), start_col, size / 2);
            get_ans(start_row, start_col + (size / 2), size / 2);
            get_ans(start_row + (size / 2), start_col + (size / 2), size / 2);
        }
    }
    else {
        if (ans[start_row][start_col]) {
            count_one++;
        }
        else {
            count_zero++;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    ans = arr;

    get_ans(0, 0, arr[0].size());

    answer.push_back(count_zero);
    answer.push_back(count_one);

    return answer;
}