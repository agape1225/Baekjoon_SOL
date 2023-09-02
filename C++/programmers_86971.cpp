#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    //전체 노드

    for (int i = 0; i < wires.size(); i++) {

        vector<int> graph[101];
        bool visited[101] = { 0 };
        int start = 0;
        int count = 0;

        for (int j = 0; j < wires.size(); j++) {
            if (j == i) {
                continue;
            }
            else {
                if (start == 0) {
                    start = wires[j][0];
                }
                graph[wires[j][0]].push_back(wires[j][1]);
                graph[wires[j][1]].push_back(wires[j][0]);
            }
        }

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {

            int node = q.front();
            q.pop();
            count++;

            for (int i = 0; i < graph[node].size(); i++) {
                if (!visited[graph[node][i]]) {
                    visited[graph[node][i]] = true;
                    q.push(graph[node][i]);
                }
            }
        }


        int tmp = abs(count - (n - count));
        answer = min(answer, tmp);
    }

    return answer;
}