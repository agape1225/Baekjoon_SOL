#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<int> two_way_queue;
    int count = 0;
    
    for(auto commands: operations) {
        //두개로 나눠야징
        pair<char, int> pre = get_pre(commands);
        
        if(pre.first == 'I') {
            count++;
            two_way_queue.push_back(pre.second);
            sort(two_way_queue.begin(), two_way_queue.end());
        }else {
            if(count == 0) {
                continue;
            }
            count--;
            if(pre.second > 0) {
                // max_queue.pop();
                
                two_way_queue.erase(two_way_queue.begin() + two_way_queue.size() - 1);
                
            }else {
                two_way_queue.erase(two_way_queue.begin());
                
            }
        }
        
//         if(count == 0) {
//             while(!max_queue.empty()){
//                 max_queue.pop();
//             }
            
//             while(!min_queue.empty()) {
//                 min_queue.pop();
//             }
//         }
    }
    
    if(count > 0) {
        answer.push_back(*(two_way_queue.begin() + two_way_queue.size() - 1));
        answer.push_back(*two_way_queue.begin());
        
        
    }else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}