#include <string>
#include <vector>
#include <queue>

using namespace std;

int row_size;
int col_size;

int dir_row[4] = { 0, 1, 0, -1 };
int dir_col[4] = { 1, 0, -1, 0 };

bool check_range(int row, int col) {
    if (row < 0 || row >= row_size || col < 0 || col >= col_size)
        return false;
    return true;
}

int bfs(int start_row, int start_col, int target_row, int target_col, vector<string> maps) {

    bool visited[100][100] = { 0 };
    queue<pair<int, pair<int, int>>> q;

    visited[start_row][start_col] = true;
    q.push(make_pair(0, make_pair(start_row, start_col)));

    while (!q.empty()) {

        int current_row = q.front().second.first;
        int current_col = q.front().second.second;
        int count = q.front().first;

        q.pop();

        if (current_row == target_row && current_col == target_col)
            return count;
        
        for (int i = 0; i < 4; i++) {
            int next_row = current_row + dir_row[i];
            int next_col = current_col + dir_col[i];

            if (check_range(next_row, next_col) &&
                !visited[next_row][next_col] &&
                maps[next_row][next_col] != 'X') {

                visited[next_row][next_col] = true;
                q.push(make_pair(count + 1, make_pair(next_row, next_col)));
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    row_size = maps.size();
    col_size = maps[0].size();

    int start_row;
    int start_col;
    int laber_row;
    int laber_col;
    int end_row;
    int end_col;

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (maps[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
            if (maps[i][j] == 'L') {
                laber_row = i;
                laber_col = j;
            }
            if (maps[i][j] == 'E') {
                end_row = i;
                end_col = j;
            }
        }
    }

    int to_laber = bfs(start_row, start_col, laber_row, laber_col, maps);
    int to_end = bfs(laber_row, laber_col, end_row, end_col, maps);

    if (to_laber == -1 || to_end == -1)
        return -1;

    return to_laber + to_end;
}