#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
    // int cache[5005][5005] = {0};
    vector<int> cache[5005];
    int N, x, y;
    long long ans = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x >> y;
        cache[y].push_back(x);
    }

    for(int i = 1; i <= N; i++){
        sort(cache[i].begin(), cache[i].end());
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < cache[i].size(); j++){
            // cout << cache[i][j] << ' ';
            if(j == 0){
                ans += cache[i][j + 1] - cache[i][j];
            }else if(j == cache[i].size() - 1){
                ans += cache[i][j] - cache[i][j - 1];
            }else{
                ans += min(
                    abs(cache[i][j] - cache[i][j - 1]), 
                    abs(cache[i][j] - cache[i][j + 1])
                );
            }
            // cout << ans << endl;
        }

        // cout << endl;
    }

    cout << ans;

    return 0;



}