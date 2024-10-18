#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n, m;
    int n1, n2;
    int x, y;
    bool graph[105][105] = {0};
    bool visited[105] = {0};
    int ans = -1;
    queue<pair<int, int>> q;
    
    cin >> n >> n1 >> n2 >> m;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }

    q.push(make_pair(n1, 0));
    visited[n1] = true;

    while(!q.empty()){
        int current_node = q.front().first;
        int current_count = q.front().second;
        q.pop();

        // cout << current_node << endl;

        if(current_node == n2){
            ans = current_count;
            break;
        }
        
        for(int i = 1; i <= n; i++){
            if(graph[current_node][i] && !visited[i]){
                visited[i] = true;
                q.push(make_pair(i, current_count + 1));
            }
        }
    }
    cout << ans;
        
    return 0;
}
