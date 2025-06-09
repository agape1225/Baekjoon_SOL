#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int candy_count[30005] = {0};
int root_count[30005] = {0};
int roots[30005] = {0};
int cache[30005][3005] = {0};
vector<pair<int, int>> candy_info;
int N, M, K;

int get_node(int root) {
    if(root == roots[root]) {
        return root;
    }
    return roots[root] = get_node(roots[root]);
}

void union_nodes(int node1, int node2) {

    int root1 = get_node(node1);
    int root2 = get_node(node2);
    
    if(root1 == root2) {
        return;
    }

    if(root1 < root2) {
        roots[root2] = root1;
        candy_count[root1] += candy_count[root2];
        root_count[root1] += root_count[root2];
    }else {
        roots[root1] = root2;
        candy_count[root2] += candy_count[root1];
        root_count[root2] += root_count[root1];
    }
}

void set_candy_info() {
    for(int i = 1; i <= N; i++) {

        if(roots[i] == i) {
            candy_info.push_back(make_pair(root_count[i], candy_count[i]));
        }
    
    }
}

int main(void) {

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> candy_count[i + 1];
        roots[i + 1] = i + 1;
        root_count[i + 1] = 1;
    }

    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        union_nodes(node1, node2);
    }

    set_candy_info();

    // 이걸로 배낭 문제 시작
    // for(auto it: candy_info) {
    //     cout << it.first << ' ' << it.second << endl;
    // }

    for(int i = 0; i < candy_info.size(); i++) {
        int persion = candy_info[i].first;
        int candy = candy_info[i].second;

        for(int j = 1; j < K; j++) {
            if(persion <= j) {
                cache[i + 1][j] = max(cache[i][j], cache[i][j - persion]+ candy);
            }else {
                cache[i + 1][j] = max(cache[i + 1][j - 1], cache[i][j]);
            }
            // cout <<candy << ' ' <<cache[i + 1][j] << endl;
        }
    }

    // for(int i = 0; i <= candy_info.size(); i++) {
    //     for(int j = 1; j <= K; j++) {
    //         cout << cache[i][j] << ' ' ;
    //     }
    //     cout << endl;
    // }

    cout << cache[candy_info.size()][K - 1];
    return 0;
}