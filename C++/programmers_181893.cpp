#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> get_arr(vector<int> arr, int query, bool even){
    vector<int> ans;
    //짝수일때
    if(even){
        int max = query + 1;
        for(int i = 0; i < query + 1; i++){
            ans.push_back(arr[i]);
        }
    }
    //홀수일때
    else{
        int min = query - 1;
        for(int i = query; i < arr.size(); i++){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for(int i = 0; i < query.size(); i++)
        arr = get_arr(arr, query[i], i % 2 == 0);
    
    answer = arr;
    
    return answer;
}
