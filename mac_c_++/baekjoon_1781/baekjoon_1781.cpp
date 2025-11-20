#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

struct comp {
    bool operator()(pair<long long, long long> p1, pair<long long,long long> p2) {
        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};

int main(void) {
    priority_queue<
    pair<long long,long long>, vector<pair<long long, long long>>, comp
    >pq;
    long long N, a, b;
    long long ans = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        pq.push(make_pair(a, b));
    }

    // cout << endl;

    while(!pq.empty()) {
        // cout << pq.top().first << ' ' << pq.top().second << endl;
        // pq.pop();

        long long dead_line = pq.top().first;
        long long weight = pq.top().second;
        pq.pop();
        ans += weight;
        // cout << ans << endl;

        while(!pq.empty() && dead_line >= pq.top().first) {
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}