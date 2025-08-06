#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[205] = {0};
    
    int node_size = computers.size();
    
    for(int node = 0; node < node_size; node++) {
        if(!visited[node]) {
            visited[node] = true;
            answer++;
            queue<int> q;
            
            q.push(node);
            
            while(!q.empty()) {
                int current_node = q.front();
                q.pop();
                
                for(int i = 0; i < computers[current_node].size(); i++) {
                    
                    
                    if(computers[current_node][i] == 0) {
                        continue;
                    }
                    
                    int next_node = i;
                    
                    if(!visited[next_node]) {
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
            
            
        }
    }
    
    return answer;
}