#include <iostream>
#include <algorithm>

using namespace std;

bool check_nums(int x, int y) {

    int max_num = max(x, y);
    int min_num = min(x, y);

    if (max_num % 2 == 0 && max_num - min_num == 1)
        return true;
    else
        return false;

}

int solution(int n, int a, int b)
{
    int answer = 1;

    while (!check_nums(a, b)) {
        answer++;

        //a, b�ʱ�ȭ ���ֱ�

        for (int i = 1; i <= n / 2; i++) {
            if (a <= i * 2) {
                a = i;
                break;
            }
        }

        for (int i = 1; i <= n / 2; i++) {
            if (b <= i * 2) {
                b = i;
                break;
            }
        }

        n /= 2;
        cout << a << ' ' << b << endl;

        //break;

    }

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}