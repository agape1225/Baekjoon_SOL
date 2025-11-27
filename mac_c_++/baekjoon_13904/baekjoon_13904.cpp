#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(void) {
    int N, d, w;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> arr;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> d >> w;
        arr.push_back(
            make_pair(d, w)
        );
    }

    sort(arr.begin(), arr.end());

    int index = 0;
    for(int i = 1; i <= 1000; i++) {
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