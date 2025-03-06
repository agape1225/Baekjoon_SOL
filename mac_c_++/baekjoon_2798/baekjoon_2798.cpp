#include <iostream>

using namespace std;

int main(void) {
    int N , M;
    int cards[105];
    int ans = -1;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(i == j || j == k || i == k){
                    continue;
                }

                int sum = cards[i] + cards[j] + cards[k];
                if(sum <= M) {
                    ans = max(ans, sum);
                }

            }
        }
    }

    cout << ans;

    return 0;
}