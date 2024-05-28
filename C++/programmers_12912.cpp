#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int start = -1;
    int end = -1;
    
    start = min(a,b);
    end = max(a, b);
    
    for(int i = start; i <= end; i++){
        answer+=i;
    }
    
    return answer;
}
