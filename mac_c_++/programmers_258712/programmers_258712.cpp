#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int get_index(vector<string> arr, string name){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == name)
            return i;
    }
}

pair<string, string> get_from_to(string str){
    string to = "";
    string from = "";
    bool flag = false;
    
    for(auto it : str){
        if(it == ' '){
            flag = true;
        }else {
            if(flag){
                to += it;
            }else{
                from += it;
            }
        }
    }
    return make_pair(from, to);
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //선물 지수
    int gift_rate[55] = {0};
    int gift_board[55][55] = {0};
    
    for(auto it : gifts){
        pair<string, string> tmp = get_from_to(it);
        int from_index = get_index(friends, tmp.first);
        int to_index = get_index(friends, tmp.second);
        
        gift_board[from_index][to_index]++;
        
        gift_rate[from_index]++;
        gift_rate[to_index]--;
    }
    
    for(int i = 0; i < friends.size(); i++){
        int tmp = 0;
        for(int j = 0; j < friends.size(); j++){
        
            if(i == j)
                continue;
            
            if(gift_board[i][j] > gift_board[j][i]){
                tmp++;
            }else if(gift_board[i][j] == gift_board[j][i]){
                if(gift_rate[i] > gift_rate[j]){
                    tmp++;
                }
            }   
        }
        answer = max(answer, tmp);
    }
    
    return answer;
}