#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int x = 1; x <= r2; x++)
    {
        long long maxY = floor(sqrt(r2 * 1LL * r2 - x * 1LL * x));
        long long minY = x >= r1 ? 0 : ceil(sqrt(r1 * 1LL * r1 - x * 1LL * x));

        answer += (maxY - minY + 1);
    }

    return answer * 4;
}