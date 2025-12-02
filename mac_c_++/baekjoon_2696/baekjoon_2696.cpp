#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        int M, input;
        vector<int> arr;
        int count = 0;
        priority_queue<int> max_q;
        priority_queue<int, vector<int>, greater<int>> min_q;
        
        cin >> M;
        for(int i = 0; i < M; i++) {
            cin >> input;
            arr.push_back(input);
        }

        if(M % 2) {
            cout << (M / 2) + 1 << '\n';
        }else {
            cout << M / 2 << '\n';
        }
        
        for(int i = 0; i < M; i++) {
            
            if(max_q.size() == min_q.size()) {
                max_q.push(arr[i]);    
            }else {
                min_q.push(arr[i]);
            }
            
            
            if(!max_q.empty() && !min_q.empty() && max_q.top() > min_q.top()) {
                int max_num = max_q.top();
                max_q.pop();
                
                int min_num = min_q.top();
                min_q.pop();
                
                max_q.push(min_num);
                min_q.push(max_num);
            }
            
            if((i + 1) % 2) {
                cout << max_q.top() << ' ';    
                count++;
                if(count % 10 == 0) {
                    cout << '\n';
                }
            }
        }
        cout <<'\n';
    }
    return 0;
}