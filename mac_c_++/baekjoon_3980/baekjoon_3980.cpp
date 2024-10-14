#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int ability[11][11] = {0};
        int playerIndex[11] = {0}; 
        int answer = 0;
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                cin >> ability[i][j];
            }
        }

        for(int j = 0; j < 11; j++){
            int tmp = -1;

            for(int i = 0; i < 11; i++){
                if(tmp < ability    )
                tmp = max(tmp, ability[i][j]);
            }

            answer += tmp;
        }
        cout << answer << '\n';
    }

    return 0;

}