#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int T;

    cin >> T;

    for(int t = 0; t < T; t++){
        int N;

        //일단 1과 2와 3의 값으로 내는 방법은
        long long cache[100005] = {0,1,2,2,3,3,6};

        cin >> N;

        for(int i = 7; i <= N; i++){
            cache[i] = (cache[i - 2] + cache[i - 4] + cache[i - 6]) % 1000000009;
        }

        cout << cache[N] << '\n';
    }

    return 0;
}