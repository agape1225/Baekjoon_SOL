#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define SIZE 20001
#define MAX  987654321

using namespace std;

vector<int> graph[SIZE];
int dis[SIZE];
int visited[SIZE] = { 0 };
priority_queue<pair<int, int>> pq;

void Dijkstra() {

    pq.push(make_pair(0, 1));
    
    while (!pq.empty()) {

        pair<int, int> buff = pq.top();
        pq.pop();

        if (!visited[buff.second]) {

            visited[buff.second] = true;
            dis[buff.second] = buff.first;

            for (auto it = graph[buff.second].begin(); it != graph[buff.second].end(); it++) {

                if (!visited[(*it)] && dis[(*it)] > buff.first + 1) {

                    dis[(*it)] = buff.first + 1;
                    pq.push(make_pair(buff.first + 1, (*it)));

                }

            }

        }

        for (int i = 1; i <= 6; i++)
            cout << dis[i] << ' ';
        cout << endl;

    }

}

int solution(int n, vector<vector<int>> edge) {

    int answer = 0;

    for (auto it = edge.begin(); it != edge.end(); it++) {

        int node1 = (*it)[0];
        int node2 = (*it)[1];

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);

    }

    for (int i = 1; i <= 6; i++) {

        for (int j = 0; j < graph[i].size(); j++) {

            cout << graph[i][j] << ' ';

        }

        cout << endl;

    }

    for (int i = 1; i <= n; i++) {
        
        dis[i] = MAX;
    }

    Dijkstra();

    int max = -1;
    int count = 0;

    for (int i = 1; i <= n; i++) {

        if (dis[i] >= MAX)
            continue;

        if (dis[i] > max) {
            max = dis[i];
            count = 1;
        }

        else if (dis[i] == max)
            count++;

    }

    answer = count;

    return answer;
}

int main(void) {

	vector<vector<int>> edge = { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };

    cout << endl << solution(6, edge);


}