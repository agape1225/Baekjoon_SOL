    #include <iostream>
    #include <algorithm>

    using namespace std;

    int T[16] = {0};
    int P[16] = {0};
    int N;
    int ans = 0;

    void get_ans(int day, int count){
        if(day >= N) {
            ans = max(ans, count);
            return;
        }

        if(day + T[day] <= N)
            get_ans(day + T[day], count + P[day]);
        if(day + 1)
            get_ans(day + 1, count);
    }

    int main(void) {
        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> T[i] >> P[i];
        }

        get_ans(0, 0);

        cout << ans;

        return 0;
    }