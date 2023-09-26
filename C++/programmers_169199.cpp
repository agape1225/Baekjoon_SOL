#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> boards;

vector<pair<int, int>> get_dir(int row, int col) {
    vector<pair<int, int>> dirs;

    //»ó
    int tmp = row;
    while (tmp - 1 >= 0 && boards[tmp - 1][col] != 'D')
        tmp--;

    if (tmp != row)
        dirs.push_back(make_pair(tmp, col));

    tmp = row;
    while (tmp + 1 < boards.size() && boards[tmp + 1][col] != 'D')
        tmp++;

    if (tmp != row)
        dirs.push_back(make_pair(tmp, col));

    tmp = col;
    while (tmp - 1 >= 0 && boards[row][tmp - 1] != 'D')
        tmp--;
    if (tmp != col)
        dirs.push_back(make_pair(row, tmp));

    tmp = col;
    while (tmp + 1 < boards[0].size() && boards[row][tmp + 1] != 'D')
        tmp++;

    if (tmp != col)
        dirs.push_back(make_pair(row, tmp));

    return dirs;
}

int solution(vector<string> board) {
    boards = board;
    int answer = -1;
    bool visited[100][100] = { 0 };
    int start_row;
    int start_col;
    int end_row;
    int end_col;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') {
                start_row = i;
                start_col = j;
            }
            if (board[i][j] == 'G') {
                end_row = i;
                end_col = j;
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(start_row, start_col)));
    visited[start_row][start_col] = true;

    while (!q.empty()) {

        int count = q.front().first;
        int current_row = q.front().second.first;
        int current_col = q.front().second.second;
        q.pop();

        if (current_row == end_row && current_col == end_col) {
            return count;
        }

        vector<pair<int, int>> dirs = get_dir(current_row, current_col);

        for (auto it : dirs) {
            int next_row = it.first;
            int next_col = it.second;

            if (!visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                q.push(make_pair(count + 1, make_pair(next_row, next_col)));
            }
        }
    }
    return answer;
}