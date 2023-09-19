#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int dir_row[4] = { 1, 0, -1, 0 };
int dir_col[4] = { 0, -1, 0, 1 };

bool check_range(int row, int col) {
    if (row < 0 || row >= 5 || col < 0 || col >= 5)
        return false;
    return true;
}

int check_bfs(int start_row, int start_col, int end_row, int end_col, vector<string> room) {
    bool visited[5][5] = { 0 };
    queue<pair<int, pair<int, int>>> q;
    visited[start_row][start_col] = true;
    q.push(make_pair(0, make_pair(start_row, start_col)));
    while (!q.empty()) {

        int current_row = q.front().second.first;
        int current_col = q.front().second.second;
        int count = q.front().first;
        q.pop();

        if (current_row == end_row && current_col == end_col && count <= 2)
            return false;

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + dir_row[i];
            int next_col = current_col + dir_col[i];

            if (check_range(next_row, next_col) &&
                room[next_row][next_col] != 'X' &&
                !visited[next_row][next_col] &&
                count + 1 <= 2) {
                visited[next_row][next_col] = true;
                q.push(make_pair(count + 1, make_pair(next_row, next_col)));
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto room : places) {
        vector<pair<int, int>> locations;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (room[i][j] == 'P') {
                    locations.push_back(make_pair(i, j));
                }
            }
        }

        bool dir = true;
        for (int i = 0; i < locations.size(); i++) {
            int current_row = locations[i].first;
            int current_col = locations[i].second;

            for (int j = 0; j < locations.size(); j++) {
                if (i == j)
                    continue;
                int next_row = locations[j].first;
                int next_col = locations[j].second;

                if (abs(current_row - next_row) + abs(current_col - next_col) <= 2) {
                    if (!check_bfs(current_row, current_col, next_row, next_col, room)) {
                        dir = false;
                    }
                }
            }
        }
        if (dir)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}