#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

string get_bit(int n, int num) {
    string ans;
    string buff;

    while (num > 0) {
        ans += to_string(num % 2);
        num = num / 2;
    }

    for (int i = 0; i < n - ans.size(); i++) {
        buff += '0';
    }

    reverse(ans.begin(), ans.end());

    return buff + ans;

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> arr_str1;
    vector<string> arr_str2;

    for (int i = 0; i < n; i++) {

        arr_str1.push_back(get_bit(n, arr1[i]));
        arr_str2.push_back(get_bit(n, arr2[i]));
    }

    for (int i = 0; i < n; i++) {

        string str1 = arr_str1[i];
        string str2 = arr_str2[i];
        string ans_tmp;

        for (int j = 0; j < n; j++) {

            if (str1[j] == '1' || str2[j] == '1')
                ans_tmp += '#';
            else
                ans_tmp += ' ';

        }
        answer.push_back(ans_tmp);

    }


    return answer;
}