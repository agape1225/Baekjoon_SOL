#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count_num = 0;
    int count_zero = 0;

    while (s != "1") {
        string buff = "";
        for (auto it : s) {
            if (it != '0') {
                buff += it;
            }
            else {
                count_zero++;
            }
        }
        count_num++;
        int tmp = buff.size();
        s = "";

        while (tmp > 0) {
            if (tmp % 2 == 1) {
                s = s + "1";
            }
            else {
                s = s + "0";
            }
            tmp = tmp / 2;
        }

    }

    answer.push_back(count_num);
    answer.push_back(count_zero);

    return answer;
}