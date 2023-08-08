#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;

    answer.push_back(-1);
    s.push(numbers[numbers.size() - 1]);

    for (int i = numbers.size() - 2; i >= 0; i--) {
        int num = numbers[i];
        int top_num = -1;

        if (!s.empty())
            top_num = s.top();

        if (num > top_num || num == top_num) {

            int tmp = -1;

            while (!s.empty()) {
                if (s.top() > num) {
                    tmp = s.top();
                    break;
                }
                s.pop();
            }
            answer.push_back(tmp);
            s.push(num);
        }
        else {
            answer.push_back(top_num);
            s.push(num);
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}