#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L, input;
    deque<int> dq;
    vector<int> arr;

    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }

    for(int i = 0; i < N; i++) {
        int min_num = i - L + 1;
        if(!dq.empty()) {
            if(min_num >= 0 && dq.front() < min_num) {
                dq.pop_front();
            }
        }

        if(!dq.empty()) {
            while(!dq.empty() && arr[dq.back()] >= arr[i]) {
                dq.pop_back();
            }
        }

        dq.push_back(i);

        cout << arr[dq.front()] << ' ';
    }

    return 0;
}