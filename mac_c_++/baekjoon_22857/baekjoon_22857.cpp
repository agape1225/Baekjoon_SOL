#include <iostream>
#include <algorithm>

using namespace std;

int cache[50005][105] = {0};
int arr[50005] = {0};

int main(void){
    int N, K;
    int ans = -1;

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    // 뒤에서 하나를 삭제

    for(int i = 1; i <= N; i++){

        bool is_even = arr[i] % 2 == 0;

        for(int j = 0; j <= K; j++){

            if(j == 0){
                if(is_even){
                    cache[i][j] = cache[i - 1][j] + 1;
                }else{
                    cache[i][j] = 0;
                }
                    
            }else{
                if(is_even){
                    cache[i][j] = cache[i - 1][j] + 1;
                }else{
                    cache[i][j] =  cache[i - 1][j - 1];
                }
            }
        }
    }

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            // cout << cache[i][j] << ' ';
                ans = max(ans, cache[i][j]);   
        }
        // cout << endl;
    }

    cout << ans;

    return 0;

}