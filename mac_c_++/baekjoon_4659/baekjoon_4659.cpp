#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_in(string str, string s){
    for(auto it : s){
        if(str.find(it) != string::npos)
            return true;
    }
    // cout << "zz";
    return false;
}

bool is_s(char c){
    string s = "aeiou";
    return s.find(c) != string::npos;
}

bool is_triple(string str){
    bool is_e = is_s(str[0]);
    int count = 1;

    for(int i = 1; i < str.size(); i++){
        bool current = is_s(str[i]);

        if(current == is_e){
            count++;
        }else{
            count = 1;
            is_e = current;
        }

        if(count == 3)
            return true;
    }
    return false;
}

bool is_double(string str){
    
    char prev = str[0];
    int count = 1;

    for(int i = 1; i < str.size(); i++){
        if(prev == str[i]){
            if(str[i] != 'e' && str[i] != 'o'){
                return true;
            }
        }else{
            prev = str[i];
        }
    }

    return false;

}

bool is_poss(string str){
    if(!is_in(str, "aeiou")){
        // cout << "is_poss";
        return false;
    }
    if(is_triple(str)){
        // cout << "is_triple";
        return false;
    }
    if(is_double(str)){
        // cout << "is_double";
        return false;
    }
    return true;
}

int main(void){
    string str;

    while(true){
        cin >> str;
        if(str == "end")
            break;

        if(is_poss(str)){
            cout << '<' << str << '>' << " is acceptable." << endl;
        }else
            cout << '<' << str << '>' << " is not acceptable." << endl;
    }

    return 0;
}