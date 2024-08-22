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
        for(int j = i; j < N; j++){
            if(arr[i] < arr[j]){
                cache[j] = max(cache[j], cache[i] + arr[j]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        ans = max(ans, cache[i]);
    }

    cout << ans;
    
    
    return 0;
}
