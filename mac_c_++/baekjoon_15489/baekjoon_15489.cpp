/*
1
11
121
1331
14641
15101051
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int cache[35][35] = {0};
    long long ans = 0;
    int R, C, W;

    cin >> R >> C >> W;

    cache[1][1] = 1;

    for(int i = 2; i <= 30; i++){
        for(int j = 1; j<= i; j++){
            if(j == 1 || j == i ){
                cache[i][j] = 1;
            }else{
                cache[i][j] = cache[i - 1][j] + cache[i - 1][j - 1];
            }

            // cout << cache[i][j] << ' ';
        }
        // cout << endl;
    }

    for(int i = 0; i < W; i++){
        for(int j =  0; j < i + 1; j++){
            ans += cache[R + i][C + j];
        }
    }


    cout << ans;


    return 0;
}