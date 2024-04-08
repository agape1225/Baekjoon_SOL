/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_condition1(string str){
    string vowels = "aeiou";
    
    for(auto it : vowels){
        if(str.find(it) != string::npos){
            return true;
        }
    }
    return false;
}

//O(N)
bool check_condition2(string str){
    string vowels = "aeiou";
    int max_count = 1;
    bool prev_vowel = vowels.find(str[0]) == string::npos ? false : true;

    for(int index = 1; index < str.size(); index++){

        bool current_vowel = vowels.find(str[index]) == string::npos ? false : true;

        if(prev_vowel == current_vowel){
            max_count++;
        }else{
            max_count = 1;
            prev_vowel = current_vowel;
        }

        if(max_count > 2)
            return false;
        
    }
    return true;
}

bool check_condition3(string str){
    char prev_char = str[0];
    for(int index = 1; index < str.size(); index++){
        char current_char = str[index];

        if(current_char == prev_char){
            if(!(current_char == 'o' || current_char == 'e')){
                return false;
            }
        }
        prev_char = current_char;

    }
    return true;
}

int main(void){
    string input;

    while(true){
        cin >> input;
        if(input == "end"){
            break;
        }

        bool ans = false;

        cout << "<" << input << "> ";

        if(check_condition1(input) && check_condition2(input) && check_condition3(input)){
            cout << "is acceptable." << endl;
        }else{
            cout << "is not acceptable." << endl;
        }

    }

}