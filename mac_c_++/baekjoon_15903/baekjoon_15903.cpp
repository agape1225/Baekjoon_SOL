#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    long long input;
    long long ans = 0;
    long long N, M;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    cin >> N >> M;

    for(long long i = 0; i < N; i++) {
        cin >> input;
        pq.push(input);
    }

    for(long long i = 0; i < M; i++) {
        long long tmp = pq.top();
        pq.pop();

        tmp += pq.top();
        pq.pop();

        pq.push(tmp);
        pq.push(tmp);
    }

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}