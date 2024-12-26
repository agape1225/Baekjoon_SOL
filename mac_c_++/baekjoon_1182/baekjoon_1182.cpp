#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[25];
int ans = 0;

void get_ans(int index, int sum, int count){
    // cout << sum << endl;
    if(index >= N){
        if(sum == S && count > 0){
            // cout << sum;
            ans++;
        }
    }else{
        get_ans(index + 1, sum + arr[index], count  + 1);
        get_ans(index + 1, sum , count);
    }
}

int main(void) {    


    cin >> N >> S;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    get_ans(0, 0, 0);

    cout << ans;

    return 0;
}