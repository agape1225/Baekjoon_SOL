#include <iostream>
#include <algorithm>

using namespace std;

int ans_battery = 987654321;

void get_ans(int n, int battery, int location) {

    if (location < n) {

        if (location != 0)
            get_ans(n, battery, location * 2);
        get_ans(n, battery + 1, location + 1);


    }
    else {
        if (location == n) {
            ans_battery = min(battery, ans_battery);
        }
    }

}

int solution(int n)
{
    int ans = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    //get_ans(n, 0, 0);

    while (n > 0) {
        if (n % 2 == 0)
            n /= 2;
        else {
            n--;
            ans++;
        }

    }


    return ans;
}