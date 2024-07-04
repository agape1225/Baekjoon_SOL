#include <iostream>

using namespace std;

int main(void){
    int N;
    int arr[10001];
    int cache[10001] = {0};
    int ans = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cache[i] = 1;
    }

    // cache[0] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j])
                cache[i] = max(cache[i], cache[j] + 1);
        }
        ans = max(ans, cache[i]);
    }

    cout << ans;

    return 0;
    
}