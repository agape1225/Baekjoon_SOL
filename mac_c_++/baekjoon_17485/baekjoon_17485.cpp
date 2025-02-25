#include <iostream>
#include <algorithm>

using namespace std;

/*
    cache[i][j] = [i][j] 까지 올 수 있는 최소 비용

    cache[i][j].first = 비용
    second = 방향

    cacche[i][j] = min( cache[i][j] , cache[i - 1][j] + map[i][new_j]);
        * new_j - i != cache[i - 1][j].second;
*/
int cache[1005][1005][3];

int main(void) {
    int map[1005][1005] = {0};
    
    int dir_y[3] = {-1, 0, 1};

    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];

            if(i == 0) {
                cache[i][j][0] = map[i][j];
                cache[i][j][1] = map[i][j];
                cache[i][j][2] = map[i][j];
                
            }else {
                cache[i][j][0] = 0;
                cache[i][j][1] = 0;
                cache[i][j][2] = 0;
            }
        }
    }

    // for(int i = 0; i < N - 1; i++) {
    //     for(int j = 0; j < M; j++) {
            
    //         for(int k = 0; k < 3; k++) {
    //             if(cache[i][j].second != k) {
    //                 int new_j = j + dir_y[k];

    //                 if(new_j < 0 || new_j >= M) {
    //                     continue;
    //                 }
    //                 int tmp_count = cache[i][j].first + map[i + 1][new_j];

    //                     if(cache[i + 1][new_j].first == 0) {
    //                         cache[i + 1][new_j].first = tmp_count;
    //                         cache[i + 1][new_j].second = k;
    //                     }else if(cache[i + 1][new_j].first > tmp_count) {
    //                         cache[i + 1][new_j].first = tmp_count;
    //                         cache[i + 1][new_j].second = k;
    //                     }
    //             }
    //         }
    //     }

    //     // for(int j = 0; j < M; j++){
    //     //     cout << cache[i ][j].first << ' ' << cache[i][j].second << ' ';
    //     // }
    //     // cout << endl;
    //}

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 3; k++) {

                if(k == 0) {
                    int count = 0;
                    int new_col = j + dir_y[k];
                    
                    if(new_col )
                }else if(k == 1) {

                }else if(k == 2) {

                }

                cache[i][j][k] = min(

                )
            }
            
        }
        // cout << endl;

        // for(int row = 0; row < N; row++) {
        //     for(int col = 0; col < M; col++) {
        //         cout << cache[row][col].first << ' ';
        //     }
        //     cout << endl;
        // }

        // cout << endl;
    }

    int answer = cache[N - 1][0].first;

    for(int j = 0; j < M; j++){
        answer = min(answer, cache[N - 1][j].first);
        // cout << cache[N - 1][j].first << ' ' << cache[N - 1][j].second << ' ';
    }

    cout << answer;

    return 0;

}