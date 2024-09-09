#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int arr[1005];
    int cache[1005];
    int N;
    int ans = -1;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cache[i] = arr[i];
    }

    ans = arr[0];

    for(int i = 0; i < N; i++){
        int standard_number = arr[i];
        for(int j = i + 1; j < N; j++){
            if(standard_number < arr[j]){
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