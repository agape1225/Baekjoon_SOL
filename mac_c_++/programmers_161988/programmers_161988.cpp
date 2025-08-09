#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long cache[2][500005] = {0};
    
    //cache[0] == [1,-1,1,-1];
    cache[0][0] = sequence[0];
    for(int i = 1; i < sequence.size(); i++) {
        long long num = sequence[i];
        if(i % 2 == 1) {
            num = -num;
        }
        
        cache[0][i] = max(cache[0][i - 1] + num, num);
    }
    
    cache[1][0] = -sequence[0];
    for(int i = 1; i < sequence.size(); i++) {
        long long num = sequence[i];
        if(i % 2 == 0) {
            num = -num;
        }
        
        cache[1][i] = max(cache[1][i - 1] + num, num);
    }
    
    for(int i = 0; i < sequence.size(); i++) {
        // cout << cache[0][i] << ' ' << cache[1][i] << endl;
        answer = max(answer, 
                     max(cache[0][i], cache[1][i])
                    );
        
    }
    
    
    
    
    return answer;
}