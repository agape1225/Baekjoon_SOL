#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int cache[1005] = {0};
    int N;
    cin >> N;

    cache[1] = 1;
    cache[2] = 2;

    for(int i = 3; i <= N; i++){
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
    }
    
    cout << cache[N];

    return 0;
}