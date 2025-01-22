#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string str;
    stack<char> s;
    vector<string> v;
    long long sum = 0;
    int size = str.size()l

    cin >> str;

    for(int i = 0; i < size; i++) {
        string tmp(1, str[i]);
        v.push_back(tmp);
    }

    while (v.size > 1)
    {
        vector<string> new_arr;
        for(auto it : v) {
            if(it == "(" || it == "["){
                new_arr.push_back(it);
            }else if(it == ")"){
                while(true) {
                    if(new_arr.back() == '['){
                        cout << 0;
                        return 0;
                    }else if(new_arr.back() == '('){
                        new_arr.pop_back();
                        new_arr.push("2");
                    }else {
                        string tmp = new_arr.back();
                        new_arr.pop_back();
                        new_arr.push(stoi(tmp))
                    }
                }

            }else if(it == "]"){

            }else{
                
            }
        }
    }
    
    cout << v[0];

    return 0;




}