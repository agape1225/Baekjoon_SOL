#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N, start, end;
    vector<pair<int, int>> rooms;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        rooms.push_back(make_pair(start, end));
    }

    sort(rooms.begin(), rooms.end());

    ans++;
    pq.push(rooms[0].second);
    for(int i = 1; i < N; i++) {
        start = rooms[i].first;
        end = rooms[i].second;

        // cout << pq.top() << ' ' << start << endl;

        while(!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
        ans = max(ans, (int) pq.size());
    }

    cout << ans;

    return 0;

}