#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    

    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int cache[2][100005] = {0};
        int sticker[2][100005] = {0};
        int N;

        cin >> N;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                cin >> sticker[i][j];
            }
        }

        cache[0][0] = sticker[0][0];
        cache[1][0] = sticker[1][0];

        if(N == 1){
            cout << max(cache[0][0], cache[1][0]) << endl;
            continue;
        }

        cache[0][1] = sticker[0][1] + sticker[1][0];
		cache[1][1] = sticker[1][1] + sticker[0][0];

		if (N == 2) {
			cout << max(cache[0][1], cache[1][1]) << '\n';
			continue;
		}
        
        for(int i = 2; i < N; i++){

            //차이점 찾기
            cache[0][i] = max(cache[0][i - 2] + sticker[1][i - 1], cache[1][i - 2]) + sticker[0][i];
            cache[1][i] = max(cache[1][i - 2] + sticker[0][i - 1], cache[0][i - 2]) + sticker[1][i];

            cache[0][i] = max(cache[1][i - 1] + sticker[0][i], cache[0][i - 1]);
            cache[1][i] = max(cache[0][i - 1] + sticker[1][i], cache[1][i - 1]);
        }

        cout << max(cache[0][N - 1], cache[1][N - 1]) << '\n';
    }

    return 0;


}