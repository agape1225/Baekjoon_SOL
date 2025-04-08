#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[100000] = {0};
long long max_tree[400000] = {0};
long long min_tree[400000] = {0};

long long init_max_tree(int start, int end, int node) {
    if(start == end) {
        return max_tree[node] = arr[start];
    }
    
    int mid = (start + end) / 2;
    return max_tree[node] = max(
        init_max_tree(start, mid, node * 2),
        init_max_tree(mid + 1, end, node * 2 + 1)
    );
}

long long init_min_tree(int start, int end, int node) {
    if(start == end) {
        return min_tree[node] = arr[start];
    }
    
    int mid = (start + end) / 2;
    return min_tree[node] = min(
        init_min_tree(start, mid, node * 2),
        init_min_tree(mid + 1, end, node * 2 + 1)
    );
}

long long get_max(int start,  int end, int left, int right, int node) {
    if(right < start || end < left) {
        return 0;
    }

    if(left <= start && end <= right ) {
        return max_tree[node];
    }

    int mid = (start + end) / 2;
    return max(
        get_max(start, mid, left, right, node * 2),
        get_max(mid + 1, end, left, right, node * 2 + 1)
    );
}

long long get_min(int start,  int end, int left, int right, int node) {
    if(right < start || end < left) {
        return 1000000000;
    }

    if(left <= start && end <= right ) {
        return min_tree[node];
    }

    int mid = (start + end) / 2;
    return min(
        get_min(start, mid, left, right, node * 2),
        get_min(mid + 1, end, left, right, node * 2 + 1)
    );
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init_max_tree(0, N - 1, 1);
    init_min_tree(0, N - 1, 1);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << get_min(0, N -1, a - 1, b - 1, 1) << ' ' << get_max(0, N - 1, a - 1, b - 1, 1) << '\n';
    }

    return 0;
}