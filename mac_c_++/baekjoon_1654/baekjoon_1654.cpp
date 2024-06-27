#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){

    int K, N;
    long long ans = -1;
    long long line;
    long long max_line = 0;
    vector<long long> lines;
    cin >> K >> N;

    for(int i = 0; i < K; i++){
        cin >> line;
        lines.push_back(line);

        max_line = max(max_line, line);
    }

    long long left = 1;
    long long right = max_line;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long tmp = 0;

        for(int i = 0; i < K; i++){
            tmp += lines[i] / mid;
        }

        // cout << tmp << ' ' << mid << endl;

        if(tmp >= N){
            left = mid + 1;
            ans = max(ans, mid);
        }else{
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;

}