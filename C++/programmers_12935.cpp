#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min = arr[0];
    
    for(int i = 0; i < arr.size(); i++){
        if(min > arr[i])
            min = arr[i];
    }
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == min)
            continue;
        answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}
