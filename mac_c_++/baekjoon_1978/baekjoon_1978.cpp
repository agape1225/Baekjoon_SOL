/*
1. 입력
2. 소수인지 아닌지 판단한다
3. 소수면 카운트
4. 정답 출력
*/
#include <iostream>
#include <algorithm>

using namespace std;

// 소수인지 아닌지를 판별한다.
bool is_ans(int tmp){
    int count = 0;
    for(int i = 1; i <= tmp; i++) {
        if(tmp % i == 0){
            count++;
        }
    }

    return count == 2;
}

int main(void) {
    int N;
    int count = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;

        if(is_ans(tmp)) {
            count++;
        }
    }

    cout << count;

    return 0;
}