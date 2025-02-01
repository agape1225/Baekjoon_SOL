#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> pipes[350];
int cache[100001] = {987654321};

int main(void) {
    int D, P;
    
    cin >> D >> P;

    for(int i = 0; i < P; i++) {
        cin >> pipes[i].first >> pipes[i].second;
    }

    // 알고즘 설계
    // 더해질 수 있으면 최솟값 의 최댓값

    for(int i = 0; i < P; i++) {
        int length = pipes[i].first;
        int size = pipes[i].second;

        for(int j = D; j >= length; j--) {


            cache[j] = max(cache[j], min(cache[j - length], size));
            // if(j >= length) {
            //     if(j == length) {
            //         cache[i + 1][j] = max(cache[i][j],  size);
            //     }else if(cache[i][j - length] > 0) {
            //         cache[i + 1][j] = max(cache[i][j], min(cache[i][j - length], size));
            //     }
                
            // }else {
            //     cache[i + 1][j] = cache[i][j];
            // }
        }
    }

    // for(int i = 0; i <= P; i++) {
    //     for(int j = 0; j <= D; j++) {
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << cache[D];

    return 0;


}