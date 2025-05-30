#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

    int N, M;
    int a, b;

    //차수
    int cache[32005] = {0};
    vector<int> graph[32005];
    priority_queue<int> pq;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        cache[b]++;
    }

    for(int i = 1; i <= N; i++) {
        if(cache[i] == 0) {
            pq.push(-i);
        }
    }

    while(!pq.empty()) {
        int node = -pq.top();
        pq.pop();

        cout << node << ' ';

        for(auto it : graph[node]) {
            cache[it]--;
            if(cache[it] == 0) {
                pq.push(-it);
            }
        }
    }

    return 0;
}