#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N, input;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    for(int i = 0; i < N * N; i++) {
        cin >> input;
        pq.push(input);

        if(pq.size() > N) {
            pq.pop();
        }
    }

    // for(int i = 0; i < N - 1; i++) {
    //     pq.pop();
    // }

    cout << pq.top();

    return 0;
}