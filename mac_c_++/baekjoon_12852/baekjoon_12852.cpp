#include <iostream>

using namespace std;

int main(void){

    int N; 
    int cache[1000005];
    int dir[1000005];

    cin >> N;

    cache[1] = 0;
    dir[1] = 0;
    cache[2] = 1;
    dir[2] = 1;
    cache[3] = 1;
    dir[3] = 1;

    for(int i = 4; i <= N; i++){

        cache[i] = cache[i - 1] + 1;
        dir[i] = i - 1;
        
        if(i % 2 == 0 && i / 2 > 0){
            if(cache[i] > cache[i / 2] + 1){
                cache[i] = cache[i / 2] + 1;
                dir[i] = i / 2;
            }
        }

        if(i % 3 == 0 && i / 3 > 0){
            if(cache[i] > cache[i / 3] + 1){
                cache[i] = cache[i / 3] + 1;
                dir[i] = i / 3;
            }
        }
    }

    cout << cache[N] << endl;
    cout << N << ' ';
    int index = N;
    while(index > 1){
        cout << dir[index] << ' ';
        index = dir[index];
    }
    // cout << 1;

    return 0;
}