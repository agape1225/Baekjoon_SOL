#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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

    // while(pq.size() > 1) {
    //     pq.pop();
    // }

    cout << pq.top();

    return 0;
}