#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if(n % i == 0){
            count++;
        }
    }

    if(count == 2){
        return true;
    }else {
        return false;
    }
    
}

int main(void) {
    int N, tmp;
    int ans = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
       if(is_prime(tmp)) {
            ans++;        
       }
    }

    cout << ans;

    return 0;
}