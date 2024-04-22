#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool is_char(char c){
    return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
}

vector<pair<int, int>> get_word_pos(string S){
    vector<pair<int,int>> words_pos;
    int start_index = 0;
    int end_index = 0;
    bool mid_of_word = false;
    bool is_tag = false;

    for(int i = 0; i < S.size(); i++){

        if(is_char(S[i]) && !is_tag){  
                if(!mid_of_word){
                start_index = i;
                mid_of_word = true;
            }
        }

        if(S[i] == '<'){
            if(mid_of_word){
                is_tag = true;
                mid_of_word = false;
                end_index = i - 1;
                words_pos.push_back(make_pair(start_index, end_index));

            end_index = 0;
            start_index = 0;
            }else
                is_tag = true;
        }

        if(S[i] == '>'){
            is_tag = false;
        }

        
        if((i == (S.size() - 1) || S[i] == ' ') && mid_of_word){
            mid_of_word = false;
            if(i == (S.size() - 1))
                end_index = i;
            else
                end_index = i - 1;
            words_pos.push_back(make_pair(start_index, end_index));

            end_index = 0;
            start_index = 0;
        }
    }
    return words_pos;
}

string get_ans(vector<pair<int, int>> words_pos, string S){
    string ans = S;

    for(auto it : words_pos){
        int start_index = it.first;
        int end_index = it.second;

        for(int i = 0; i < (end_index - start_index + 1); i++){
            ans[start_index + i] = S[end_index - i];
        }
    }

    return ans;

}

int main(void){

    string S;
    string ans;
    vector<pair<int, int>> words_pos;
    getline(cin, S);

    words_pos = get_word_pos(S);
    ans = get_ans(words_pos, S);

    std::cout << ans;

    return 0;

}