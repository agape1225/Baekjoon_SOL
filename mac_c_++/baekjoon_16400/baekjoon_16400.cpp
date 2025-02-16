#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime[40005] = {0};

void set_prime(int N) {
    int tmp[40005] = {0};

    for(int i = 2; i <= N; i++) {
        tmp[i] = i;
    }
    
    for (int i = 2; i <= sqrt(N); i++) {
        if (tmp[i] == 0){
            continue;
        }
        
        for (int j = i * i; j <= N; j += i){
            tmp[j] = 0;
        }
        
    }

    for (int i = 2; i <= N; i++){
        if (tmp[i] != 0){
            is_prime[i] = true;
        }
    }
}

int main(void) {
    int N;
    int cache[40005] = {0};

    cin >> N;

    //40005까지의 소수를 전부 구한다.
    set_prime(N);

    //dp로 정답 구하기
    //n ^ 2

    cache[0] = 1;

    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i; j <= N; j++){
                cache[j] = (cache[j] + cache[j - i]) % 123456789;
            }
        }
    }

    cout << cache[N];


    return 0;
}