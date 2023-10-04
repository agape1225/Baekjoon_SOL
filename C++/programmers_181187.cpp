#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long line_ans = 2 + r2 - r1;

    int start = r2;
    int end = r1;

    for (int x = 1; x < r2; x++) {

        //check start
        while (pow(x, 2) + pow(start, 2) > pow(r2, 2) && start > 0) {
            start--;
        }
        //check end
        //1 + 1 < 4
        while (pow(x, 2) + pow(end, 2) > pow(r1,2) && end > 0) {
            end--;
        }


        cout << x << ' ' << start << ' ' << end << endl;

        if (end != 0 && start != 0)
            answer += start - end;
        else 
            answer += start - end - 1;

    }

    return (answer + line_ans) * 4;
}

int main(void) {
    cout << solution(2, 5);
}