#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef struct info {
    int row;
    int col;
    int count;
} info;

bool check_range(int row, int col, int N) {
    if(row < 0 || row >= N || col < 0 || col >= N) {
        return false;
    }
    return true;
}

//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)

int main(void) {
    int N, r1, c1, r2, c2;
    int ans = -1;
    bool visited[205][205] = {0};

    int dir_row[6] = {-2, -2, 0, 0, 2, 2};
    int dir_col[6] = {-1, 1, -2, 2, -1, 1};

    cin >> N >> r1 >> c1 >> r2 >> c2;


    // queue<pair<int, pair<int, int>>> q;
    queue<info> q;
    visited[r1][c1] = true;
    info start;
    start.row = r1;
    start.col = c1;
    start.count = 0;
    q.push(start);
    // q.push(make_pair(0, make_pair(r1, c1)));

    while(!q.empty()) {
        info current_info = q.front();
        // int current_row = q.front().second.first; 
        // int current_col = q.front().second.second;
        // int current_count = q.front().first;
        q.pop();

        if(current_info.row == r2 && current_info.col == c2) {
            ans = current_info.count;
            break;
        }

        for(int i = 0; i < 6; i++) {
            int next_row = current_info.row + dir_row[i];
            int next_col = current_info.col + dir_col[i];

            if(check_range(next_row, next_col, N) && !visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                info next_info;
                next_info.row = next_row;
                next_info.col = next_col;
                next_info.count = current_info.count + 1;

                q.push(next_info);

                // q.push(make_pair(current_count + 1, make_pair(next_row, next_col)));
            }
        }

    }

    cout << ans;

    return 0;


}