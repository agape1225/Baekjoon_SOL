#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int cache[205] = {0};

//find
int find_node(int node){
    if(cache[node] == node){
        return node;
    }
    return cache[node] = find_node(cache[node]);
}

//union
void union_nodes(int node1, int node2){
    int root1 = find_node(node1);
    int root2 = find_node(node2);

    if(root1 <= root2){
        cache[root2] = root1;
    }else{
        cache[root1] = root2;
    }

}

bool check_nodes(int node1, int node2){
    int root1 = find_node(node1);
    int root2 = find_node(node2);

    return root1 == root2;
}

int main(void){
    int N, M;
    bool graph[205][205];
    int ans[1005];
    
    
    cin >> N >> M;

    
    for(int i = 0; i < N; i++){
        cache[i] = i;
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        cin >> ans[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j]){
                union_nodes(i, j);
            }
        }
    }

    //ans 판단
    string str = "YES";

    for(int i = 0; i < M - 1; i++){
        int from = ans[i] - 1;
        int to = ans[i + 1] - 1;

        if(!check_nodes(from, to)){
            str = "NO";
            break;
        }
    }

    cout << str;

    return 0;


}