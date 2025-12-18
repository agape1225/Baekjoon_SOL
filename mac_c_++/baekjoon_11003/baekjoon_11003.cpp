#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L, input;
    vector<int> arr;
    deque<int> dq;

    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }

    for(int i = 0; i < N; i++) {
        int num = arr[i];
        while(!dq.empty() && dq.front() <= i - L) {
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] > num) {
            dq.pop_back();
        }

        dq.push_back(i);

        cout << arr[dq.front()] << ' ';
    }

    return 0;

}