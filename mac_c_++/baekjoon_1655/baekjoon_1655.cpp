#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<int> max_queue;
    priority_queue<int, vector<int>, greater<int> > min_queue;

    int N, input;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input;

        if(max_queue.size() == min_queue.size()) {
            max_queue.push(input);
        }else {
            min_queue.push(input);
        }

        if(
            !max_queue.empty() &&
            !min_queue.empty() &&
            max_queue.top() > min_queue.top()
        ) {
            int max_tmp = max_queue.top();
            int min_tmp = min_queue.top();

            max_queue.pop();
            min_queue.pop();

            max_queue.push(min_tmp);
            min_queue.push(max_tmp);
        }

        cout << max_queue.top() << '\n';
    }

    return 0;
}