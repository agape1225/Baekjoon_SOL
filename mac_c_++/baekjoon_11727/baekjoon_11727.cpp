#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;

    int cache[1001];

    cache[1] = 1;
    cache[2] = 3;

    for(int i = 3; i <= n; i++){
        cache[i] = ((cache[i - 2]  * 2) + cache[i - 1]) % 10007;
    }
    cout << cache[n];

    return 0;
}