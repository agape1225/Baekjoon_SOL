#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//cache[i] = 2^i 까지의 1의 갯수의 합
long long cache[55] = {0};

long long get_one_count(long long x) {
    // int i = 55;
    long long count = x & 1;

    for(long long i = 54; i > 0; i--) {
        if(x & (1LL << i)) {
            count += cache[i - 1] + (x - (1LL << i) + 1);
            // count += x - (1LL << i) + 1;
            x -= 1LL << i;

        }
    }

    return count;
}

int main(void) {
    long long A, B;
    cin >> A >> B;
    
    cache[0] = 1;
    for(long long i = 1; i < 55; i++) {
        cache[i] = cache[i - 1] * 2 + (1LL << i); 
    }

    cout << get_one_count(B) - get_one_count(A - 1);

    return 0;
}