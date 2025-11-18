#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(pair<int, int> n1, pair<int, int> n2) {
    return n1.first < n2.first;
}

int main(void) {
    vector<long long> bag_sizes;
    vector<pair<long long, long long>> gem_infos;
    priority_queue<long long>pq;

    long long size, weight, ans;
    int N, K;

    ans = 0;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> size >> weight;
        gem_infos.push_back(make_pair(size, weight));
    }

    for(int i = 0; i < K; i++) {
        cin >> size;
        bag_sizes.push_back(size);
    }

    sort(bag_sizes.begin(), bag_sizes.end());
    sort(gem_infos.begin(), gem_infos.end(), comp);

    int bag_index = 0;

    for(int i = 0; i < K; i++) {

        int bag_size = bag_sizes[i];

        while(bag_index < N && bag_size >= gem_infos[bag_index].first) {
            pq.push(gem_infos[bag_index++].second);
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;

    
}