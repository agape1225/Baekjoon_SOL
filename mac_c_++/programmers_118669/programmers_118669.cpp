#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    vector<bool> is_summits(n + 1, false);
    vector<vector<pair<int, int>>> maps(n + 1);
    vector<int> intensity( n + 1, 987654321);
    priority_queue<pair<int, int>> pq;
    
    for(auto it : summits) {
        is_summits[it] = true;
    }
    
    for(auto it : paths) {
        int node1 = it[0];
        int node2 = it[1];
        int length = it[2];
        
        maps[node1].push_back(make_pair(node2, length));
        maps[node2].push_back(make_pair(node1, length));
    }
    
    for(auto it : gates) {
        intensity[it] = 0;
        pq.push(make_pair(0, it));
    }
    
    while(!pq.empty()) {
        int current_length = -pq.top().first;
        int current_node = pq.top().second;
        
        pq.pop();
        
        if(is_summits[current_node]) {
            continue;
        }
        
        for(auto it : maps[current_node]) {
            int next_node = it.first;
            int next_length = it.second;
            int next_int = max(intensity[current_node], next_length);
            
            if(next_int < intensity[next_node]) {
                intensity[next_node] = next_int;
                pq.push(
                    make_pair(
                        -next_int, next_node
                    )
                );
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    
    answer[0] = -1;
    answer[1] = 987654321;
    
    for(auto it : summits) {
        if(intensity[it] < answer[1]) {
            answer[0] = it;
            answer[1] = intensity[it];
        }
    }
    
    
    return answer;
}