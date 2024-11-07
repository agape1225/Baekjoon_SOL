#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    
    int N, M;
    
    cin >> N >> M;

    while(N != 0 && M != 0){

        int arr[1005][1005] = {0};
        int dp[1005][1005] = {0};

        int ans = 0;
        // int max = 0;

        for(int row = 0; row < N; row++){
            for(int col = 0; col < M; col++){
                cin >> arr[row][col];
                dp[row][col] = arr[row][col];
                ans = max(dp[row][col], ans);
            }
        }

        for(int row = 1; row < N; row++){
            for(int col = 1; col < M; col++){
                if(arr[row][col] == 1){
                    dp[row][col] = min( dp[row - 1][col], min(dp[row][col - 1], dp[row - 1][col - 1])) + 1;
                }
                
            }
        }

        for(int row = 0; row < N; row++){
            for(int col = 0; col < M; col++){
                ans = max(ans, dp[row][col]);
            }
        }

        cout << ans << '\n';

        cin >> N >> M;

    }

    return 0;
}