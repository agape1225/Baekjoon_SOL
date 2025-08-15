#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool can_changed(string str1, string str2) {
    int count_diff = 0;
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            count_diff++;
        }
    }
    // cout << str1 << ' ' << str2 << count_diff << endl;
    return count_diff < 2;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visited[55] = {0};
    queue<pair<int, string>> q;
    
    q.push(make_pair(0, begin));
    
    while(!q.empty()) {
        int current_count = q.front().first;
        string current_str = q.front().second;
        
        q.pop();
        
        if(current_str == target) {
            answer = current_count;
            break;
        }
        
        for(int i = 0; i < words.size(); i++) {
            if(!visited[i] && can_changed(words[i], current_str)) {
                visited[i] = true;
                q.push(make_pair(current_count + 1, words[i]));
            }
        }
    }
    
    return answer;
}