#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct comp {
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(void) {
    priority_queue<int, vector<int>, comp> pq;
    int N;
    int input;

    cin >> N;

    for(int i = 0; i < N; i++) {
        
        cin >> input;

        if(input == 0) {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }else {
                cout << 0 << '\n';
            }
            
        }else {
            pq.push(input);
        }
    }

    return 0;
}