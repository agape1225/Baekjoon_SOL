#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    bool walls[105] = {0};
    int ans = 1;
    pair<int, int> commands[105];

    cin >> N >> M;

    //있고 없고를 구분하는 boolean
    for(int i = 0; i <= N; i++ ) {
        walls[i] = true;
    }

    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        // cin >> commands[i].first >> commands[i].second;

        for(int j = start; j < end; j++) {
            walls[j] = false;
        }
    }

    for(int i = 1; i < N; i++) {
        if(walls[i]) {
            ans++;
        }
    }

    cout << ans;

    return 0;


}