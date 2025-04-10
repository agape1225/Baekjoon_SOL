#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[1000000] = {0};
long long tree[4000000] = {0};

long long init_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

long long get_sum(int start, int end, int left, int right, int node) {
    if(right < start || end < left){
        return 0;
    }
    
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return get_sum(start, mid, left, right, node * 2) + get_sum(mid + 1, end, left, right, node * 2 + 1);
}

void update_node(int start, int end, int index, int node, long long diff) {
    if(index < start || end < index) {
        return;
    }

    tree[node] += diff;

    if(start != end) {
        int mid = (start + end) / 2;
        update_node(start, mid, index, node * 2, diff);
        update_node(mid + 1, end, index, node * 2 + 1, diff);
    }
}

int main(void) {
    int N, K, M;
    int a, b;
    long long c;

    cin >> N >> K >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // for(int i = 0; i < N * 4; i++) {
    //     cout << tree[i] << ' ';
    // }
    // cout << endl;

    init_tree(0, N - 1, 1);

    for(int i = 0; i < K  + M; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update_node(0, N - 1, b - 1, 1, c- arr[b - 1]);
            arr[b - 1] = c;

                for(int i = 0; i < N * 4; i++) {
                    cout << tree[i] << ' ';
                }
                cout << endl;
        }else {
            cout << get_sum(0, N - 1, b, c, 1) << '\n';
        }
    }

    return 0;

}