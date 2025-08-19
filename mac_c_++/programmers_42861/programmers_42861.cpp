#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

bool comp(vector<int> arr1, vector<int> arr2) {
    if(arr1[2] == arr2[2]) {
        if(arr1[1] == arr2[1]) {
            return arr1[0] < arr2[0];
        }
        return arr1[1] < arr2[1];
    }
    return arr1[2] < arr2[2];
}


// void dfs(int current_node, int sum, int n, int count_node) {
//     if(count_node == n ) {
//         answer = min(sum, answer);
//         return;
//     }
    
//     for(int i = 0; i < n; i++) {
//         if(current_node != i && islands[current_node][i] > 0 && !visited[i]) {
//             visited[i] = true;
//             dfs(i, sum + islands[current_node][i], n, count_node + 1);
//             visited[i] = false;
            
//         }
//     }
    
    
// }

int cache[105] = {0};

int get_root(int node) {
    if(node == cache[node]) {
        return node;
    }
    return cache[node] = get_root(cache[node]);
}

void union_nodes(int node1, int node2) {
    int root1 = get_root(node1);
    int root2 = get_root(node2);
    
    if(root1 < root2) {
        cache[root2] = root1;
    }else {
        cache[root1] = root2;
    }
}

int solution(int n, vector<vector<int>> costs) {
    
    int answer = 0;
    int count_node = 0;
    set<int> s;
    
    sort(costs.begin(), costs.end(), comp);
    
    for(int i = 0; i < n; i++) {
        cache[i] = i;
    }
    
    for(auto it : costs) {
        int node1 = it[0];
        int node2 = it[1];
        int cost = it[2];
        
        if(cache[node1] != cache[node2]) {
            answer += cost;
            s.insert(node1);
            s.insert(node2);
        }
        
        if(s.size() == n) {
            break;
        }
    }
    
    
    
    
    return answer;
}