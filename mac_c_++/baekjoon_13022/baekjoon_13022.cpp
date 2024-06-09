#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_words(string s){
    vector<string> words;
    string tmp = "";
    bool is_begin = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'w'){
            if(is_begin){
                tmp += s[i];
            }else{
                words.push_back(tmp);
                tmp = "" ;
                tmp += s[i];
                is_begin = true;
            }
        }else{
            if(is_begin){
                is_begin = false;
            }
            tmp += s[i];
        }
    }
    words.push_back(tmp);
    return words;
}

int get_N(string s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'w'){
            count++;
        }else
            return count;
    }
    return count;
}

string get_comp_base_str(int N){
    vector<string> str_order = {"w", "o", "l", "f"};
    string comp_str = "";

    for(auto it : str_order){
        string tmp = "";
        for(int i = 0; i < N; i++){
            tmp += it;
        }
        comp_str += tmp;
    }
    return comp_str;
}

int main(void){
    string s;
    cin >> s;

    vector<string> words = get_words(s);

    for(auto it : words){
        // cout << it << endl;
        int N = get_N(it);
        string comp_base_str = get_comp_base_str(N);

        if(it != comp_base_str){
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}