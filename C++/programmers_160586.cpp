#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int get_count(char target, string key){
    for(int i = 0; i < key.size(); i++){
        if(key[i] == target){
            return i + 1;
        }
    }
    return -1;
}

int get_min_count(char target, vector<string> keymap){
    int ans = 1000;
    for(auto key : keymap){
        int tmp = get_count(target, key);
        if(tmp != -1)
            ans = min(ans, tmp);   
    }
    
    if(ans == 1000)
        return -1;
    return ans;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(auto target : targets){
        int ans = 0;
        bool ans_flag = false;
        for(auto it : target){
            int tmp = get_min_count(it, keymap);
            if(tmp == -1){
                answer.push_back(-1);
                ans_flag = true;
                break;
            }else
                ans += tmp;
        }
        if(!ans_flag)
            answer.push_back(ans);   
    }
    
    return answer;
}
