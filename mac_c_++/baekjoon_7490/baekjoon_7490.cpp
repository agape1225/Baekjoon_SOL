#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_zero(string exp){
    // erase blank
    string new_exp = "";

    for(auto it : exp) {
        if(it != ' '){
            new_exp += it;
        }
    }

    //create arr
    vector<int> nums;
    vector<char> sign;

    string tmp = "";
    for(int i = 0; i < new_exp.size(); i++) {
        if('0' <= new_exp[i] && new_exp[i] <= '9'){
            tmp += new_exp[i];
        }else {
            if(tmp != ""){
                nums.push_back(stoi(tmp));
                tmp = "";

                sign.push_back(new_exp[i]);
            }
        }
    }

    if(tmp != ""){
        nums.push_back(stoi(tmp));
    }

    //calculate
    int sum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(sign[i - 1] == '+'){
            sum += nums[i];
        }else{
            sum -= nums[i];
        }
    }

    return sum == 0;

}

void get_ans(int current_num, int max, string history){

    if(current_num == max){
        // print ans with history
        history += to_string(current_num);
        if(is_zero(history)){
            cout << history << '\n';
        }
    }else{
        //blank
        get_ans(current_num + 1, max, history + to_string(current_num) + " ");
        
        //+
        get_ans(current_num + 1, max, history + to_string(current_num) + "+");
        
        //-
        get_ans(current_num + 1, max, history + to_string(current_num) + "-");
        
    }

}

int main(void) {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N;
        cin >> N;
        get_ans(1, N, "");
        cout << "\n";
    }
}