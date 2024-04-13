#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int cache[1005] = {0};
    
    //cache 값
    for(auto it : array){
        cache[it]++;
    }
    
    //값 구하기
    int max = 0;
    for(int i = 0; i < 1005; i++){
        if(cache[i] > max){
            max = cache[i];
        }
    }
    
    int max_count = 0;
    for(int i = 0; i < 1005; i++){
        if(cache[i] == max){
            max_count++;
        }
    }
    
    if(max_count > 1)
        return -1;
    
    for(int i = 0; i < 1005; i++){
        if(cache[i] == max){
            return i;
        }
    }   
    return answer;
}