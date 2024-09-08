#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int arr[100005];
    int cache[100005];
    int n;
    int ans = -1;

    cin  >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cache[0] = arr[0];
    ans = arr[0];

    for(int i = 1; i < n; i++){
        cache[i] = max(arr[i], arr[i] + cache[i - 1]);
    }

    for(int i = 0; i < n; i++){
        ans = max(ans, cache[i]);
    }
    
    cout << ans;

    return 0;

}