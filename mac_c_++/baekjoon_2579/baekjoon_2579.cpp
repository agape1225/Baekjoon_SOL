#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    vector<int> stares;
    vector<int> cache;
    int N, stare;
    cin >> N;

    for(int i = 0; i < N; i++){
        // int stare;
        cin >> stare;
        stares.push_back(stare);
        cache.push_back(stare);
    }

    for(int i = 1; i < N; i++){
        if(i == 1){
            cache[i] = stares[i] + cache[i - 1];
        }
        else if(i == 2){
            cache[i] = max(stares[i - 1], cache[i - 2]) + stares[i];
        }else{
            cache[i] = max(cache[i - 3] + stares[i - 1], cache[i - 2]) + stares[i];
        }
    }

    cout << cache[N - 1];

    return 0;

}