#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    int cache[100005];
    int arr[100005];
    int ans = -1;

    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cache[0] = arr[0];
    ans = cache[0];

    for(int i = 1; i < n; i++){
        cache[i] = max(cache[i - 1] + arr[i], arr[i]);
        ans = max(ans, cache[i]);
    }

    cout << ans;

    return 0;

}