#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(void) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int N, ans, input;
    ans = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input;
        pq.push(input);
    }

    while(pq.size() > 1) {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        int tmp = num1 + num2;
        pq.push(tmp);
        ans += tmp;
    }

    cout << ans;

    return 0;

}