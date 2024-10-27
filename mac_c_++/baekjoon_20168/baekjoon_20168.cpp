#include<iostream>
#include <algorithm>

using namespace std;

int ans = -1;

    int N, M, start_node, end_node, C;
    int graph[15][15] = {0};
    int visited[15] = {0};

void dfs(int node, int total_pay, int max_pay){

    // cout << node << ' ' << total_pay << ' ' << max_pay << endl;

    if(node == end_node){
        if(total_pay <= C){
            // ans = min(max_pay, ans)
            // cout << node << ' ' << total_pay << ' ' << max_pay << ' '  << C << endl;
            if(ans == -1){
                ans = max_pay;
            }else{
                ans = min(max_pay, ans);
            }
        }

        return;
    }

    for(int i = 1; i <= N; i++){
        int cost = graph[node][i];
        if(cost > 0 && !visited[i]){
            visited[i] = true;
            dfs(i, total_pay + cost, max(cost, max_pay));
            visited[i] = false;
        }
    }
}

int main(void){
    //dfs다!!!!
    int node1, node2, cost;



    cin >> N >> M >> start_node >> end_node >> C;

    for(int i = 0; i < M; i++){
        cin >> node1 >> node2 >> cost;
        graph[node1][node2] = cost;
        graph[node2][node1] = cost;
    }

    visited[start_node] = true;
    dfs(start_node, 0, 0);

    cout << ans;

    return 0;

}