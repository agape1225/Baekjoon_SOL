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
        cache[i] = arr[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[j] > arr[i]){
                cache[j] = max(cache[j], cache[i] + arr[j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        ans = max(ans, cache[i]);
    }
    
    cout << ans;
    
    return 0;
    
}
