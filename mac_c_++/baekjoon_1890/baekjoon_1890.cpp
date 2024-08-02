#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    int bord[105][105];
    long long cache[105][105] = {0};

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> bord[i][j];
        }
    }

    cache[0][0] = 1;    

    for(int i = 0; i < N; i++){

        for(int j = 0; j < N; j++){
            if(cache[i][j] != 0){

                if(i == N - 1 && j == N - 1)
                continue;
            int new_i = i + bord[i][j];
            int new_j = j + bord[i][j];
            

            if(new_i < N){
                // cout << i << ' ' << j << ' ' << new_i << ' ' << j << endl << endl;
                cache[new_i][j] += cache[i][j];
            }

            if(new_j < N){
                // cout << i << ' ' << j << ' ' << i << ' ' << new_j << endl << endl;
                cache[i][new_j] += cache[i][j];
            }

            }

            

            // cout << endl; 
            // for(int k = 0; k < N; k++){
            //     for(int l = 0; l < N; l++){
            //         cout << cache[k][l] << ' ';
            //     }
            // cout << endl;
            // }
        }
            
        // }

        
        

    }

    cout << cache[N - 1][N - 1];

    return 0;

}