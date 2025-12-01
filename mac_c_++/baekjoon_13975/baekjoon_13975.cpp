#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int K, input;
        long long ans = 0;

        cin >> K;

        for(int i = 0; i < K; i++) {
            cin >> input;
            pq.push(input);
        }

        while(pq.size() > 1) {
            int tmp1 = pq.top();
            pq.pop();

            int tmp2 = pq.top();
            pq.pop();

            ans += tmp1 + tmp2;

            pq.push(tmp1 + tmp2);
        }

        cout <<  ans << '\n';
    }

    return 0;
}