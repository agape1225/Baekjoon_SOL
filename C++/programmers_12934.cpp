#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    for(long long i = 0; i < 30000000; i++){
        
        if(i * i > n)
            break;
        
        if(i * i == n){
            return (i + 1) * (i + 1);
        }
    }
    
    return answer;
}
