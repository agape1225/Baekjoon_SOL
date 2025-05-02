#include <iostream>
#include <algorithm>

using namespace std;

int roots[500005] = {0};
int edges[500005] = {0};
int count_nodes[500005] = {0};

int get_root(int node) {
    if(node == roots[node]) {
        return node;
    }
    return roots[node] = get_root(roots[node]);
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int node1, node2;
    int ans = 0;

    cin >> n >> m;

    //init roots;

    for(int i = 0; i < n; i++) {
        roots[i] = i;
        count_nodes[i] = 1;
    }

    for(int i = 0; i < m; i++) {
        cin >> node1 >> node2;

        // int root = union_nodes(node1, node2);
        int root1 = get_root(node1);
        int root2 = get_root(node2);

        // cout << root1 << ' ' << root2 << endl;

        if(root1 != root2) {
            if(root1 < root2) {
                roots[root2] = root1;
                count_nodes[root1] += count_nodes[root2];
                count_nodes[root2] = 0;

                edges[root1]++;
                edges[root1] += edges[root2];
                edges[root2] = 0;


            }else {
                roots[root1] = root2;
                count_nodes[root2] += count_nodes[root1];
                count_nodes[root1] = 0;

                edges[root2]++;
                edges[root2] += edges[root1];
                edges[root1] = 0;
                // edges[root1]++;
            }
        }else {
            edges[root1]++;
        }

        // cout << edges[root1] << ' ' << edges[root2] << ' ' << count_nodes[root1] << endl << endl;

        if(ans == 0 ) {
            if(root1 < root2) {
                if(count_nodes[root1] == edges[root1]) {
                    ans = i + 1;
                }
            }else {
                if(count_nodes[root2] == edges[root2]) {
                    ans = i + 1;
                }
            }
            
        }
    }

    cout << ans;

    return 0;
}