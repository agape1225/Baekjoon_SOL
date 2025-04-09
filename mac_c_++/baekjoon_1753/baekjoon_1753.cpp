#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define INF 987654321

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E, K;
    int u, v, w;
    int cache[20005] = {0};
    vector<pair<int, int>> graph[20005];
    priority_queue<pair<int, int>> pq;

    cin >> V >> E;
    cin >> K;

    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    // init cache
    for(int i = 1; i <= V; i++) {
        cache[i] = INF;
    }

    pq.push(make_pair(0, K));
    cache[K] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = -pq.top().first;

        pq.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second + weight;

            if(cache[next_node] > next_weight) {
                cache[next_node] = next_weight;
                pq.push(make_pair(-next_weight, next_node));
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(cache[i] == INF) {
            cout << "INF" << '\n';
        }else {
            cout << cache[i] << '\n';
        }
        
    }

    return 0;

}