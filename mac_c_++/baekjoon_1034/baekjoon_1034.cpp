#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(void){
    // int lamps[55][55];
    vector<string> lamps;
    int counts[55] = {0};
    int N, M, K;
    map<string, int> cache;
    int ans = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        lamps.push_back(tmp);
    }

    cin >> K;

    for(auto row: lamps){
        int count = 0;
        // cout << row << endl;
        for(auto it : row){
            if(it == '0'){
                count++;
            }
        }

        if(count > K || (count % 2) != K % 2){
            continue;
        }

        if(cache.find(row) == cache.end()){
            cache.insert(make_pair(row, 1));
        }else{
            // cout << row << endl;
            cache[row]++;
            // cout << cache.at(row) << endl;
        }
    }

    for(auto it : cache){
        // cout << it.first << ' ' << it.second << endl;
        ans = max(ans, it.second);
    }

    cout << ans;

    return 0;
}