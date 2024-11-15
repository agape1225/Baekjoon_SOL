#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[100005] = {0};
vector<int> graph[1000005];
pair<int, int> ans[1000005];
int N;
int start_node;
int count_num = 1;

void dfs(int node){
    pair<int, int> tmp;
    tmp.first = count_num;
    for(auto it : graph[node]){
        if(!visited[it]){
            visited[it] = true;
            count_num++;
            dfs(it);
        }
    }
    count_num++;
    tmp.second = count_num;
    ans[node] = tmp;
    
}

int main() {

    cin >> N;
    for(int i = 1; i<= N; i++){
        int root;
        int node;
        
        cin >> root >> node;
        
        while(node != -1){
            graph[root].push_back(node);
            cin >> node;
        }

        sort(graph[root].begin(), graph[root].end());
    }
    cin >> start_node;

    // for(int i = 1; i <= N; i++){
    //     for(auto it : graph[i]){
    //         cout << it << ' ';
    //     }
    //     cout << '\n';
    // }

    visited[start_node] = true;
    dfs(start_node);

    for(int i = 1; i <= N; i++){
        cout << i << ' ' << ans[i].first << ' ' << ans[i].second << '\n';
    }
    
    return 0;
}
