#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct comp
{
    /* data */

    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second < n2.second;
    }
};


int main(void) {
    int N, start, end;
    int ans = 0;
    vector<pair<int, int>> time_line;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        time_line.push_back({start, end});
    }

    sort(time_line.begin(), time_line.end());

    for(int i = 0; i < N; i++) {
        start = time_line[i].first;
        end = time_line[i].second;

        if(!pq.empty()) {
            if(start >= pq.top().second) {
                pq.pop();
            }
        }

        pq.push(time_line[i]);

        ans = ans < pq.size() ? pq.size() : ans;
    }

    cout << ans;

    return 0;
}