#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> arr1, vector<int> arr2) {
    if(arr1[1] == arr2[1]) {
        return arr1[0] < arr2[0];
    }
    return arr1[1] < arr2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int end_tmp;
    
    sort(routes.begin(), routes.end());
    end_tmp = routes[0][1];
    
    for(auto it : routes) {
        if(it[0] > end_tmp) {
            answer++;
            end_tmp = it[1];
        }
        
        if(end_tmp >= it[1]) {
            end_tmp = it[1];
        }
    }
    
    return answer;
}