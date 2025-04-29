#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, R, Q;
long long cache[100005] = {0};
vector<int> graph[100005];
vector<int> tmp[100005];

void set_child(int root) {

    // 종료 조건
    if(graph[root].size() == 0) {
        cache[root] = 1;
    }else {
        for(auto child : graph[root]) {
            set_child(child);
            cache[root] += cache[child];
        }
        cache[root]++;
    }

    // cout << root << ' ' << cache[root] << endl;
}

void create_tree(){
    bool visited[100005] = {0};
    queue<int> q;
    visited[R] = true;
    q.push(R);

    while(!q.empty()) {
        int root = q.front();

        q.pop();

        for(auto it : tmp[root]) {
            if(!visited[it]) {
                graph[root].push_back(it);
                visited[it] = true;
                q.push(it);
            }
        }
    }

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;

    for(int i = 0; i < N - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        tmp[node1].push_back(node2);
        tmp[node2].push_back(node1);
    }

    create_tree();

    set_child(R);
    
    for(int i = 0; i < Q; i++) {
        int q;
        cin >> q;

        cout << cache[q] << '\n';
    }

    return 0;
}