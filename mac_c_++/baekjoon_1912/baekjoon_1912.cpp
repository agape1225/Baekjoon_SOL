#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int arr[100005] = {0};
    int cache[100005] = {0};
    int N;
    int ans;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cache[0] = arr[0];

    for(int i = 1; i < N; i++){
        cache[i] = max(arr[i], arr[i] + cache[i - 1]);
    }

    ans = cache[0];

    for(int i = 0; i < N; i++){
        ans = max(ans, cache[i]);
    }

    cout << ans;

    return 0;
    
}