#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, M;
    int budget[10005];
    int ans = 1000000000;
    int sum = 0;
    int max_budget = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> budget[i];
        sum += budget[i];
        max_budget = max(max_budget, budget[i]);
    }

    cin >> M;

    int left, right;
    left = 1;
    right = 1000000000;

    if(sum <= M){
        cout << max_budget;
        return 0;
    }
    

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long total_budget = 0;
        for(int i = 0; i < N; i++){
            int current_budget = budget[i];

            if(current_budget <= mid){
                total_budget += current_budget;
            }else{
                total_budget += mid;
            }
        }

        // cout << left << ' ' << right << ' ' << mid << ' ' << total_budget << endl;

        if(total_budget > M){
            right = mid - 1;
        }else{
            left = mid + 1;
            ans = mid;
            // ans = min(mid, ans);
        }

    }
    
    cout << ans;

    return 0;


}