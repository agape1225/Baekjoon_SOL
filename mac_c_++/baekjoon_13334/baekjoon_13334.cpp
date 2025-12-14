#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int n, h, o, ans = 0, L;
    vector<pair<int, int>> table;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> h >> o;
        if(h > o) {
            swap(h, o);
        }

        table.push_back(
            make_pair(o, h)
        );
    }

    cin >> L;

    sort(table.begin(), table.end());

    for(auto it : table) {
        cout << it.second << ' ' << it.first << endl;
    }

    for(int i = 0; i < n; i++) {
        h = table[i].second;
        o = table[i].first;

        if(o - h > L) {
            continue;
        }

        pq.push(h);

        while(!pq.empty() && o - pq.top() > L) {
            pq.pop();
        }

        ans = max(ans, (int) pq.size());
    }

    cout << ans;
}