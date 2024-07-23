#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    int cache[1000001];
    cin >> N;

    cache[1] = 0;

    for(int i = 2; i <= N; i++){
        int tmp = 1000001;
        if(i % 3 == 0){
            tmp = cache[i / 3] + 1;
        }

        if(i % 2 == 0){
            tmp = min(cache[i / 2] + 1, tmp);
        }

        tmp = min(tmp, cache[i - 1] + 1);

        cache[i] = tmp;

    }

    cout << cache[N];

    return 0;
}