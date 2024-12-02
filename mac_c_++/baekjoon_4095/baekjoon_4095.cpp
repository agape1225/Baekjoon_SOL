#include <iostream>
#include <algorithm>

using namespace std;

int main(void){




    int N, M;
    int arr[1005][1005] = {0};
    int cache[1005][1005] = {0};

    cin >> N >> M;

    while(N != 0 && M != 0){


        for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            cache[i][j] = 0;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] == 1){
                cache[i][j] = min( cache[i - 1][j], min(cache[i][j - 1], cache[i - 1][j - 1]) ) + 1;
            }
        }
    }

    int ans = -1;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            ans = max(ans, cache[i][j]);
        }
    }

    cout << ans << '\n';

    cin >> N >> M;
    }

    

    return 0;

}