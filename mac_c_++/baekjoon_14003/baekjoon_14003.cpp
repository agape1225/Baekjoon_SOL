// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    vector<int> arr;
    vector<int> ans;
    int cache[1000000] = {0};

    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(int i = 0; i < N; i++) {
        int it = arr[i];
        if(ans.size() == 0) {
            ans.push_back(it);
        }else {
            
            if(ans[ans.size() - 1] < it) {
                ans.push_back(it);
                cache[i] = ans.size() - 1;
            }
            
            // auto next = lower_bound(ans.begin(), ans.end(), it);
            int index = lower_bound(ans.begin(), ans.end(), it) - ans.begin();
            ans[index] = it;
            cache[i] = index;

        }
    }
    
    cout << ans.size() << '\n';

    // for(int i = 0; i < N; i++) {
    //     cout << cache[i] << ' ';
    //  }
    //  cout << endl;

    // int index = ans.size() - 1;
    vector<int> ans_list;
    int index = ans.size() - 1;

    // cout << index;

    for(int i = N-1; i >= 0; i--) {
        if(cache[i] == index) {
            // cout << index << ' ';
            index--;
            ans_list.push_back(arr[i]);
        }
    }

    for(int i = ans_list.size() - 1; i >= 0; i--) {
        cout << ans_list[i] << ' ';
    }
    return 0;
}