#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int stare[301] = {0};
    int cache[301] = {0};
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> stare[i];
    }

    cache[0] = stare[0];
    cache[1] = stare[0] + stare[1];
    cache[2] = max(stare[0], stare[1]) + stare[2];

    for(int i = 3; i < N; i++){
        cache[i] = max(cache[i - 3] + stare[i - 1], cache[i - 2] ) + stare[i];
    }

    cout << cache[N - 1];

    return 0;

}