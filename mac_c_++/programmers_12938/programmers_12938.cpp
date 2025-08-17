#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    // int count = 1;
    while(0 < n) {
        answer.push_back(s / n);
        s -= s / n;
        n--;
        // count++;
    }
    // answer.push_back(s);
    
    return answer;
}