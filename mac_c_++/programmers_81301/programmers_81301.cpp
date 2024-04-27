#include <string>
#include <vector>
#include <iostream>

using namespace std;


                        
int get_num(string str){

    vector<string> cache = {"zero","one","two","three","four",
                            "five","six","seven","eight","nine"};
    
    for(int i = 0; i < cache.size(); i++){
        if(cache[i] == str)
            return i;
    }
    return -1;
}

vector<string> get_str_list(string str){
    string tmp = "";
    vector<string> ans;
    
    for(auto it : str){
        // cout << it << endl;
        if('0' <= it && it <= '9' ){
            string tmp = "";
            tmp += it;
            // cout << tmp << endl << endl;
            ans.push_back(tmp);
        }else{
            tmp += it;
            if(get_num(tmp) != -1){
                ans.push_back(tmp);
                tmp = "";
            }
        }
    }
    if(tmp != "")
        ans.push_back(tmp);
    
    return ans;
}



int solution(string s) {
    int answer = 0;
    //list로 만든다.
    vector<string> str_list = get_str_list(s);
    for(auto it : str_list){
        cout << it << endl;
        if("0" <= it && it <= "9" ){
            answer = (answer * 10) + stoi(it); 
        }else{
            int num = get_num(it);
            answer = (answer * 10) + num;
        }
    }
    return answer;
}

int main(void){
    cout << solution("one4seveneight");
}