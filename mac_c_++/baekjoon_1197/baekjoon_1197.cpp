#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(void){

    bool cache[100005] = {0};

    // union find 배열 생성
    for(int i = 0; i <= 10; i++){
        cache[i] = i;
    }

    for(int i = 0; i <= 10; i++){
        cout << cache[i] << ' ';
    }
    cout << endl;
    
    return 0;
}