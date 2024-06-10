#include <iostream>
#include <string>

using namespace std;

int diff = 'a' - 'A';

bool is_c_lang(string var){

    int count_bar = 0;

    //모든 문자가 소문자여야한다.
    for(auto it : var){

        if(!(it == '_' || ('a' <= it && it <= 'z'))){
            return false;
        }

        if(it == '_')
            count_bar++;
        
        else if(('a' <= it && it <= 'z'))
            count_bar = 0;

        if(count_bar > 1)
            return false;


    }

    if(var[var.size() - 1] == '_' || var[0] == '_')
        return false;

    return true;
}

bool is_java_lang(string var){

    if(('A' <= var[0] && var[0] <= 'Z') )
        return false;

    for(auto it : var){

        if(!(('A' <= it && it <= 'Z') || ('a' <= it && it <= 'z'))){
            return false;
        }
    }
    return true;
}

string get_c_to_java(string var){
    string java_lang = "";
    for(int i = 0; i < var.size(); i++){
        char c = var[i];

        if(c == '_'){
            i++;
            c = var[i];
            java_lang += (c - diff);
        }else{
            java_lang += c;
        }
    }
    return java_lang;
}

string get_java_to_c(string var){
    string c_lang = "";

    for(int i = 0; i < var.size(); i++){
        char c = var[i];

        if(('A' <= c && c <= 'Z')){
            string tmp = "";
            tmp += c + diff;
            c_lang += "_" + tmp;
        }else{
            c_lang += c;
        }

        // cout << c_lang << endl;
    }

    // cout << c_lang << endl;

    return c_lang;

}

int main(void){
    string var;

    string ans;

    cin >> var;

    if(is_c_lang(var)){

        ans =  get_c_to_java(var);

    }else if(is_java_lang(var)){
        ans =  get_java_to_c(var);
    }else{
        ans =  "Error!";
    }

    cout << ans << endl;

    return 0;

}