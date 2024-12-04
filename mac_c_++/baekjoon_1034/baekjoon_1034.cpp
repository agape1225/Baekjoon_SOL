#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    int N, M, K;
    string lamps[55];
    int ans = 0;
    
    map<string, int> m;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> lamps[i];
        // for(int j = 0; j < M; j++){
        //     cin >> lamps[i][j];
        // }
    }

    cin >> K;

    for(int i = 0; i < N; i++){

        // cout << i << endl;

        //count
        int count = 0;
        string pattern = "";
        for(int j = 0; j < M; j++){
            if(lamps[i][j] == '0'){
                count++;
                pattern+= to_string(j);
            }
        }

        if(count > K || (count % 2 != K % 2)){
            continue;
        }

        auto node = m.find(pattern);

        if(node == m.end()){
            m.insert(make_pair(pattern, 1));
        }else{
            node->second++;
            // m[pattern]++;
        }
    }

    for(auto it : m){
        ans = max(ans, it.second);
    }


    cout << ans;

    return 0;

}