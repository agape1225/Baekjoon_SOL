#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

    vector<int> graph[3001];
    bool visited_n[3001] = {0};
    bool visited_e[3001][3001] = {0};
    int V, E;
    int node1, node2;
    int start_node = 1;
    int max_size = -1;
    bool is_ans = false;

void dfs(int current_node, int count){

    if(count >= E){
        bool flag = true;
        for(int i = 1; i <= V; i++){
            if(!visited_n[i]){
                flag = false;
            }
        }
        if(flag)
            is_ans = true;
        return;
    }

    for(auto it : graph[current_node]){
        if(!visited_e[current_node][it]){
            visited_e[current_node][it] = true;
            visited_e[it][current_node] = true;
            visited_n[it] = true;
            dfs(it, count + 1);
            }
        }
}

int main(void){


    cin >> V >> E;

    for(int i = 0; i < E; i++){
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }




    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            visited_n[j] = false;
        }
        for(int j = 1; j <= V; j++){
            for(int k = 1; k <= V; k++){
                visited_e[j][k] = false;
            }
        }
        visited_n[i] = true;
        dfs(i, 0);
    }

   

    

    if(is_ans){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
    
}