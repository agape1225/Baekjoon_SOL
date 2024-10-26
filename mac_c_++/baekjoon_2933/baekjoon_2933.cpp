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

    // 마지막 row만 보면됨
    bool visited[105][105] = {0};
    pair<int, int> pos = {-1, -1};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (cave[i][j] == 'x' && !visited[i][j])
            {

                // cout << "--------------------------" << endl;

                // bfs start
                int min_row = -1;
                int start_row = i;
                int start_col = j;
                queue<pair<int, int>> q;

                visited[i][j] = true;
                q.push(make_pair(i, j));

                while (!q.empty())
                {

                    // cout << i << ' ' << j << endl;
                    int curr_row = q.front().first;
                    int curr_col = q.front().second;
                    q.pop();

                    

                    min_row = max(min_row, curr_row);
                    // cout << curr_row << ' ' << curr_col << ' ' << min_row << endl;

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
                    // cout << min_row << endl;
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
    // string new_cave[105];

    // for(int i = 0; i < R; i++){
    //     new_cave[i] = cave[i];
    // }

    // bfs start
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

        // int min_row = R;
        // for(int row = R - 1; row >= 0; row--){
        //     if(cave[row][col] == '.'){
        //         min_row = row;
        //         break;
        //     }
        // }

        // // cout << min_row << ' ' << max_row << endl;

        // if(max_row != -1)
 
        //     dis = min(min_row - max_row, dis);
    }

    // cout << "dis : " << dis << endl;


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

    // for (int i = 0; i < R; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //     {
    //         cout << visited[i][j] << ' ';
    //     }
    // }
    // cout << '\n';
}

void fall_clusters()
{

    pair<int, int> fall_clusters_pos = get_fall_clusters();

    if(fall_clusters_pos.first != -1 && fall_clusters_pos.second != -1){
        adjust_one_cluster(fall_clusters_pos);
    }

    // cout << fall_clusters_pos.first << ' ' << fall_clusters_pos.second << endl;
    // while (fall_clusters_pos.first != -1 && fall_clusters_pos.second != -1)
    // {

        
    //     // break;

    //     adjust_one_cluster(fall_clusters_pos);
    //     // for (int i = 0; i < R; i++)
    //     // {
    //     //     for (int j = 0; j < C; j++)
    //     //     {
    //     //         cout << cave[i][j];
    //     //     }
    //     //     cout << '\n';
    //     // }
    //     // cout << '\n';

    //     fall_clusters_pos = get_fall_clusters();
    // }
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

        // erase
        erase_minaral(i % 2 == 0, R - highs[i]);
        //     for (int i = 0; i < R; i++)
        // {
        //     for (int j = 0; j < C; j++)
        //     {
        //         cout << cave[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        fall_clusters();

        // get new cluster

        // fall down
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

// ........
// ........
// .....xx.
// ...xxx..
// ..xxx...
// ..x.xxx.
// ..x...x.
// .xxx..x.