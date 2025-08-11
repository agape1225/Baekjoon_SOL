#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<char, int> get_pre(string commands) {
    char cmd1 = commands[0];
    string cmd2 = "";
    for(int i = 2; i < commands.size(); i++) {
        cmd2 += commands[i];
    }
    return make_pair(cmd1, stoi(cmd2));
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max_queue;
    priority_queue<int> min_queue;
    int count = 0;
    
    for(auto commands: operations) {
        //두개로 나눠야징
        pair<char, int> pre = get_pre(commands);
        
        if(pre.first == 'I') {
            count++;
            max_queue.push(pre.second);
            min_queue.push(-pre.second);
        }else {
            if(count == 0) {
                continue;
            }
            count--;
            if(pre.second > 0) {
                max_queue.pop();
            }else {
                min_queue.pop();
            }
        }
        
        if(count == 0) {
            while(!max_queue.empty()){
                max_queue.pop();
            }
            
            while(!min_queue.empty()) {
                min_queue.pop();
            }
        }
    }
    
    if(count > 0) {
        answer.push_back(max_queue.top());
        answer.push_back(-min_queue.top());
        
    }else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}