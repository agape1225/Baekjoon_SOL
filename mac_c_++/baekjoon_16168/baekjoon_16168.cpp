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

    if(count == E){
        bool flag = true;
        for(int i = 1; i <= V; i++){
            if(!graph[i].empty()){
                flag =  false;
            } 
                
        }

        if(flag){
            is_ans = true;
        }
    }

    // bool ans = false;

    for(int i = 0; i < graph[current_node].size(); i++){
        int next = graph[current_node][i]; // 노드 x의 연결되어 있는 다음 노드
        graph[current_node].erase(graph[current_node].begin()+i); // 제거
        
        // 그 노드에서도 상호 연결이 되어있기 때문에 인덱스를 찾아 연결을 끊어줌
        auto it = find(graph[next].begin(),graph[next].end(),current_node);
        graph[next].erase(it);
        // or 연산을 통해 하나라도 true면 true
        dfs(next,count+1);
        i--; // i가 하나 줄었으므로 i--
    }
    // return ans;
}

int main(void){


    cin >> V >> E;

    for(int i = 0; i < E; i++){
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }




    for(int i = 1; i <= V; i++){
        int size = graph[i].size();
        if(size > max_size){
            max_size = size;
            start_node = i;
        }
    }

    visited_n[start_node] = true;
    dfs(start_node, 0);

    if(is_ans){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
    
}