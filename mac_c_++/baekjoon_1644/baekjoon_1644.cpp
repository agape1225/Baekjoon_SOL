#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int prime_number_tmp[4000005] = {0};
vector<int> prime_number;
// int N;

void init_prime_number(int N) {
    
    for(int i = 2; i <= N; i++) {
        prime_number_tmp[i] = i;
    }

    for(int i = 2; i <= sqrt(N); i++) {

        if(prime_number_tmp[i] == 0) {
            continue;
        }

        for(int j =  i * 2; j <= N; j += i) {
            prime_number_tmp[j] = 0;
        }
    }

    //vector에 소수 추가
    for(int i = 2; i <= N; i++) {
        if(prime_number_tmp[i] == i) {
            prime_number.push_back(i);
        }
    }
}

int main(void) {

    int ans = 0;
    int N;

    cin >> N;

    //init prime number
    init_prime_number(N);

    int left = 0;
    int right = 1;

    int tmp = 2;

    while(left < prime_number.size() && right <= prime_number.size()) {
        if(tmp == N) {
            ans++;
            if(right < prime_number.size()){
                tmp += prime_number[right];
                right++;
            }else {
                break;
            }
            
        }

        if(tmp < N) {

            if(right < prime_number.size()) {
                tmp += prime_number[right];
                right++;
            }else {
                break;
            }

        }else if(tmp > N) {
            tmp -= prime_number[left];
            left++;
        }
    }

    cout << ans;

    return 0;

}