#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(void){
    int N, tmp, prev;
    vector<int> rocks;
    vector<int> cache;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        rocks.push_back(tmp);
        cache.push_back(0);
    }

    
    // 시작부터 오는 애랑 바로 뒤에서 오는애 -> 바로 뒤에서 오는애는 최단거리라는 가정 하에
    for(int i = 1; i < N; i++){
        //prev
        int prev_dis = cache[i - 1] + 1 + abs(rocks[i - 1] - rocks[i] );
        int first_dis = (i) * (1 + abs(rocks[0] - rocks[i]));
        cout << prev_dis << ' ' << first_dis << endl;
        cache[i] = min(prev_dis, first_dis);
    }

    cout << cache[N - 1];
    return 0;
}