//1, 2, 3, 4, 5

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){

    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

    priority_queue<int> max_queue;
    priority_queue<int> min_queue;
    int N, input;

    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> input;

        if(min_queue.size() == max_queue.size()) {
            max_queue.push(input);
        }else {
            min_queue.push(-input);
        }

        if(!min_queue.empty() && !max_queue.empty() && max_queue.top() > -min_queue.top()) {
            int min_top = -min_queue.top();
            int max_top = max_queue.top();

            max_queue.pop();
            min_queue.pop();

            max_queue.push(min_top);
            min_queue.push(-max_top);
        }

        cout << max_queue.top() << '\n';
        
    }

    return 0;
}