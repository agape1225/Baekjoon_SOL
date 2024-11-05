#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector<pair<pair<int, int> ,int>> timeline;
long long dp[100005][2];
int N;

int main(void){
    
    int start, end, people;
    

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> start >> end >> people;
        timeline.push_back(make_pair(make_pair(start, end), people));
    }

    dp[0][1] = timeline[0].second;
    
    dp[1][0] = timeline[0].second;
    dp[1][1] = timeline[1].second;

    for(int i = 2; i < N; i++){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + timeline[i].second;
    }

    cout << max(dp[N - 1][0], dp[N - 1][1]);

    return 0;
}   