#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> graph[1000001];
bool node[1000001] = {0};
int count_in[1000001] = {0};
int count_out[1000001] = {0};

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
    
    q.push(start_node);
    
    while(true){
        int node = q.front();
        q.pop();
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
    if(int i = 0; i < graph[start_node].size(); i++){
        int root_node = graph[start_node][i];
        answer[get_graph_type(root_node)]++;
    }
    
    return answer;
}