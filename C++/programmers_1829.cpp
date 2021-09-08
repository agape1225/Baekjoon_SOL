#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool check_range(int x, int y, int max_x, int max_y) {

    if (x < 0 || x >= max_x)
        return false;
    else {
        if (y < 0 || y >= max_y)
            return false;
        else
            return true;
    }

}

int BFS(int x, int y, vector<vector<int>> picture, int max_x, int max_y, bool visited[100][100]) {

    int dir_x[4] = { 1,0,-1,0 };
    int dir_y[4] = { 0,1,0,-1 };

    int count_max = 0;
    int standard = picture[x][y];
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push(make_pair(x, y));


    while (!q.empty()) {
        pair<int, int> buff = q.front();
        q.pop();
        count_max++;

        for (int i = 0; i < 4; i++) {

            int buff_x = buff.first + dir_x[i];
            int buff_y = buff.second + dir_y[i];

            if (check_range(buff_x, buff_y, max_x, max_y) && !visited[buff_x][buff_y]
                && picture[buff_x][buff_y] == standard && picture[buff_x][buff_y] != 0) {

                q.push(make_pair(buff_x, buff_y));
                visited[buff_x][buff_y] = true;

            }

        }

    }

    return count_max;

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    bool visited[100][100] = { 0 };

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (picture[i][j] != 0 && !visited[i][j]) {
                int buff = BFS(i, j, picture, m, n, visited);
                number_of_area++;

                if (buff > max_size_of_one_area)
                    max_size_of_one_area = buff;

            }

        }

    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}