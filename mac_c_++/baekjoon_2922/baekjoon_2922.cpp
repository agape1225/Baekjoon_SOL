#include <iostream>
#include <algorithm>

using namespace std;

//자음: 0 (21개)
//모음: 1 (5개)

int ans = 0;

bool is_ans(string str){
    if(str.find('L') == string::npos){
        return false;
    }

    int count = 1;
    int token = str[0];
    for(int i = 1; i < str.size(); i++){
        if(token == str[i]){
            count++;
        }else if(token == 'L' && str[i] == '0'){
            count++;

        }else if(token == '0' && str[i] == 'L'){
            count++;

        }else{
            
            count = 1;
        }

        token = str[i];

        if(count >= 3){
            return false;
        }
    }

    return true;
}

void get_ans(string str, int count){
    //정답인지 판별 후 확인
    if(str.find('_') == string::npos){
        
        if(is_ans(str)){
            // cout << str << ' ' << count << endl;
            ans += count;
        }
    }else{
        int index = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '_'){
                index = i;
                break;
            }
        }

        str[index] = '0';
        get_ans(str, count * 20);
        str[index] = '1';
        get_ans(str, count * 5);
        str[index] = 'L';
        get_ans(str, count);
    }
}

int main(void){
    string str;
    string code_str;
    string k = "AEIOU";
    cin >> str;

    //str to code
    for(auto it : str){
        //자음 -> 0
        if(it == 'L' || it == '_'){
            code_str += it;
        }
        else if(k.find(it) == string::npos){
            code_str += '0';
        }
        //모음
        else{
            code_str += '1';
        }
    }

    // cout << code_str << endl;

    get_ans(code_str, 1);

    cout << ans;

    return 0;

}