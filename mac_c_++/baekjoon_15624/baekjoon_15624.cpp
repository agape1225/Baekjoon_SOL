#include <iostream>
#include <algorithm>

using namespace std;

int cache[1000005] = {0};

int main(void){

    int N;
    cin >> N;

    cache[0] = 0;
    cache[1] = 1;

    for(int i = 2; i <= N; i++){
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1000000007;
        // cout << cache[i] << ' ';
    }

    cout << cache[N];

    return 0;
    
}