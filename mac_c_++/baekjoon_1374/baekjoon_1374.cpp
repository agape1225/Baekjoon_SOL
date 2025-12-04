#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N;
    int num, start, end;
    vector<pair<int, int>> lectures;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 1;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num >> start >> end;

        lectures.push_back(
            make_pair(start, end)
        );
    }

    sort(lectures.begin(), lectures.end());

    pq.push(lectures[0].second);

    for(int i = 1; i < N; i++) {
        int next_start = lectures[i].first;

        while(!pq.empty() && pq.top() <= next_start) {
            pq.pop();
        }
        pq.push(lectures[i].second);

        ans = max((int)pq.size(), ans); 
    }

    cout << ans;

    return 0;



}