#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

bool check_range(int r, int c, int max_r, int max_c) {

    if (r < 0 || r >= max_r)
        return false;
    else {
        if (c < 0 || c >= max_c)
            return false;
        else
            return true;
    }

}

int count_blocks(int max_m, int max_n, vector<string>& bord,
    queue<pair<int, int>>& get_point) {

    int blocks = 0;

    for (int i = 0; i < max_m - 1; i++) {

        for (int j = 0; j < max_n - 1; j++) {

            if (bord[i][j] != '0') {

                if (bord[i][j] == bord[i + 1][j] &&
                    bord[i][j] == bord[i][j + 1] &&
                    bord[i][j] == bord[i + 1][j + 1]) {

                    blocks += 4;
                    get_point.push(make_pair(i, j));


                }

            }

        }

    }

    return blocks;

}

void set_block(int max_m, int max_n, vector<string>& bord, queue<pair<int, int>>& get_point) {

    while (!get_point.empty()) {

        pair<int, int> buff = get_point.front();
        get_point.pop();

        int x = buff.first;
        int y = buff.second;

        bord[x][y] = '0';
        bord[x + 1][y] = '0';
        bord[x][y + 1] = '0';
        bord[x + 1][y + 1] = '0';

    }

    for (int t = 0; t < max_m - 1; t++) {
        for (int i = 0; i < max_m - 1; i++) {
            for (int j = 0; j < max_n; j++) {

                if (bord[i][j] != '0' && bord[i + 1][j] == '0') {

                    char buff = bord[i][j];
                    bord[i][j] = bord[i + 1][j];
                    bord[i + 1][j] = buff;

                }

            }
        }
    }



}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<pair<int, int>> get_point;

    int buff;
    while ((buff = count_blocks(m, n, board, get_point)) != 0) {

        //answer += buff;
        set_block(m, n, board, get_point);

        cout << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                cout << board[i][j] << ' ';;

            }
            cout << endl;
        }

    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '0')
                answer++;
        }
    }

    /*for (int i = 0; i < m; i++ ) {
        for (int j = 0; j < n; j++) {

            cout << board[i][j] << ' ';;

        }
        cout << endl;
    }*/

    return answer;
}

int main(void) {

    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

    solution(4, 5, board);

    return 0;


}