#include <iostream>

using namespace std;

int main(void){
    //...?

    int bord[105][105] = {0};
    long long cache[105][105] = {0};

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> bord[i][j];
        }
    }

    if(N > bord[0][0]){
        cache[0][bord[0][0]] = 1;
        cache[bord[0][0]][0] = 1;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if(cache[i][j] > 0 && bord[i][j] > 0){
                int num = bord[i][j];
                if(i + num < N){
                    cache[i + num][j]+= cache[i][j];
                }

                if(j + num < N){
                    cache[i][j + num] += cache[i][j];
                }
            }
        }
    }

    cout << cache[N - 1][N - 1];

    return 0;

}