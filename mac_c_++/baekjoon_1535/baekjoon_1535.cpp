#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    int hp[25];
    int joy[25];
    int cache[25][105] = {0};

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> hp[i];
    }

    for(int i = 1; i <= N; i++){
        cin >> joy[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 100; j++){
            if(j < hp[i]){
                cache[i][j] = cache[i - 1][j];
            }else{
                cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - hp[i]] + joy[i]);
            }
        }
    }

    cout << cache[N][99];

    return 0;

}