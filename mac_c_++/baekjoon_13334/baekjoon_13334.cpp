#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int n, h, o, L;
    int ans = 0;
    vector<pair<int, int>> coops;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h >> o;

        if(h > o) {
            swap(h, o);
        }

        coops.push_back(make_pair(o, h));
    }

    cin >> L;

    sort(coops.begin(), coops.end());

    for(int i = 0; i < n; i++) {
        int start = coops[i].second;
        int end = coops[i].first;

        if(end - start > L) {
            continue;
        }
        pq.push(start);
        while(!pq.empty() && end - pq.top() > L) {
            pq.pop();
        }

        ans = max(ans, (int) pq.size());

    }

    cout << ans;

    return 0;


}