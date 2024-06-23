#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long long n, left, right;
    cin >> n;

    left = 0;
    right = sqrt(n);

    if(right * right < n){
        right++;
    }
    
    cout << right;

    return 0;
}