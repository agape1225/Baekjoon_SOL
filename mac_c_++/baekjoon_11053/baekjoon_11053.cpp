#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int arr[1005];
    int cache[1005] = {0};
    int N;
    int ans = -1;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cache[i] = 1;
    }

   

    for(int i = 0; i < N; i++){
        
        for(int j = i + 1; j < N; j++){
            if(arr[i] < arr[j]){
                cache[j] = max(cache[j], cache[i] + 1);
            }
        }

        
    }

    for(int i = 0; i < N; i++){
ans = max(ans, cache[i]);
    }

    

    cout << cache[N - 1];

    return 0;
}