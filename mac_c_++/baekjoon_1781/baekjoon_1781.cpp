#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

// struct comp {
//     bool operator()(pair<int, int> p1, pair<int, int> p2) {

//     }
// }

bool copm(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    long long ans = 0;
    long long tmp1, tmp2;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    vector<pair<int, int>> arr;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        arr.push_back(make_pair(tmp1, tmp2));
    }

    sort(arr.begin(), arr.end());

    int index = 0;
    for(int i = 1; i <= N; i++) {
        while(index < N && arr[index].first <= i) {
            pq.push(arr[index].second);
            index++;
        }

        while(pq.size() > i) {
            pq.pop();
        }
    }

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}