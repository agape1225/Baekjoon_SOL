#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//combination
int answer = 0;
//bool visited[9] = {0};
bool visited_num[10000000] = { 0 };
bool visited_digit[9] = { 0 };

bool check_prime(int n) {
    if (n == 1 || n == 0)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void get_ans(string numbers, string num) {

    if (num.size() < numbers.size()) {
        for (int i = 0; i < numbers.size(); i++) {

            int tmp = stoi(num + numbers[i]);
            //cout << num + numbers[i] << endl;

            if (!visited_digit[i]) {

                //cout << '|' << ' ' << tmp << endl;

                visited_digit[i] = true;

                if (check_prime(tmp) && !visited_num[tmp]) {
                    visited_num[tmp] = true;
                    answer++;
                }

                get_ans(numbers, num + numbers[i]);
                visited_digit[i] = false;
            }
        }
    }
}

int solution(string numbers) {
    get_ans(numbers, "");

    return answer;
}