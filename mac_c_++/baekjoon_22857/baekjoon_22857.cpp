#include <iostream>
#include <algorithm>

using namespace std;

    int cache[50001][101] = {0};
    int arr[50001];

int main(void){


    int N, K;
    int ans = -1;

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        bool is_even = arr[i - 1] % 2 == 0;
        for(int j = 0; j <= K; j++){

            if(is_even){
                cache[i][j] = cache[i - 1][j] + 1;
            }else if(j != -1){
                cache[i][j] = cache[i - 1][j - 1];
            }
            
        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            ans = max(ans, cache[i][j]);
        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            cout << cache[i][j] << ' ';
        }
        cout << endl;
    }

    cout << ans;

    return 0;
}