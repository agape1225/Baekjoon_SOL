#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1000001];
int count_in[1000001] = {0};
int count_out[1000001] = {0};

int get_ans_node(){
    int max_node = 0;
    int max_node_size = -1;
    for(int i = 0; i < 1000001; i++){
        //node is in graph
        if(count_in[i] == 0 && count_out[i] >= 2){
                return i;
        }
    }
    return -1;
}

int get_graph_type(int start_node){
    queue<int> q;
    
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
        
        count_in[edges[i][1]]++;
        count_out[edges[i][0]]++;
    }
    
    int start_node = get_ans_node();
    answer[0] = start_node;
    
    for(int i = 0; i < graph[start_node].size(); i++){
        int root_node = graph[start_node][i];
        int graph_type = get_graph_type(root_node);
        answer[graph_type]++;
    }
    
    return answer;
}
