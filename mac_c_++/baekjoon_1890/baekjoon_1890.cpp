#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int board[105][105];
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
            
            if(i == N - 1 && j == N - 1)
                continue;
            
            long long tmp = cache[i][j];

            
            
            if( tmp > 0){
                int dis = board[i][j];
                if(i + dis < N){
                    cache[i + dis][j] += cache[i][j];
                }
                if(j + dis < N){
                    cache[i][j + dis] += cache[i][j];
                }
            }
        }
    }

    cout << cache[N - 1][N - 1];
    
    return 0;
}
