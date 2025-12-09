#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // vector<pair<int,int>> 
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> coops;
    int n, L;
    int start, end;
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        if(end < start) {
            swap(start, end);
        }

        coops.push_back(
            make_pair(end, start)
        );
    }

    cin >> L;

    sort(coops.begin(), coops.end());

    for(int i = 0; i < n; i++) {
        start = coops[i].second;
        end = coops[i].first;

        if(end - start > L) {
            continue;
        }

        pq.push(start);

        while(
            !pq.empty() &&
            end - pq.top() > L
        ) {
            pq.pop();
        }

        ans = max(ans, (int) pq.size());
    }

    cout << ans;

    return 0;
}