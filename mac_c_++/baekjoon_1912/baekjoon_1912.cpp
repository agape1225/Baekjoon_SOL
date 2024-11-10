#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int arr[100005] = {0};
    int cache[100005] = {0};
    int ans = -1;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cache[0] = arr[0];
    ans = arr[0];

    for(int i = 1; i < N; i++){
        cache[i] = max(arr[i], cache[i - 1] + arr[i]);
    }

    for(int i = 1; i < N; i++){
        ans = max(ans, cache[i]);
    }

    cout << ans;

    return 0;

}