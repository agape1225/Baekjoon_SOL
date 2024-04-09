#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string s;
    string t;
    while (cin >> s >> t){
        int index = 0;
        for(int i = 0; i < t.size(); i++){
            if(index == s.size())
                break;
            if(t[i] == s[index]){
                index++;
            }
        }
        
        if(index == s.size()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
