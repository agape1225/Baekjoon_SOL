#include <cstdio>
#include <string>
#include <iostream> 
#include <vector>
using namespace std;  
vector<int> adj[3004];
int V, E, a, b,ok, visited[3004][3004];
void dfs(int here, int id, int cnt){
    if(cnt == E){
        ok = 1; return;
    }  
    for(int there : adj[here]){
        if(visited[here][there] == id || visited[there][here] == id) continue;
        visited[here][there] = visited[there][here] = id;
        dfs(there, id, cnt + 1); 
    }
    return; 
} 
int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E; 
    for(int i = 0; i < E; i++){
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    for(int i = 1; i <= V; i++){ 
        dfs(i, i, 0);  
        if(ok) break;
    }
    if(ok)cout << "YES"<<"\n";
    else cout << "NO" << "\n";  
     
    return 0;
} 
