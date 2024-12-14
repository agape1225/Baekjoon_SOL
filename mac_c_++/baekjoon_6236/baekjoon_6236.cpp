#include <iostream>
#include <algorithm>

using namespace std;


int cache[100005];

int main(void){
    int N, M;
    int left, right;
    int ans = -1;

    left = 0;
    right = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> cache[i];
        // cout << cache[i] << endl;
        left = max(cache[i], left);
        right += cache[i];

        // cout << left << ' ' << right << endl;
    }

    ans = right;

    while (left <= right)
    {
        
        int mid = (left + right) / 2;
        int tmp = mid;
        int count = 1;

        for(int i = 0; i < N; i++){
            if(tmp >= cache[i]){
                tmp -= cache[i];
            }else{
                count++;
                tmp = mid;
                tmp -= cache[i];
            }
        }

        if(count <= M){
            ans = right;
            right = mid - 1;
            // ans = right;
        }else{
            left = mid + 1;
        }
    }
    
    cout << ans;

    return 0;

}