#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

bool check_range(int x, int y, int max_x, int max_y) {
    if (x < 0 || x >= max_x || y < 0 || y >= max_y)
        return false;
    return true;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    bool visited[101][101] = { 0 };

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                
                int count = 0;
                queue<pair<int, int>> q;
                
                q.push(make_pair(i, j));
                visited[i][j] = true;

                while (!q.empty()) {
                    int current_x = q.front().first;
                    int current_y = q.front().second;

                    q.pop();
                    count += (maps[current_x][current_y] - '0');

                    for (int k = 0; k < 4; k++) {

                        int next_x = current_x + dir_x[k];
                        int next_y = current_y + dir_y[k];

                        if (check_range(next_x, next_y, maps.size(), maps[0].size()) &&
                            maps[next_x][next_y] != 'X' && !visited[next_x][next_y]) {
                            visited[next_x][next_y] = true;
                            q.push(make_pair(next_x, next_y));
                        }
                    }
                }
                answer.push_back(count);
            }
        }
    }

    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}