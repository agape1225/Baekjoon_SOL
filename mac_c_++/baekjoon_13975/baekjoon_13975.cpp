#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int K;
        // vector<long long> files;
        // vector<long long> newFilse;
        priority_queue<long long> pq;
        int tmp;
        long long ans = 0;

        cin >> K;

        for(int i = 0; i < K; i++){
            cin >> tmp;
            pq.push(-tmp);
        }

        while(pq.size() > 1){
            long long num1 = -pq.top();
            pq.pop();
            long long num2 = -pq.top();
            pq.pop();
            // cout << num1 << ' ' << num2 << endl;
            long long total = num1 + num2;
            ans += total;
            pq.push(-total);
        }

        cout << ans << '\n';
    }

    return 0;
}