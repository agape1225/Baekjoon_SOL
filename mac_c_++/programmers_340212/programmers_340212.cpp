#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_max(vector<int> diffs){
    int max_level = diffs[0];
    
    for(int i = 1; i < diffs.size(); i++){
        max_level = max(max_level, diffs[i]);
    }
    
    return max_level;
}

long long get_time(vector<int> diffs, vector<int> times, int level){
    long long time = 0;
    
    for(int i = 0; i < diffs.size(); i++){
        int diff = diffs[i];
        int time_cur = times[i];
        
        if(level < diff){
            int time_prev = times[i - 1];
            time += ((time_cur + time_prev) * (diff - level)) + time_cur;
        }else{
            time += time_cur;
        }
    }
    return time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int min = 1;
    int max = get_max(diffs);
    int mid;
    
    while(min <= max){
        mid = (max + min) / 2;
        long long time = get_time(diffs, times, mid);
        if(time > limit){
            min = mid + 1;
        }else{
            answer = mid;
            max = mid - 1;
        }
        
    }
    
    return answer;
}