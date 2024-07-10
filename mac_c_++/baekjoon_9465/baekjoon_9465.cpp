#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int sticker[2][100005];
        int cache[2][100005];

        int n;

        cin >> n;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> sticker[i][j];
            }
        }

        cache[0][0] = sticker[0][0];
        cache[0][1] = sticker[0][1];

		if (n == 1) {
			cout << max(cache[0][0], cache[1][0]) << '\n';
			continue;
		}

		cache[0][1] = sticker[0][1] + sticker[1][0];
		cache[1][1] = sticker[1][1] + sticker[0][0];

		if (n == 2) {
			cout << max(cache[0][1], cache[1][1]) << '\n';
			continue;
		}

        for(int i = 1; i < n; i++){
            cache[0][i] = max(cache[1][i - 1] + sticker[0][i], cache[0][i - 1]);
            cache[1][i] = max(cache[0][i - 1] + sticker[1][i], cache[1][i - 1]);
        }

        cout << max(cache[0][n - 1], cache[1][n - 1]) << '\n';
    }

    return 0;
}