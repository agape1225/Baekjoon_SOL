#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    int N, input;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input;

        if(max_pq.size() == min_pq.size()) {
            max_pq.push(input);
        }else {
            min_pq.push(input);
        }

        if(!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
            int max_num = max_pq.top();
            max_pq.pop();

            int min_num = min_pq.top();
            min_pq.pop();

            max_pq.push(min_num);
            min_pq.push(max_num);
        }

        cout << max_pq.top() << '\n';
    }

    return 0;
    
}