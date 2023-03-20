#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_p = 0;
    int num_y = 0;

    for (auto it : s) {
        if (it == 'P' || it == 'p') {
            num_p++;
        }
        else if (it == 'Y' || it == 'y') {
            num_y++;
        }
    }

    if (num_p == num_y) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}