#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int R, C;
string cave[105];
int highs[105] = {0};
int N;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

void erase_minaral(bool dir, int high)
{
    // left
    if (dir)
    {

        for (int i = 0; i < C; i++)
        {
            if (cave[high][i] == 'x')
            {
                cave[high][i] = '.';
                return;
            }
        }
    }
    else
    {

        for (int i = C - 1; i > -1; i--)
        {
            if (cave[high][i] == 'x')
            {
                cave[high][i] = '.';
                return;
            }
        }
    }
}

pair<int, int> get_fall_clusters()
{
    bool visited[105][105] = {0};
    pair<int, int> pos = {-1, -1};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (cave[i][j] == 'x' && !visited[i][j])
            {
                int min_row = -1;
                int start_row = i;
                int start_col = j;
                queue<pair<int, int>> q;

                visited[i][j] = true;
                q.push(make_pair(i, j));

                while (!q.empty())
                {
                    int curr_row = q.front().first;
                    int curr_col = q.front().second;
                    q.pop();

                    min_row = max(min_row, curr_row);

                    for (int k = 0; k < 4; k++)
                    {
                        int new_row = curr_row + dir_x[k];
                        int new_col = curr_col + dir_y[k];

                        if (new_row >= 0 && new_row < R && new_col >= 0 && new_col < C && cave[new_row][new_col] == 'x' && !visited[new_row][new_col])
                        {
                            visited[new_row][new_col] = true;
                            q.push(make_pair(new_row, new_col));
                        }
                    }
                }

                if (min_row != R - 1)
                {
                    return make_pair(start_row, start_col);
                }
            }
        }
    }

    return pos;
}

void adjust_one_cluster(pair<int, int> fall_clusters_pos)
{
    int visited[105][105] = {0};
    queue<pair<int, int>> q;
    int min_row = -1;

    visited[fall_clusters_pos.first][fall_clusters_pos.second] = true;
    q.push(make_pair(fall_clusters_pos.first, fall_clusters_pos.second));

    while (!q.empty())
    {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int new_row = curr_row + dir_x[k];
            int new_col = curr_col + dir_y[k];

            if (new_row >= 0 && new_row < R && new_col >= 0 && new_col < C && cave[new_row][new_col] == 'x' && !visited[new_row][new_col])
            {
                visited[new_row][new_col] = true;
                q.push(make_pair(new_row, new_col));
            }
        }
    }

    int dis = R;

    for(int col = 0; col < C; col++){
        int max_row = -1;
        for(int row = 0; row < R; row++){
            
            if(visited[row][col] && !visited[row + 1][col]){
                int end_row = -1;

                for(end_row = row + 2; end_row < R; end_row++){

                    if((!visited[end_row][col] && cave[end_row][col] == 'x') ){
                        dis = min(dis, end_row - row - 1);
                        break;
                    }

                    if( (cave[end_row][col] == '.' && end_row == R - 1)){
                        dis = min(dis, end_row - row );
                        break;
                    }


                }
            }
        }
    }

    for (int i = R - 1; i >= 0; i--)
    {
        for (int j = 0; j < C; j++)
        {
            if (visited[i][j])
            {
                cave[i + dis][j] = 'x';
                cave[i][j] = '.';
            }
        }
    }
}

void fall_clusters()
{

    pair<int, int> fall_clusters_pos = get_fall_clusters();

    if(fall_clusters_pos.first != -1 && fall_clusters_pos.second != -1){
        adjust_one_cluster(fall_clusters_pos);
    }
}

int main(void)
{

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> cave[i];
    }
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> highs[i];
    }

    for (int i = 0; i < N; i++)
    {
        erase_minaral(i % 2 == 0, R - highs[i]);
        fall_clusters();
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << cave[i][j];
        }
        cout << '\n';
    }

    return 0;
}