#include <string>
#include <vector>
#include <iostream>

using namespace std;

//broute force인가...?
long long solution(vector<int> weights) {
    long long answer = 0;
    int cache[4005] = {0};
    int count_cache[1005] = {0};
    bool dir_cache[1005] = {0};
    
    for(auto it : weights){
        count_cache[it]++; 
        cache[it * 2]++;
        cache[it * 3]++;
        cache[it * 4]++;
    }
    
    for(auto it : weights){
        
        answer += count_cache[it] - 1;
        
        if(cache[it * 2] > 1)
            answer += cache[it * 2] - (count_cache[it]);
        if(cache[it * 3] > 1)
            answer += cache[it * 3] - (count_cache[it]);
        if(cache[it * 4] > 1)
            answer += cache[it * 4] - (count_cache[it]);
    }
    
    return answer / 2;
}
