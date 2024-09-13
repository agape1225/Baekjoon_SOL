#include <iostream>
#include <algorithm>

using namespace std;

int S[50005] = {0};
int cache[105][50005] = {0};

int N, K;

int ans = -1;

int main(void){

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> S[i];
    }

    for(int i = 1; i <= N; i++){
        bool is_even = S[i] % 2 == 0;

        for(int j = 0; j <= K; j++){
            
            if(is_even){
                cache[j][i] = cache[j][i - 1] + 1;
            }else if(j != 0){
                cache[j][i] = cache[j - 1][i - 1];
            }

        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            ans = max(ans, cache[j][i]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            cout << cache[j][i] << ' ';
        }
        cout << endl;
    }

    cout << cache[K][N];

    return 0;

}