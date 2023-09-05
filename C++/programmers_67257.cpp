#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string cal_ans(string exp, string priority) {
    string exp_tmp = exp;
    cout << exp << endl;
    for (auto it : priority) {
        for (int i = 0; i < exp_tmp.size(); i++) {
            if (exp_tmp[i] == it) {
                if (exp_tmp[i] == '-' && i >= 1 && exp_tmp[i - 1] == '(')
                    continue;
                cout << it << ' ' << i << ' ';
                string num1 = "";
                string num2 = "";

                int index1 = i - 2;
                int index2 = i + 2;

                while (index1 >= 0 && ((exp_tmp[index1] >= '0' && exp_tmp[index1] <= '9') || exp_tmp[index1] == '-')) {
                    num1 = exp_tmp[index1] + num1;
                    index1--;
                }

                while (index2 < exp_tmp.size()
                    && ((exp_tmp[index2] >= '0' && exp_tmp[index2] <= '9') || exp_tmp[index2] == '-')) {
                    num2 += exp_tmp[index2];
                    index2++;
                }

                cout << num1 << ' ' << num2 << ' ';

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
                
                exp_tmp = exp_tmp.substr(0, index1 + 1) + ans + exp_tmp.substr(index2, exp_tmp.size() - index2);
                cout << ' ' << exp_tmp << endl;
                i = 0;
            }
        }
       
    }
    cout << exp_tmp.substr(1, exp_tmp.size() - 3) << endl;
    
    return exp_tmp.substr(1, exp_tmp.size() - 3);
}

string add_bracket(string expression) {
    string exp_tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            string num = "";

            while (i < expression.size()
                && expression[i] >= '0' && expression[i] <= '9') {
                num += expression[i];
                i++;
            }

            string ans = "(" + num + ")";
            exp_tmp += ans + expression[i];
        }
    }
    return exp_tmp;
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> priority = { "*+-", "*-+", "+-*", "+*-", "-+*", "-*+" };

    expression = add_bracket(expression);

    for (auto it : priority) {
        answer = max(answer, abs(stoll(cal_ans(expression, it))));
    }

    return answer;
}