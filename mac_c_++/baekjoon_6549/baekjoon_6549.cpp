#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005] = {0};
int tree[400005] = {0};

pair<long long, int> get_ans(int start, int end) {

    if(start == end) {
        return make_pair(arr[start], arr[start]);
    }

    int size = end - start;
    int mid = (start + end) / 2;

    pair<long long, int> result1 = get_ans(start, mid);
    pair<long long, int> result2 = get_ans(mid + 1, end);

    long long current_size = min(result1.second, result2.second) * (size + 1);

    return make_pair(
        max(max(current_size, result1.first), result2.first),
        min(result1.second, result2.second)
    );
}

int main(void) {
    while(true) {
        int n;
        cin >> n;

        if(n == 0) {
            return 0;
        }

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << get_ans(0, n - 1).first << '\n';
    }
}