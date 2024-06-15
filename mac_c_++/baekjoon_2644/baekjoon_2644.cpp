#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int N, M;
    int to, from;
    int ans = -1;
    vector<int> graph[105];
    bool visited[105] = {0};

    cin >> N;
    cin >> to >> from;
    cin >> M;

    for(int i = 0; i < M; i++){
        int x, y;

        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //bfs

    queue<pair<int, int>> q;
    q.push(make_pair(to, 0));
    visited[to] = true;

    while(!q.empty()){

        int node = q.front().first;
        int count = q.front().second;
        q.pop();

        if(node == from){
            ans = count;
            break;
        }

        for(auto it : graph[node]){

            if(!visited[it]){
                visited[it] = true;
                q.push(make_pair(it, count + 1));
            }
        }
    }
    cout << ans;
    
    return 0;

}