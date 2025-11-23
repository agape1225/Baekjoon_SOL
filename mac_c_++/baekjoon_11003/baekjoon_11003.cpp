#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

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
        if(!dq.empty()) {
            int index = dq.front();
            if(index <= i - L) {
                dq.pop_front();
            }
        }

        int tmp = arr[i];
        // if(arr[dq.back()] > arr)

        while(!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        cout << arr[dq.front()] << ' ';
    }

    return 0;

}