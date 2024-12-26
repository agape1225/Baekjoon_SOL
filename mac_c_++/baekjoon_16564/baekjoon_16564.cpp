    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    int main(void){
        int N, K;
        long long arr[1000005];
        long long left = 1;
        long long right = 0;
        long long max_num = 0;
        long long ans = -1;

        cin >> N >> K;

        for(int i = 0; i < N; i++){
            cin >> arr[i];
            max_num = max(max_num, arr[i]);
        }

        right = max_num + K;

        while(left <= right){
            long long mid = (left + right) / 2;
            long long tmp_k = K;

            for(int i = 0; i < N; i++){
                if(arr[i] < mid){
                    tmp_k -= mid - arr[i];
                }
            }

            if(tmp_k < 0){
                right = mid -1 ;
            }else{
                ans = mid;
                left = mid + 1;
            }
        }

        cout << ans;

        return 0;

    }