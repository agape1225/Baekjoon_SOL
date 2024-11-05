#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, K, M;
    int kimbob[1000005];

    cin >> N >> K >> M;

    for(int i = 0; i < N; i++){

        //꼬다리 길이 먼저 손질
        cin >> kimbob[i];

        if(kimbob[i] >= 2 * K){
            kimbob[i] = kimbob[i] - 2 * K;
        }else if(kimbob[i] > K){
            kimbob[i] = kimbob[i] - K;
        }else {
            kimbob[i] = 0;
        }
    }

    

    int left, right, ans;
    left = 1;
    right = 1000000000;
    ans = -1;


    while(left <= right){
        int mid = (left + right) / 2;
        int count = 0;
        for(int i = 0; i < N; i++){
            count += kimbob[i] / mid;
        }

        if(count >= M){
            ans = max(ans, mid);
            left = mid + 1;
        }else{
            right = mid - 1;
        }

    }

    cout << ans;

    return 0;

}