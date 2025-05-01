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

    cache[0][0] = rgb[0][0];
    cache[1][0] = rgb[1][0];
    cache[2][0] = rgb[2][0];

    for(int start = 0; start < 3; start++) {


        int cache[3][1005] = {0};

        for(int end = 0; end < 3; end++) {
            
        }
    }


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