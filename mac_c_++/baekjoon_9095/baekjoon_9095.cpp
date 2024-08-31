#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int n;
        int cache[11] = {0};

        cin >> n;

        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;

        /*
            1       +3

            1+1     +2
            2       +2

            1+1+1   +1
            1+2     +1
            2+1     +1
            3       +1
        */

       for(int i = 4; i <= n; i++ ){
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
       }

       cout << cache[n] << '\n';
    }

    return 0;
}