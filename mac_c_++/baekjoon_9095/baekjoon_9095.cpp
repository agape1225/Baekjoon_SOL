#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int cache[11] = {0};
    int N;
    
    cin >> N;

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for(int i = 4; i <= N; i++){
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
    }

    cout << cache[N] << '\n';
    }

    

    return 0;
}
