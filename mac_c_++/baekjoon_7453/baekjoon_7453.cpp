#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    long long input = 0;
    long long ans = 0;

    vector<long long> tmp[4];
    vector<long long> arr1;
    vector<long long> arr2;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> input;
            tmp[j].push_back(input);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr1.push_back(tmp[0][i] + tmp[1][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr2.push_back(tmp[2][i] + tmp[3][j]);
        }
    }

    sort(arr2.begin(), arr2.end());

    for(int i = 0; i < n * n; i++){
        long long num = arr1[i];
        long long target_num = num * -1;

        auto lower = lower_bound(arr2.begin(), arr2.end(), target_num);
        auto upper = upper_bound(arr2.begin(), arr2.end(), target_num);

        ans += upper - lower;

    }

    cout << ans;

    return 0;

    
}