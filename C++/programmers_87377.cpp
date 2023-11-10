#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long, long long>> coord;
    long long x_min = 100000000000;
    long long x_max = -100000000000;
    long long y_min = 100000000000;
    long long y_max = -100000000000;
    
    for(int i = 0; i < line.size(); i++){
        for(int j = i + 1; j < line.size(); j++){
            //둘의 점 구하기
            if(line[i][0] * line[j][1] == line[i][1] * line[j][0])
                continue;
            long long x_mole = (long long)line[i][1] * (long long)line[j][2] - (long long)line[i][2] * (long long)line[j][1];
            long long y_mole = (long long)line[i][2] * (long long)line[j][0] - (long long)line[i][0] * (long long)line[j][2];
            long long deno = (long long)line[i][0] * (long long)line[j][1] - (long long)line[i][1] * (long long)line[j][0];
        
            if(x_mole % deno == 0 && y_mole % deno == 0){
                long long x = x_mole / deno;
                long long y = y_mole / deno;
                coord.insert(make_pair(x, y));
                x_min = min(x_min, x);
                x_max = max(x_max, x);
                y_min = min(y_min, y);
                y_max = max(y_max, y);
            }
        }
    }
    
    long long x_size = abs(x_max - x_min) + 1;
    long long y_size = abs(y_max - y_min) + 1;
    
    if(coord.size() == 0)
        return answer;
    
    for(long long y = y_max; y >= y_min; y--){
        string tmp = "";
        for(long long x = x_min; x <= x_max; x++){
            if(coord.find(make_pair(x, y)) == coord.end()){
                tmp += ".";
            }else{
                tmp += "*";
            }
        }
        answer.push_back(tmp);
    }
    
    return answer;
}
