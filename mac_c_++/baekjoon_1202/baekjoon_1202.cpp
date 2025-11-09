#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool comp1(pair<int, int> n1, pair<int, int> n2) {
    return n1.first < n2.first;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

    vector<int> bags;
    vector<pair<int, int>> js;
    priority_queue<int> pq; 
    long long ans = 0;

    int weight, value, space;
    int N, K;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> weight >> value;
        js.push_back(make_pair(weight, value));
    }

    for(int i = 0; i < K; i++) {
        cin >> space;
        bags.push_back(space);
    }

    sort(js.begin(), js.end(), comp1);
    sort(bags.begin(), bags.end());

    // for(auto it : js) {
    //     cout << it.first << ' ' << it.second << endl;
    // }

    int j_index = 0;
    for(int i = 0; i < K; i++) {
        int bag_size = bags[i];

        while(j_index < N && js[j_index].first <= bag_size) {
            pq.push(js[j_index].second);
            j_index++;
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

    }
    
    cout << ans;

    return 0;
}