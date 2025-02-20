#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    int arr[1005];
    int cache[1005] = {0};
    int ans = -1;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cache[i] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                cache[j] = max(cache[j], cache[i] + 1);
                // cout << i << ' ' << j << ' ' << cache[i] << endl;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        ans = max(ans, cache[i]);
    }
    
    cout << ans;
    
    return 0;
    
}
