#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer;
    int height = 0;
    int weight = 0;
    
    for(auto size : sizes){
        if(size[0] > size[1]){
            height = max(size[0] , height);
            weight = max(size[1] , weight);
        }else{
            height = max(size[1], height);
            weight = max(size[0], weight);
        }
    }
    
    return height * weight;
}