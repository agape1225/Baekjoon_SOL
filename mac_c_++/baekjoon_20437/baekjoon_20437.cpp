#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int ans_min = 100000;
int ans_max = -1;

void get_ans(string W, int K){

    int cache[30] = {0};
    for(auto it : W ){
        cache[it - 'a']++;
    }

    for(int alpha = 'a'; alpha <= 'z'; alpha++){
        if(cache[alpha - 'a'] < K)
            continue;
        for(int i = 0; i < W.size(); i++){
            if(W[i] == alpha){
                int count = 0;
                for(int j = i; j < W.size(); j++){
                    
                    if(alpha == W[j])
                        count++;

                    if(count == K){
                        ans_min = min(ans_min, j - i + 1);
                        ans_max = max(ans_max, j - i + 1);
                        break;
                    }
                }
            }
        }
        
    }

}

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        string W;
        int K;
        
        cin >> W >> K;

        if(K == 1){
            cout << 1 << ' ' << 1 << endl;
            continue;
        }

        get_ans(W, K);

        if(ans_min == 100000 || ans_max == -1){
            cout << -1 << endl;
        }else
            cout << ans_min << ' ' << ans_max << endl;
        
        ans_min = 100000;
        ans_max = -1;
    }

    return 0;
}