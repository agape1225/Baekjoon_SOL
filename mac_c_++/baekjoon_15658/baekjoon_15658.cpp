#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
int N;
int ops[4] = {0};
int ans_min = 1000000000;
int ans_max = -1000000000;

int get_num(int index, int num1, int num2){
    if(index == 0){
        return num1 + num2;
    }else if(index == 1){
        return num1 - num2;
    }else if(index == 2){
        return num1 * num2;
    }else if(index == 3){
        return num1 / num2;
    }
    return -1;
}

void get_ans(int count, int result){
    if(count > N - 2){
        // cout << "end";
        ans_min = min(ans_min, result);
        ans_max = max(ans_max, result);
    }else{
        for(int i = 0; i < 4; i++){
            if(ops[i] > 0){
                if(i == 3 && nums[count + 1] == 0)
                    continue;
                if(count == 0){
                    int tmp = get_num(i, nums[count], nums[count + 1]);
                    ops[i]--;
                    get_ans(count + 1, tmp );
                    ops[i]++;
                }else{
                    int tmp = get_num(i, result, nums[count + 1]);
                    ops[i]--;
                    get_ans(count + 1, tmp );
                    ops[i]++;
                }
                
                
            }
        }
    }
}

int main(void){
    cin >> N;

    int tmp;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }

    for(int i = 0; i < 4; i++){
        cin >> ops[i];
    }

    get_ans(0, 0);
    // cout << -1 / 1;

    cout << ans_max << endl << ans_min;

    return 0;
}