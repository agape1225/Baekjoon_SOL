#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(auto it : arr){
        if(it % divisor == 0){
            answer.push_back(it);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}
