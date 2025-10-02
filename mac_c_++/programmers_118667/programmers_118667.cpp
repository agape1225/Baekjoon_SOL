#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long long sum1 = 0;
    long long sum2 = 0;
    
    queue<int> q1, q2;
    
    for(auto it: queue1) {
        q1.push(it);
        sum1 += it;
    }
    
    for(auto it: queue2) {
        q2.push(it);
        sum2 += it;
    }
    
    int count = 0;
    int max_count = (queue1.size() + queue2.size()) * 4;
    
    while( max_count > count) {
        if(sum1 == sum2) {
            break;
        }
        
        if(sum1 > sum2) {
            int tmp = q1.front();
            q1.pop();
            
            q2.push(tmp);
            
            sum1 -= tmp;
            sum2 += tmp;
            
        }else {
            int tmp = q2.front();
            q2.pop();
            
            q1.push(tmp);
            
            sum2 -= tmp;
            sum1 += tmp;
        }
        
        count++;
    }
    
    if(sum1 != sum2) {
        count = -1;
    }
    
    
    return count;
}