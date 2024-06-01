#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> cities[300001];

int N, M, K, X;

int main(void){
    cin >> N >> M >> K >> X;

    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        cities[from].push_back(to);
    }

    //BFS 알고리즘
    queue<pair<int, int>> q;
    bool visited[300001] = {0};
    vector<int> ans;

    q.push(make_pair(X, 0));
    visited[X] = true;

    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;

        q.pop();

        if(dis == K){
            // cout << node << '\n';
            ans.push_back(node);
            continue;
        }

        for(int i = 0; i < cities[node].size(); i++){
            int to_node = cities[node][i];
            int to_dis = dis + 1;

            if(!visited[to_node]){
                visited[to_node] = true;
                q.push(make_pair(to_node, to_dis));
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(auto it : ans){
        cout << it << '\n';
    }

    if(ans.size() == 0)
        cout << -1;

    return 0;
}