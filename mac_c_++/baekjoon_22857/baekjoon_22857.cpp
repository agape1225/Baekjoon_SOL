#include <iostream>

using namespace std;

int main() {

    int N, K;
    int arr[50005] = {0};
    int cache[50005][105] = {0};
    int ans = -1;
    
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i + 1];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            if(arr[i] % 2 == 0){
                cache[i][j] = cache[i - 1][j] + 1;
            }else{
                cache[i][j] = cache[i - 1][j - 1];
            }
        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            ans = max(ans, cache[i][j]);
        }
    }

    cout << ans;
    
    
    return 0;
}