#include <iostream>
#include <algorithm>
using namespace std;

int S[50005];
int cache[50005][105] = {0};

int main(void){
    int N, K;
    
    int ans = -1;
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    for(int i = 1; i <= N; i++){
        bool is_even = S[i - 1] % 2 == 0;
        for(int j = 0; j <= K; j++){

            if(is_even){
                cache[i][j] = cache[i - 1][j] + 1;
            }
            
            if(j != 0 && !is_even){
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
