#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int rgb[3][1005];
    int ans = 987654321;

    cin >> N;

    for(int i = 0; i < N; i++) {
        // red green blue 순서
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    }

    for(int start = 0; start < 3; start++) {

        int cache[3][1005] = {0};

        for(int j = 0; j < 3; j++) {
            if(j == start) {
                cache[j][0] = rgb[j][0];
            }else {
                cache[j][0] = 987654321;
            }
        }


        for(int i = 1; i < N; i++) {
            cache[0][i] = rgb[0][i] + min(cache[1][i - 1], cache[2][i - 1]);
            cache[1][i] = rgb[1][i] + min(cache[0][i - 1], cache[2][i - 1]);
            cache[2][i] = rgb[2][i] + min(cache[1][i - 1], cache[0][i - 1]);
        }

        for(int i = 0; i < 3; i++) {
            if(i == start) {
                continue;
            }
            ans = min(ans, cache[i][N - 1]);
        }

        // ans = min(ans, min(cache[0][N - 1], min(cache[1][N - 1], cache[2][N - 1])));
    }

    cout << ans;


    // for(int i = 1; i < N; i++) {
    //     if(i == 1) {
    //         cache[0][i] = cache[0][i - 1] + max(cache[1][i - 1], cache[2][i - 1]);
    //         cache[1][i] = cache[1][i - 1] + max(cache[0][i - 1], cache[2][i - 1]);
    //         cache[2][i] = cache[2][i - 1] + max(cache[1][i - 1], cache[0][i - 1]);
    //     }else if(i == N - 1) {
    //         cache[0][i] = cache[0][i - 1] + max(cache[1][i - 1], cache[2][i - 1]);
    //         cache[1][i] = cache[1][i - 1] + max(cache[0][i - 1], cache[2][i - 1]);
    //         cache[2][i] = cache[2][i - 1] + max(cache[1][i - 1], cache[0][i - 1]);
    //     }else {

    //     }
    // }
}