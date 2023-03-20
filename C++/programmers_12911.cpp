#include <string>
#include <vector>
#include <iostream>

using namespace std;

string get_digit(int n) {

    string digit = "";

    while (n > 0) {
        if (n % 2) {
            digit = digit + "1";
        }
        else {
            digit = digit + "0";
        }
        n = n / 2;
    }
    return digit;
}

int count_one(string num) {
    int count = 0;

    for (auto it : num) {
        if (it == '1') {
            count++;
        }
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int num_count = count_one(get_digit(n));

    for (int i = n + 1; i < 1000002; i++) {
        string tmp_digit = get_digit(i);
        int tmp_count = count_one(tmp_digit);

        if (num_count == tmp_count) {
            answer = i;
            break;
        }
    }

    return answer;
}