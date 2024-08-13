#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int cache[1005] = {0};
    int n;

    cin >> n;

    cache[0] = 1;
    cache[1] = 2;

    for(int i = 2; i < n; i++){
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
    }

    cout << cache[n - 1];

    return 0;
}