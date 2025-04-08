#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// vector<int> board[20005][20005]; 

vector<pair<int, int>> graph[20005];
priority_queue<pair<int, int>> pq;
int cost[20005] = {0};
bool visited[20005] = {0};
int V, E, K;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    K--;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back(make_pair(w, v -1));
    }

    for(int i = 0; i < V; i++) {
        cost[i] = 987654321;
    }

    pq.push(make_pair(K, 0));
    cost[K] = 0;

    while(!pq.empty()) {

        int node = pq.top().second;
        int weight = -pq.top().first;

        pq.pop();

        for(int i = 0; i < graph[node].size(); i++) {


            int next_node = graph[node][i].second;
            int next_weight = graph[node][i].first + weight;


            // cout << next_weight << endl;

            if(next_weight < cost[next_node]) {
                // visited[next_node] = true;
                cost[next_node] = next_weight;
                pq.push(make_pair(-next_weight, next_node));
            }
        }
    }

    for(int i = 0; i < V; i++) {
        if(cost[i] == 987654321){
            cout << "INF" << endl;
        }else {
            cout << cost[i] << endl;
        }
        
    }

    return 0;


}