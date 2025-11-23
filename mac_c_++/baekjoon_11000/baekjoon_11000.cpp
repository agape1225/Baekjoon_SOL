#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

int main(void) {
    int N, input1, input2;
    int ans = 0;
    vector<pair<int, int>> arr;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input1 >> input2;
        arr.push_back(make_pair(input1, input2));
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        int start = arr[i].first;
        int end = arr[i].second;

        // cout << start << ' ' << end << endl;

        

        if(!pq.empty() && pq.top().second <= start) {
            pq.pop();
        }
        pq.push(make_pair(start, end));

        // cout << pq.top().second << endl;

        // ans = max(ans, pq.size());

        ans = ans < pq.size() ? pq.size() : ans;
    }

    cout << ans;

    return 0;

}