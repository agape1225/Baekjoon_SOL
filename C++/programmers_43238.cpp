#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    unsigned long long left = 1;
    unsigned long long right = times[times.size() - 1] * n;
    unsigned long long mid = NULL;
    unsigned long long buff = NULL;

    while (left <= right) {

        mid = (left + right) / 2;
        buff = 0;

        for (auto it = times.begin(); it != times.end(); it++) {

            buff += mid / *it;

        }

        if (buff >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }


    }

    return answer;
}