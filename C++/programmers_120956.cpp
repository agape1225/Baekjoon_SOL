#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> ans;

bool visited[4] = {0};
int dir[4] = {0};
vector<string> babbles = {"aya", "ye", "woo", "ma"};

void set_single_combination(int index, int max){
    if(index == max){
        string word = "";
        for(int i = 0; i < max; i++){
            word += babbles[dir[i]];
        }
        ans.push_back(word);
    }else{
        for(int i = 0; i < babbles.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                dir[index] = i;
                set_single_combination(index + 1, max);
                visited[i] = false;
            }
        }
    }
}

void set_combination(int max){
    
    for(int i = 0; i < babbles.size(); i++){
        dir[0] = i;
        visited[i] = true;
        set_single_combination(1, max);
        visited[i] = false;
    }
    
}

void create_combination(){
    for(int i = 0; i < babbles.size(); i++){
        set_combination(i + 1);
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    create_combination();
    
    for(auto it : babbling){
        if(find(ans.begin(), ans.end(), it) != ans.end()){
            // cout << it << endl;
            answer++;
        }
    }
    return answer;
}
