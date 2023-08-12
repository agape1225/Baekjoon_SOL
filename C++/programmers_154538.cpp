#include <string>
#include <vector>
#include <queue>

using namespace std;

int cache[1000001] = { 0 };

int solution(int x, int y, int n) {
    int answer = 0;

    for (int i = x; i <= y; i++) {
        cache[i] = -1;
    }

    queue<int> q;
    q.push(x);
    cache[x] = 0;

    while (!q.empty()) {

        int num = q.front();
        q.pop();

        if (num + n <= y && cache[num + n] == -1) {
            cache[num + n] = cache[num] + 1;
            q.push(num + n);
        }

        if (num * 2 <= y && cache[num * 2] == -1) {
            cache[num * 2] = cache[num] + 1;
            q.push(num * 2);
        }

        if (num * 3 <= y && cache[num * 3] == -1) {
            cache[num * 3] = cache[num] + 1;
            q.push(num * 3);
        }

    }

    answer = cache[y];

    return answer;
}