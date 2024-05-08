#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(char a, char b){
    return a> b;
}

string solution(string X, string Y) {
    string answer = "";
    //X와 Y에 공통으로 들어가는 문자 찾기
    
    string common = "";
    int count_x[10] = {0};
    int count_y[10] = {0};
    bool is_zero = true;
        
    for(auto it : X){
        count_x[it -'0']++;
    }
    for(auto it : Y){
        count_y[it - '0']++;
    }
    
    for(int i = 0; i < 10; i++){
        if(count_x[i] > 0 && count_y[i] > 0){
            if(i > 0)
                is_zero = false;
            int count = min(count_x[i], count_y[i]);
            char tmp = i + '0';
            for(int j = 0; j < count; j++){
                answer += tmp;
            }
        }
    }
    
    sort(answer.begin(), answer.end(), comp);
    
    if(answer.size() == 0)
        answer = "-1";
    
    else if(is_zero)
        answer = "0";
    
    // answer = stoi(common);
    
    return answer;
}
