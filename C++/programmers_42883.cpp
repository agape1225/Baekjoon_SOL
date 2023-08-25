#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_num(int start_index, int end_index, string num) {
    int max_index = start_index;
    char max_num = num[start_index];

    for (int i = start_index + 1; i < end_index; i++) {
        if (max_num < num[i]) {
            max_num = num[i];
            max_index = i;
        }
    }

    return max_index;
}

string solution(string number, int k) {
    string answer = "";
    int select_num = number.size() - k;
    int start_index = 0;
    int end_index = number.size() - (select_num - 1);

    while (select_num > 0) {
        //문자열 앞 부터 select_num - 1 까지의 숫자중 최대값 찾기
        int max_index = get_num(start_index, end_index, number);

        answer.push_back(number[max_index]);

        select_num--;
        start_index = max_index + 1;
        end_index = number.size() - (select_num - 1);
    }

    return answer;
}