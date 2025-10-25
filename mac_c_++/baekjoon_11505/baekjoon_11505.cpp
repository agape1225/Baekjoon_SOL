#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000005] = {0};
long long tree[4000005] = {0};
long long MOD = 1000000007;

long long init_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = (
        init_tree(start, mid, node * 2) *
        init_tree(mid + 1, end, node * 2 + 1)
    ) % MOD;
}

long long get_result(int start, int end, int left, int right, int node) {
    if(right < start || end < left) {
        return 1;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return (get_result(start, mid, left, right, node * 2) * get_result(mid + 1, end, left, right, node * 2 + 1)) % MOD;
}

long long update_value(int start, int end, int node, int index, int value) {
    if (index < start || index > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] = value;
    }
    int mid = (start + end) / 2;
    long long left = update_value(start, mid, node * 2, index, value);
    long long right = update_value(mid + 1, end, node * 2 + 1, index, value);
    return tree[node] = (left * right) % MOD;
}

int main(void) {

    int N, M, K;
    int a, b, c;

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i + 1];
    }

    init_tree(1, N, 1);

    // for(int i = 0; i < 30; i++) {
    //     cout << tree[i] << ' ';
    // }
    // cout << endl;

    for(int i = 0; i < M + K; i++) {

        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update_value(1, N, 1, b, c);
        }else {
            cout << get_result(1, N, b, c, 1) << '\n';
        }

    }


    return 0;

}