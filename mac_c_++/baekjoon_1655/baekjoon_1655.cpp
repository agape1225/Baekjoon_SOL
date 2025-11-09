#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N, input;
    priority_queue<int> max_q;
    priority_queue<int> min_q;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input;

        if(max_q.size() == min_q.size()) {
            // cout << "max " << input << endl; 
            max_q.push(input);
            
        }else {
            // cout << "min " << input << endl;
            min_q.push(-input);
        }

        if(!max_q.empty() && !min_q.empty() && (max_q.top() > -min_q.top())) {
            int min_num = -min_q.top();
            int max_num = max_q.top();

            // cout << min_num << ' ' << max_num << endl;

            min_q.pop();
            max_q.pop();

            min_q.push(-max_num);
            max_q.push(min_num);
        }

        cout << max_q.top() << '\n';
    }

    return 0;
}