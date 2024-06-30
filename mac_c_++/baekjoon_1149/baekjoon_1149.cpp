#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int cost[3][1005];
    int cache[3][1005];
    int N;

    cin >> N;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> cost[i][j];
        }
    }

    cache[0][0] = cost[0][0];
    cache[1][0] = cost[1][0];
    cache[2][0] = cost[2][0];

    for (int i = 0; i < N; i++)
    {
        cache[0][i] = cost[0][i] + min(cache[1][i - 1], cache[2][i - 1]);
        cache[1][i] = cost[1][i] + min(cache[2][i - 1], cache[0][i - 1]);
        cache[2][i] = cost[2][i] + min(cache[0][i - 1], cache[1][i - 1]);
    }

    cout << min(cache[0][N - 1], min(cache[1][N - 1], cache[2][N - 1]));

    return 0;
}