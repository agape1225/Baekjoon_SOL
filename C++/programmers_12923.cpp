#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++) {

        answer.push_back(1);

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if (i / j > 10000000) {
                    answer[i - begin] = j;
                    continue;
                }
                else
                    answer[i - begin] = i / j;
                break;
            }
        }
    }
    if (begin == 1)
        answer[0] = 0;
    return answer;
}