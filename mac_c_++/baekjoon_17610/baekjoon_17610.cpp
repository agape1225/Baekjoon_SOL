//broute force
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, tmp;
int sum = 0;
int ans = 0;
vector<int> nums;
int visited[13] = {0};
// int cache[5000000] = {0};
vector<bool> cache;

void get_ans(int index, int target_num){

    // cout << index << endl;

    if(index == K){
        if(target_num >= 0){
            // cout<< target_num << endl;
            cache[target_num] = true;
            

        }
        return;
            
    }
    // cout << index << endl;
    get_ans(index + 1, target_num);
    get_ans(index + 1, target_num + nums[index]);
    get_ans(index + 1, target_num - nums[index]);
}

int main(void){


    // nums.push_back(0);

    cin >> K;

    for(int i = 0; i < K; i++){
        cin >> tmp;
        nums.push_back(tmp);
        sum += tmp;
    }

    cache.resize(sum + 1, false);

    // sort(nums.begin(), nums.end());

    get_ans(0, 0);

    for(int i = 1; i <= sum; i++){
        // get_ans(0, i, 0, i);
        if(!cache[i]){
            ans++;
        }
    }

    cout << ans;

    return 0;
}