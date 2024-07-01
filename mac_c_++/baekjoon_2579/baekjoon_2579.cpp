#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    vector<int> stairs;
    vector<int> cache;
    int N, s;
    cin >> N;

    for(int i = 0; i < N; i++){
        // int stare;
        cin >> s;
        stairs.push_back(s);
        cache.push_back(s);
    }

    for(int i = 1; i < N; i++){
        if(i == 1){
            cache[i] = stairs[i] + cache[i - 1];
        }
        else if(i == 2){
            cache[i] = max(stairs[i - 1], cache[i - 2]) + stairs[i];
        }else{
            cache[i] = max(cache[i - 3] + stairs[i - 1], cache[i - 2]) + stairs[i];
        }
    }

    cout << cache[N - 1];

    return 0;

}