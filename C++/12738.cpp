// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    vector<int> arr;
    vector<int> ans;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(auto it : arr) {
        if(ans.size() == 0) {
            ans.push_back(it);
        }else {
            
            if(ans[ans.size() - 1] < it) {
                ans.push_back(it);
            }
            
            // auto next = lower_bound(ans.begin(), ans.end(), it);
            int index = lower_bound(ans.begin(), ans.end(), it) - ans.begin();
            ans[index] = it;
            
            
            
            // if(index == 0) {
            //     ans[index] = it;
            // }else {
            //     if(ans[index] > it) {
            //         ans[index - 1] = it;
            //     }else {
            //         ans[index] = it;
            //     }
            // }
            
            // if(*next > it) {
            //     next
            // }
            
            // *next = it;
        }
    }
    
    cout << ans.size();
    return 0;
}
