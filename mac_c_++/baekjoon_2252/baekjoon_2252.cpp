#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    int N, M;
    vector<int> graph[32005];
    int cache[32005] = {0};
    bool visited[32005] = {0};
    queue<int> q;
    int from, to;

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> from >> to;

        graph[from].push_back(to);
        cache[to]++;
    }

    for(int i = 1; i <= N; i++){
        if(cache[i] == 0){
            q.push(i);
            visited[i] = true;
            // break;
        }
    }

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();

        cout << current_node << ' ';

        //간선 제거
        for(auto it : graph[current_node]){
            cache[it]--;
            if(!visited[it] && cache[it] == 0){
                visited[it] = true;
                q.push(it);

            }
        }
    }
    
    return 0;

}