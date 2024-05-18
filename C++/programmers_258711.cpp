#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> graph[1000001];
bool node[1000001] = {0};
int count_in[1000001] = {0};
int count_out[1000001] = {0};

bool is_isolated_node(int start_node){
    bool visited[1000001] = {0};
    queue<int> q;
    visited[start_node] = true;
    
    q.push(start_node);
    cout << start_node << endl << endl;
    while(!q.empty()){
        int front_node = q.front();
        q.pop();
        
        for(int i = 0; i < graph[front_node].size(); i++){
            int new_node = graph[front_node][i];
            cout << front_node << ' ' << new_node << endl;
            if(!visited[new_node]){
                visited[new_node] = true;
                q.push(new_node);
            }
        }
    }
    
    for(int i = 0; i < 1000001; i++){
        if(visited[i] != node[i])
            return false;
    }
    return true;
    
}

int get_ans_node(){
    int max_node = 0;
    int max_node_size = -1;
    for(int i = 0; i < 1000001; i++){
        //node is in graph
        if(node[i]){
            if(count_in[i] == 0 && count_out[i] >= 2){
                return i;
            }
        }
    }
    return -1;
}

int get_graph_type(int start_node){
    queue<int> q;
    bool visited[100001];
    
    
    
    if(graph[start_node].size() != 1){
            
            if(graph[start_node].size() == 0)
                return 2;
            else
                return 3;
    }
    
    q.push(graph[start_node][0]);
    
    while(true){
        int node = q.front();
        q.pop();
        // cout << start_node << ' ' << node << ' ' << graph[node].size() << endl;
        if(graph[node].size() != 1){
            
            if(graph[node].size() == 0)
                return 2;
            else
                return 3;
        }
        if(node == start_node)
            return 1;
        
        q.push(graph[node][0]);
        
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0, 0, 0, 0};
    int ans_node = -1;
    //정점을 구한다.
    
    //create graph
    for(int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        
        node[edges[i][0]] = true;
        node[edges[i][1]] = true;
        
        count_in[edges[i][1]]++;
        count_out[edges[i][0]]++;
    }
    
    int start_node = get_ans_node();
    answer[0] = start_node;
    
    for(int i = 0; i < graph[start_node].size(); i++){
        int root_node = graph[start_node][i];
        int graph_type = get_graph_type(root_node);
        // cout << root_node << ' ' << graph_type << endl;
        answer[graph_type]++;
    }
    
    return answer;
}
