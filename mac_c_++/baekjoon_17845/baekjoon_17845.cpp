#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


    int cache[1005][10005] = {0};
    vector<pair<int, int>> info;

//배낭 문제임요
int main(void){

    int N, K;
    int I, T;

    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> I >> T;

        info.push_back(make_pair(I, T));
    }

    for(int i = 1; i <= K; i++){
        int weight = info[i - 1].first;
        int time = info[i - 1].second;
        for(int j = 1; j <= N; j++){
            if(j - time >= 0){
                cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - time] + weight);
            }else{
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }

    cout << cache[K][N];

    return 0;

}