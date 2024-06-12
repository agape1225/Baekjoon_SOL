#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_ans(string old_sign, string conv_name){
    
    for(int i = 0; i < old_sign.size(); i++){
        if(old_sign[i] == conv_name[0]){

            int start_pos = i;
            int max_diff = old_sign.size();

            for(int diff = 1; diff < max_diff; diff++){

                int index = start_pos;
                string new_str = "";

                for(int j = 0; j < conv_name.size(); j++){
                    if(index < old_sign.size()){
                        new_str += old_sign[index];
                        index += diff;
                    }else{
                        break;
                    }
                }
                if(new_str == conv_name)
                    return true;
            }

        }
    }

    return false;
}

int main(void){
    int N;
    string conv_name = "";
    int count = 0;
    cin >> N >> conv_name;

    for(int n = 0; n < N; n++){
        string old_sign;
        cin >> old_sign;

        if(is_ans(old_sign, conv_name)){
            count++;
        }
    }

    cout << count;
}