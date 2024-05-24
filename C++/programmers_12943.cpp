#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    long long number = num;
    
    while(number > 1){
        
        if(answer >= 500)
            return -1;
        
        answer++;
        if(number % 2){
            number = number * 3 + 1;
            
        }else{
            number /= 2;
        }
    }
    return answer;
}
