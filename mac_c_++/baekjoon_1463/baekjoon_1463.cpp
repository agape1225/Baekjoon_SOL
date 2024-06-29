#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int cache[1000001];
    cin >> N;

    cache[1] = 0;

    for(int i = 2; i <= N; i++){
        int num1, num2, num3;
        num1 = cache[i - 1];
        num2 = 1000001;
        num3 = 1000001;
        if(i / 2 >= 1 && i % 2 == 0){
            num2 = cache[i / 2];
        }else if(i / 3 >= 1 && i % 3 == 0){
            num3 = cache[i / 3];
        }

        cache[i] = min(num1, min(num2, num3)) + 1;
    }

    cout << cache[N];

    return 0;
}