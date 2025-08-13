#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(auto it: works) {
        pq.push(it);
    }
    
    while(n > 0 && pq.top() > 0) {
        n--;
        int tmp = pq.top();
        pq.pop();
        
        pq.push(tmp - 1);
    }
    
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}