#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool sosu(int num) {
    if (num < 2) return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}

string get_number(int n, int k) {

    string ans = "";
    string buff;

    while (n > 0) {
        int tmp = n % k;
        n = n / k;
        buff = to_string(tmp);
        ans += buff;
        cout << buff << endl;
    }
    reverse(ans.begin(), ans.end());
    return ans;

}


int solution(int n, int k) {
    int answer = 0;

    string num = get_number(n, k);
    cout << num << endl;
    string buff = "";

    for (auto it = num.begin(); it != num.end(); it++) {

        if ((*it) == '0') {

            int tmp = stoi(buff);
            if (sosu(tmp))
                answer++;

            buff = "0";

        }
        else {

            buff += (*it);
        }
    }

    int tmp = stoi(buff);
    if (sosu(tmp))
        answer++;

    return answer;
}

int main(void) {

    solution(437674, 3);

}