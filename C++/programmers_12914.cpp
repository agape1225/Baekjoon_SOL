#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long cache[2001] = { 0 };
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; i++) {

        cache[i] += (cache[i - 1] + cache[i - 2]) % 1234567;

    }

    answer = cache[n];

    return answer;
}