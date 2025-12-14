#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L, tmp;
    vector<int> arr;
    deque<int> dq;
    
    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(int i = 0; i < N; i++) {
        int last_index = i - L + 1;

        while(!dq.empty() && dq.front() < last_index) {
            dq.pop_front();
        }
        
        while(!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        cout << arr[dq.front()] << ' ';
    }

    return 0;

}