#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[1000000];
long long tree[2100000];

long long init_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

void update_tree(int start, int end, int node, int index, long long diff) {

    // cout << start << ' ' << end << ' ' << index << endl;

    if(start <= index && index <= end) {
        tree[node] += diff;

        if(start != end) {
            int mid = (start + end) / 2;

            update_tree(start, mid, node * 2, index, diff);
            update_tree(mid + 1, end, node * 2 + 1, index, diff);
        }
    }
}

long long get_sum(int start, int end, int left, int right, int node) {
    if(right < start || end < left){
        return 0;
    }

    if(left <=  start && end  <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return get_sum(start, mid, left, right, node * 2) + get_sum(mid + 1, end, left, right, node * 2 + 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    int a, b;
    long long c;

    cin >> N >> M >> K;

    for(int i= 0; i < N; i++) {
        cin >> arr[i];
    }

    init_tree(0, N - 1, 1);

    // for(int i = 0; i <= N * 4; i++) {
    //     cout << tree[i] << ' ';
    // }
    // cout << endl;

    for(int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        
        if(a == 1) {
            // b를 c로 수정
            update_tree(0, N - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;

            // for(int i = 0; i <= N * 4; i++) {
            //     cout << tree[i] << ' ';
            // }
            // cout << endl;


        }else {
            // b부터 c의 합을 출력
            cout << get_sum(0, N - 1, b - 1, c - 1, 1) << '\n';
        }

    }

    return 0;
    
}