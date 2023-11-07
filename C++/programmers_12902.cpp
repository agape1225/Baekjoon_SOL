#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long cache[5001] = {0};
    int answer = 0;
    
    if(n % 2 == 1)
        return 0;
    
    cache[0] = 1;
    cache[2] = 3;
    
    for(int i = 4; i <= n; i+= 2){
        
        cache[i] = cache[i - 2] * 3;
        for(int j=i-4; j>=0; j-=2){
                cache[i] += cache[j]*2;
        }
        cache[i] %= 1000000007;
        
    }
    
    answer = cache[n];
    
    return answer;
}
