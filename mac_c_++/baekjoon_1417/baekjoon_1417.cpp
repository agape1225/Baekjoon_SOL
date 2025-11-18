#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int num1, input;
    priority_queue<int> pq;
    int N;
    int count = 0;

    cin >> N;

    cin >> num1;

    for(int i = 0; i < N - 1; i++) {
        cin >> input;
        pq.push(input);
    }

    while(!pq.empty() && pq.top() >= num1) {
        count++;
        int tmp = pq.top();
        pq.pop();

        num1++;
        tmp--;
        pq.push(tmp);
    }

    cout << count;

    return 0;


}