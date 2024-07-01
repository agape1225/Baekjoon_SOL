#include <iostream>

using namespace std;

int main(void){
    int N, M;
    int nums[100005];
    int cache[100005] = {0};
    int start, end;

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    //creat cache
    cache[1] = nums[1];

    for(int i = 2; i <= N; i++){
        cache[i] = nums[i] + cache[i - 1];
    }

    // for(int i = 0; i <= N; i++){
    //     cout << cache[i] << ' ';
    // }

    for(int i = 0; i < M; i++){
        cin >> start >> end;
        cout << cache[end] - cache[start - 1] << '\n';
    }

    return 0;
}