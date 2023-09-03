#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string cal_ans(string exp, string priority) {
    string exp_tmp = exp;
    for (auto it : priority) {
        for (int i = 0; i < exp_tmp.size(); i++) {
            if (exp_tmp[i] == it) {
                string num1 = "";
                string num2 = "";

                int index1 = i - 1;
                int index2 = i + 1;

                while (index1 >= 0 && exp_tmp[index1] >= '0' && exp_tmp[index1] <= '9') {
                    num1 = exp_tmp[index1] + num1;
                    index1--;
                }

                while (index2 < exp_tmp.size()
                    && exp_tmp[index2] >= '0' && exp_tmp[index2] <= '9') {
                    num2 += exp_tmp[index2];
                    index2++;
                }

                string ans;

                if (it == '*') {
                    ans = to_string(stoll(num1) * stoll(num2));
                }
                else if (it == '+') {
                    ans = to_string(stoll(num1) + stoll(num2));
                }
                else if (it == '-') {
                    ans = to_string(stoll(num1) - stoll(num2));
                }

                exp_tmp = exp_tmp.substr(0, index1 + 1) + ans + exp_tmp.substr(index2, exp_tmp.size() - index2 - 1);
            }
        }
        cout << it << ' ' << exp_tmp << endl;
    }
    return exp_tmp;
}

//구현 + 문자열
long long solution(string expression) {
    long long answer = 0;
    vector<string> priority = { "*+-", "*-+", "+-*", "+*-", "-+*", "-*+" };

    for (auto it : priority) {
        answer = max(answer, stoll(cal_ans(expression, it)));
    }

    //1. 우선순위 만들기
    //2. 계산
    return answer;
}

int main(void) {
    solution("100-200*300-500+20");
    return 0;
}