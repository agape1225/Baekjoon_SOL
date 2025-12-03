#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>

using namespace std;

int main(void) {
    int graph[1005][1005] = {0};
    int n, m, k, start, end, weight;
    multiset<int> cache[1005];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        cin >> start >> end >> weight;

        graph[start][end] = weight;
    }

    cache[1].insert(0);
    pq.push(make_pair(0, 1));
    
    while(!pq.empty()) {
        int current_node = pq.top().second;
        int current_weight = pq.top().first;
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(graph[current_node][i] > 0) {
                int next_weight = current_weight + graph[current_node][i];
                if(cache[i].size() < k) {
                    
                    cache[i].insert(next_weight);
                    pq.push(make_pair(next_weight, i));
                }else {
                    auto it = cache[i].end();
                    if(*(--it) > next_weight) {
                        cache[i].erase(it);
                        cache[i].insert(next_weight);
                        pq.push(make_pair(next_weight, i));
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(cache[i].size() < k) {
            cout << "-1" << ' ';
        }else {
            cout << *(--cache[i].end()) << ' ';
        }
        
    }

    return 0;

}