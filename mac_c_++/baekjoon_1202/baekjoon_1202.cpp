#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    priority_queue<long long> pq;
    vector<long long> bags;
    vector<pair<long long, long long>> jew;

    long long ans = 0;
    long long size, weight;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> size >> weight;
        jew.push_back(
            make_pair(size, weight)
        );
    }

    for(int i = 0; i < K; i++) {
        cin >> size;
        bags.push_back(size);
    }

    sort(jew.begin(), jew.end());
    sort(bags.begin(), bags.end());

    int index = 0;
    for(int i = 0; i < K; i++) {
        size = bags[i];
        while(index < N && jew[index].first <= size) {
            pq.push(jew[index].second);
            index++;
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    
    cout << ans;

    return 0;

}