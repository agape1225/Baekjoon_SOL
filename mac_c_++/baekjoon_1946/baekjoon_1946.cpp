#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;



int main(void){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        vector<pair<int, int>> arr;
        // map<int, int> m2;
        int N;
        int tmp1, tmp2;
        int ans = 0;
        int interview_score;

        cin >> N;

        for(int i = 0; i < N; i++){
            cin >> tmp1 >> tmp2;
            arr.push_back(make_pair(tmp1, tmp2));
        }

        sort(arr.begin(), arr.end());

        ans++;
        interview_score = arr[0].second;

        for(int i = 1; i < N; i++){
            pair<int, int> it = arr[i];
            if(it.second < interview_score){
                ans++;
                interview_score = it.second;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}