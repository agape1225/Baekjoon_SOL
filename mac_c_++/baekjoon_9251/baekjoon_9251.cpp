#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int cache[1005][1005] = {0};

    string str1, str2;
    string s_str, b_str;
    int ans = 0;

    cin >> str1 >> str2;

    if(str1.size() < str2.size()){
        s_str = str1;
        b_str = str2;
    }else {
        b_str = str1;
        s_str = str2;
    }
    for(int i = 1; i <= s_str.size(); i++){
        for(int j = 1; j <= b_str.size(); j++){
            if(s_str[i - 1] == b_str[j - 1]){
                cache[i][j] = max(cache[i - 1][j - 1] + 1, cache[i - 1][j] );
            }else{
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1] );
                
            }
        }
            
    }

    cout << cache[s_str.size()][b_str.size()];

    return 0;
    
}