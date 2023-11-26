#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    do {
        cout << h1 << ' ' << m1 << ' ' << s1 << endl;
        if (h1 >= 12) {
            if (h1 - 12 == s1)
                answer++;
            else if (m1 == s1)
                answer++;
        }
        else {
            if (h1 == s1)
                answer++;
            else if (m1 == s1)
                answer++;
        }
        //시계 조정
        s1++;
        if (s1 == 60) {
            s1 = 0;
            m1++;
        }
        if (m1 == 60) {
            m1 = 0;
            h1++;
        }
    }     while (!(h1 == h2 && m1 == m2 && s1 == s2));

    return answer;
}

int main(void) {
    solution(11, 59, 30, 12, 0, 0);
}