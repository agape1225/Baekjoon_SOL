#include <iostream>
#include <algorithm>

using namespace std;

/*
    cache[i][j] = cache[i][j] 까지 올 수 있는 최소 비용
*/
pair<int, int> cache[1005][1005];

int main(void) {
    int map[1005][1005] = {0};
    
    int dir_y[3] = {-1, 0, 1};

    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];

            if(i == 0) {
                cache[i][j].first = map[i][j];
                cache[i][j].second = -1;
            }else {
                cache[i][j].first = 0;
                cache[i][j].second = -1;
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

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {

            if(i < N - 2) {
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        if(k != l && k != cache[i][j].second) {
                            int tmp_j = j;
                            int tmp_count = cache[i][j].first;
    
                            tmp_j += dir_y[k];
    
                            if(tmp_j < 0 ||  tmp_j >= M){
                                continue;
                            }
    
                            tmp_count += map[i + 1][tmp_j];
    
                            tmp_j += dir_y[l];
                            
                            if(tmp_j < 0 ||  tmp_j >= M){
                                continue;
                            }
    
                            tmp_count += map[i + 2][tmp_j];
    
                            if(cache[i + 2][tmp_j] == 0) {
                                cache[i + 2][tmp_j].first = tmp_count;
                                cache[i + 2][tmp_j].second = tmp_count;
                            }else if(cache[i + 2][tmp_j].first > tmp_count){
                                cache[i + 2][tmp_j].first = tmp_count;
                                cache[i + 2][tmp_j].second = tmp_count;
                            }
                        }
    
                    }
                }
            }else if(i < N - 1) {
                for(int k = 0; k < 3; k++) {
                    if(j + dir_y[k] < 0 || j + dir_y[k] >= M){
                        continue;
                    }

                    if(cache[i + 1][j + dir_y[k]] == 0) {
                        cache[i + 1][j + dir_y[k]].first = cache[i][j].first + map[i + 1][j + dir_y[k]];
                    }else{
                        cache[i + 1][j + dir_y[k]].first = min(cache[i + 1][j + dir_y[k]].first,cache[i][j].first + map[i + 1][j + dir_y[k]] );
                    }
                    
                }
            }
        }
        cout << endl;

        for(int row = 0; row < N; row++) {
            for(int col = 0; col < M; col++) {
                cout << cache[row][col].first << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }

    int answer = cache[N - 1][0].first;

    for(int j = 0; j < M; j++){
        answer = min(answer, cache[N - 1][j].first);
        // cout << cache[N - 1][j].first << ' ' << cache[N - 1][j].second << ' ';
    }

    cout << answer;

    return 0;

}