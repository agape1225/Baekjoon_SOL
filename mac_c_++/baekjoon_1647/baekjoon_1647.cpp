#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cache[100005] = {0};

int find_root(int node) {
    if(cache[node] == node) {
        return node;
    }
    return cache[node] = find_root(cache[node]);
}

void union_node(int node1, int node2) {
    int root1 = find_root(node1);
    int root2 = find_root(node2);

    if(root1 < root2) {
        cache[root2] = root1;
    }else {
        cache[root1] = root2;
    }
}

bool is_in_union(int node1, int node2) {
    int root1 = find_root(node1);
    int root2 = find_root(node2);

    return root1 == root2;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pair<int, pair<int, int>>> pq;
    int N, M;
    int a, b, c;
    int ans = 0;
    int count_node = 1;
    int last_weight = 0;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cache[i] = i;
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        pq.push(make_pair(-c, make_pair(a, b)));
    }

    // cout << endl;

    while(count_node < N) {
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;

        int weight = -pq.top().first;

        

        pq.pop();

        if(is_in_union(node1, node2)) {
            continue;
        }

        // cout << node1 << ' ' << node2 << ' ' << weight << endl;

        union_node(node1, node2);
        ans += weight;
        count_node++;
        last_weight = weight;
    }

    cout << ans - last_weight;

    return 0;
}