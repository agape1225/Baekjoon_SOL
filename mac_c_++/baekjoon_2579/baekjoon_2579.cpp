#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int N;
    int cache[305] = {0};
    int stairs[305] = {0};

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> stairs[i];
    }

    cache[0] = stairs[0];
    
    for(int i = 1; i < N; i++){
        if(i == 1){
            cache[i] = stairs[i] + stairs[i - 1];
        }
        else if(i == 2)
            cache[i] = max(stairs[i - 1], stairs[i - 2]) + stairs[i];
        else
            cache[i] = max(cache[i - 2], stairs[i - 1] + cache[i - 3]) + stairs[i];
    }

    cout << cache[N - 1];

    return 0;

}