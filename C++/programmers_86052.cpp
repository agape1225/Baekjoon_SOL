#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int row_size;
int col_size;

vector<int> get_next_dir(int x, int y, int input_dir, int next_dir) {
    int dir;
    vector<int> rets;

    if (next_dir == 'L') {
        if (input_dir - 1 < 0)
            input_dir = 3;
        else
            input_dir = input_dir - 1;
    }
    else if (next_dir == 'R') {
        input_dir = (input_dir + 1) % 4;
    }
    x = (x + dir_x[input_dir]) % row_size;
    y = (y + dir_y[input_dir]) % col_size;

    if (x < 0)
        x = row_size - 1;
    if (y < 0)
        y = col_size - 1;

    rets.push_back(x);
    rets.push_back(y);
    rets.push_back(input_dir);

    return rets;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    bool visited[500][500][4] = { 0 };
    row_size = grid.size();
    col_size = grid[0].size();

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            for (int k = 0; k < 4; k++) {

                if (visited[i][j][k])
                    continue;

                int cor_x = i;
                int cor_y = j;
                int dir = k;
                int count = 0;

                while (!visited[cor_x][cor_y][dir]) {
                    count++;
                    visited[cor_x][cor_y][dir] = true;
                    vector<int> tmp = get_next_dir(cor_x, cor_y, dir, grid[cor_x][cor_y]);
                    cor_x = tmp[0];
                    cor_y = tmp[1];
                    dir = tmp[2];
                }
                if (count != 0)
                    answer.push_back(count);
            }

        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}