#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int cache[60001] = { 0 };

int solution(int n) {
    int answer = 0;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % MOD;
    }

    answer = cache[n];

    return answer;
}