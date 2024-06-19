#include <iostream>
using namespace std;

int get_ans(long long k){
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;
    if(k % 2 == 1)
        return 1 - get_ans(k / 2);
    else
        return get_ans(k / 2);
}

int main(void){
    long long k;
    cin >> k;

    cout << get_ans(k - 1);

    return 0;
    
}