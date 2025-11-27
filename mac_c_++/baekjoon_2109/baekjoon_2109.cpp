#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    int N;
    int ans = 0;
    int weight, time;
    int max_num = -1;
    vector<pair<int, int>> arr;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> weight >> time;
        arr.push_back(make_pair(time, weight));
        max_num = max(max_num, time);
    }

    sort(arr.begin(), arr.end());

    int index = 0;
    for(int i = 1; i <= max_num; i++) {
        while(index < N && arr[index].first <= i) {
            pq.push(arr[index].second);
            index++;
        }

        while(pq.size() > i) {
            // cout << pq.top() << ' ' << i << ' ' << pq.size() << ' ' << endl;
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

/*
20 1
2 1

100 2
8 2

10 3

50 10

5 20
*/