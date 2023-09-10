#include <iostream>
#include <vector>
#include <queue>
#define INF 9876543210

using namespace std;

//Dijkstra
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int, int>> town[51];
    bool visited[51] = { 0 };
    int distance[51] = { 0 };
    int start = 1;

    for (int i = 1; i <= N; i++) {
        distance[i] = INF;
    }

    for (auto it : road) {
        town[it[0]].push_back(make_pair(it[2], it[1]));
        town[it[1]].push_back(make_pair(it[2], it[0]));
    }

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;
    visited[start] = true;

    while (!pq.empty()) {

        int node = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();

        for (int i = 0; i < town[node].size(); i++) {
            int next_node = town[node][i].second;
            int next_distance = town[node][i].first;

            if (distance[next_node] > dis + next_distance) {
                distance[next_node] = dis + next_distance;
                pq.push(make_pair(-(dis + next_distance), next_node));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (K >= distance[i]) {
            answer++;
        }
    }


    return answer;
}