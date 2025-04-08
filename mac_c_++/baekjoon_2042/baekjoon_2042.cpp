#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


long long arr[1000000] = {0};
long long tree[2000000] = {0};

long long init_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int range_left, int range_right, int node) {

    if(range_left > end || start > range_right) {
        return 0;
    }

    if(range_left <= start && end <= range_right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    // 나눠서 탐색 진행
    return sum(start, mid, range_left, range_right, node * 2) + sum(mid + 1, end, range_left, range_right, node * 2 + 1);
}

void update(int start, int end, int node, int index, long long diff){

    if(start > index || index  > end) {
        return;
    }
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index, diff);
        update(mid + 1, end, node * 2 + 1, index, diff);
    }
}

int main(void) {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M, K;
    long long a, b, c;

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init_tree(0, N - 1, 1);

    // for(int i = 0; i < N * 2; i++) {
    //     cout << tree[i] << ' ';
    // }

    for(int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        if(a == 1) {
            //b번째를 c로 바꾸기
            // arr[b - 1] = c;
            update(0, N - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;

            // for(int i = 0; i < N * 2; i++) {
            //     cout << tree[i] << ' ';
            // }

        }else if(a == 2) {
            // b - c의 합
            cout << sum(0, N - 1, b - 1, c - 1, 1) << endl;
        }
    }

    return 0;
}