#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dis = pow(d, 2);
    int end = min(k, d);
    int max_num = d;

    for (int i = 0; i <= d; i += k) {
        // while(dis < (pow(i, 2) + pow(max_num, 2))){
        //     max_num -= k;
        // }
        // cout << i << ' ' << max_num << endl;
        // answer += (max_num ) / k + 1;
        answer += (floor(sqrt(dis - pow(i, 2))) / k) + 1;
    }

    return answer;
}