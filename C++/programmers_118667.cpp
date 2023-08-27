#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int count = 0;

    long long sum1 = 0;
    long long sum2 = 0;
    long long sum = 0;

    long long init1 = 0;
    long long init2 = 0;

    queue<int> q1;
    queue<int> q2;

    int max = -1;

    for (auto it : queue1) {
        q1.push(it);
        if (max < it)
            max = it;
        sum1 += it;
        init1 += it;
    }

    for (auto it : queue2) {
        q2.push(it);
        if (max < it)
            max = it;
        sum2 += it;
        init2 += it;
    }

    sum = sum1 + sum2;

    if (max > sum / 2 || sum % 2 == 1) {

        return answer;
    }

    for (int i = 0; i < 10000000; i++) {
        if (sum1 == sum2) {
            answer = count;
            break;
        }
        else if (sum1 > sum2) {
            int front = q1.front();
            q1.pop();

            q2.push(front);

            sum1 -= front;
            sum2 += front;

        }
        else if (sum1 < sum2) {
            int front = q2.front();
            q2.pop();

            q1.push(front);

            sum2 -= front;
            sum1 += front;
        }

        count++;
    }

    return answer;
}