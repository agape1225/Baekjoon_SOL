#include <iostream>
#include <algorithm>

using namespace std;

int pixel[50][50] = {0};
int ans_array[50][50] = {0};
int R, C, T;
int ans = 0;

int get_mid_value(int row, int col) {
    vector<int> tmp;
    for(int i = row; i < row + 3; i++) {
        for(int j = col; j < col + 3; j++) {
            tmp.push_back(pixel[i][j]);
        }
    }

    sort(tmp.begin(), tmp.end());

    return tmp[tmp.size() / 2];
}

int main(void) {
    cin >> R >> C;
    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            cin >> pixel[row][col];
        }
    }
    cin >> T;

    //진행

    for(int row = 0; row < R - 2; row++) {
        for(int col = 0; col < C - 2; col++) {

            // cout << get_mid_value(row, col) << ' ';

            if(get_mid_value(row, col) >= T ) {
                ans++;
            }

            // ans_array[row][col] = get_mid_value(row, col);
        }
        // cout << endl;
    }

    cout << ans;

    return 0;


}