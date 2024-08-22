#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int cache[1005] = {0};
    int arr[1005] = {0};
    int N;
    int ans = -1;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cache[i] = arr[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                cache[i] = max(cache[i], cache[j] + arr[i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        ans = max(ans, cache[i]);
    }

    cout << ans;
    
    
    return 0;
}
