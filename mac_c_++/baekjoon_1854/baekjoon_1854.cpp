#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    int to, end, weight;
    int graph[1005][1005] = {0};
    priority_queue<int> cache[1005];
    priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
    >pq;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        cin >> to >> end >> weight;

        graph[to][end] = weight;
    }

    cache[1].push(0);
    pq.push(
        make_pair(0, 1)
    );
    while (!pq.empty())
    {
        int current_weight = pq.top().first;
        int current_node = pq.top().second;

        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(graph[current_node][i] > 0) {
                int next_weight = current_weight + graph[current_node][i];
                if(cache[i].size() < k) {
                    cache[i].push(
                        next_weight
                    );
                    pq.push(
                        make_pair(next_weight, i)
                    );
                }else {
                    if(cache[i].top() > next_weight) {
                        cache[i].pop();
                        cache[i].push(next_weight);
                        pq.push(
                            make_pair(next_weight, i)
                        );
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(cache[i].size() < k) {
            cout << "-1" << '\n'; 
        }else {
            cout << cache[i].top() << '\n';
        }
    }
    
    return 0;

}