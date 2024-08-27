#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int N;
    int board[105][105] = {0};
    long long cache[105][105] = {0};

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    cache[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if(i == N -1 && j == N - 1)
                continue;

            int dir = board[i][j];

            if(i + dir < N){
                cache[i + dir][j] += cache[i][j];
            }

            if(j + dir < N){
                cache[i][j + dir] += cache[i][j];
            }
        }
    }

    cout << cache[N - 1][N - 1];
    
    return 0;
}
