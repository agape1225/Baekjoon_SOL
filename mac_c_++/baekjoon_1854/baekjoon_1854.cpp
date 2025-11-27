#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 987654321

using namespace std;

int main(void) {
    int graph[1005][1005] = {0};
    int n, m, k, start, end, weight;
    int cache[1005];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        cin >> start >> end >> weight;

        graph[start][end] = weight;
    }

    for(int i = 1; i <= n; i++) {
        cache[i] = INF;
    }

    cache[1] = 0;
    pq.push(make_pair(0, 1));
    
    while(!pq.empty()) {
        int current_node = pq.top().second;
        int current_weight = pq.top().first;
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(graph[current_node][i] > 0) {
                int next_weight = cache[current_node] + graph[current_node][i];
                if(next_weight < cache[i]) {
                    cache[i] = next_weight;
                    pq.push(make_pair(next_weight, i));
                }
            }
            
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << cache[i] << ' ';
    }

    return 0;

}