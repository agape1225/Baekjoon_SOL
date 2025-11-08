#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct  comp
{
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        if(n1.second == n2.second) {
            return n1.first < n2.first;
        }
        return n1.second < n2.second;
    }
};

bool comp1(pair<int, int> n1, pair<int, int> n2) {
    return n1.first < n2.first;
}

bool comp2(int a, int b) {
    return a > b;
}


int main(void) {
    priority_queue<int> pq;
    vector<int> bags;
    vector<pair<int, int>> j;
    int N, M;
    int answer = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        // pq.push(make_pair(a, b));
        j.push_back(make_pair(a, b));
    }

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        bags.push_back(a);
    }

    sort(j.begin(), j.end(), comp1);
    sort(bags.begin(), bags.end());

    

    int bag_index = 0;

    // for(int i = 0; i < N; i++) {
    //     cout << j[i].first << ' ' << j[i].second << endl;
    // }

    int j_index = 0;

    for(int i = 0; i < M; i++) {
        int bag_size = bags[i];

        while(j_index < N && j[j_index].first <= bag_size) {
            // cout << j[j_index].first << ' ' << bag_size << endl;
            pq.push(j[j_index].second);
            j_index++;
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }

    }
    // while(!pq.empty() && bag_index < M) {
    //     int bag_size = bags[bag_index++];
    //     while(!pq.empty() && bag_size < pq.top().first) {
    //         pq.pop();
    //     }

    //     if(!pq.empty()) {
    //         answer += pq.top().second;
    //         pq.pop();
    //     }
    // }

    cout << answer;

    // while(!pq.empty()) {
    //     cout << pq.top().first << ' ' << pq.top().second << endl;
    //     pq.pop();
    // }

    return 0;

}