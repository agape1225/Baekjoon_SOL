#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct comp
{
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second > n2.second;
    }
};


int main(void) {
    int N, start, end;
    int ans = 0;
    vector<pair<int, int>> time_table;
    priority_queue< pair<int, int>, vector<pair<int, int>>, comp> pq;

    // pq.push(make_pair(1,2));
    // pq.push(make_pair(1,3));
    // pq.push(make_pair(1,4));
    // pq.push(make_pair(1,5));
    // pq.push(make_pair(1,6));

    // while(!pq.empty()) {
    //     cout << pq.top().second << endl;
    //     pq.pop();
    // }

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        time_table.push_back(make_pair(start, end));
    }

    sort(time_table.begin(), time_table.end());
    ans = 1;
    pq.push(time_table[0]);

    for(int i = 1; i < N; i++) {
        start = time_table[i].first;
        end = time_table[i].second;

        if(pq.top().second <= start) {
            pq.pop();
            pq.push(time_table[i]);
        }else {
            pq.push(time_table[i]);
            ans = ans < pq.size() ? pq.size() : ans;
        }
    }

    cout << ans;

    return 0;
}