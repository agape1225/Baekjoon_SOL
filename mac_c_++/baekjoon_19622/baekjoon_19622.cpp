#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(void){
    vector<pair<pair<int, int> , int>> meetings;
    int cache[100005][2] = {0};

    int N;
    int start, end, people;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> start >> end >> people;

        meetings.push_back(
            make_pair(
                make_pair(start, end), people
            )
        );
    }

    //0은 선택
    //1은 선택하지 않음

    cache[0][1] = meetings[0].second;

    if(N > 1){
        cache[1][0] = meetings[1].second;
        cache[1][1] = meetings[0].second;
    }

    for(int i  = 2; i < N; i++){

        cache[i][0] = cache[i - 1][1] + meetings[i].second;
        cache[i][1] = max(cache[i - 1][1], cache[i - 1][0]);

    }

    cout << max(cache[N - 1][0], cache[N - 1][1]);

    return 0;
}