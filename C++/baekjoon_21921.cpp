// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    int N;
    int X;
    long long sum = 0;
    long long ans = 0;
    int count = 0;
    int arr[250005];
        
    cin >> N >> X;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i < X){
            sum += arr[i];
        }
        
    }
    
    int start = 0;
    int end = X - 1;
    
    while(true){
        
        // cout << ans << ' ' << sum << endl;
        
        // 판단하기
        if(ans < sum){
            ans = sum;
            count = 1;
        }else if(ans == sum){
            count++;
        }
        
        //break
        if(end + 1 >= N){
            break;
        }
        
        //sum 초기화
        sum -= arr[start++];
        sum += arr[++end];
        
    }
    
    if(ans == 0){
        cout << "SAD";
    }else{
        cout << ans << '\n' << count;
    }

    return 0;
}
