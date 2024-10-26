#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int money[100005] = {0};
    int N, M;
    int left = 1;
    int right = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++){

        cin >> money[i];
        right += money[i];
        // left = max(left, money[i]);
    }

    int  ans = right;

    while(left <= right){
        //보다 작으면 됨 최소가 !!! M

            // cout << left << ' ' << right << endl;

        int count = 1;
        int K = (left + right) / 2;
        int curr_money = K;
        bool is_over = false;

        for(int i = 0; i < N; i++){

            if(K < money[i]){
                is_over = true;
                break;
            }
                
            if(curr_money >= money[i]){
                curr_money -= money[i];
            }else{
                curr_money = K;
                curr_money -= money[i];
                count++;
            }
        }

        if(is_over || count > M){
            left = K + 1;
        }else{
            right = K - 1;
            ans = min(K, ans);
        }
    }

    cout << ans << endl;

    return 0;
}