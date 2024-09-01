#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int stairs[305] = {0};
    int cache[305] = {0};
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> stairs[i];
    }

    cache[0] = stairs[0];
    cache[1] = stairs[1] + stairs[0];

    cache[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for(int i = 3; i < N; i++){
        cache[i] = max(stairs[i -1] + cache[i - 3], cache[i - 2]) + stairs[i];
    }

    cout << cache[N - 1];

    return 0;
}