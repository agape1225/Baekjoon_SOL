#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    int N, tmp, prev;
    int rocks[5005];
    int cache[5005] = {0};

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> rocks[i];

    }

    
    // 시작부터 오는 애랑 바로 뒤에서 오는애 -> 바로 뒤에서 오는애는 최단거리라는 가정 하에
    for(int i = 2; i <= N; i++){
        //prev
        int prev_dis =  1 + abs(rocks[i - 1] - rocks[i] );
        int first_dis = (i - 1) * (1 + abs(rocks[1] - rocks[i]));
        cout << prev_dis << ' ' << first_dis << endl;
        cache[i] = min(prev_dis, first_dis);
        cout << cache[i] << endl;
    }

    cout << cache[N - 1];
    return 0;
}