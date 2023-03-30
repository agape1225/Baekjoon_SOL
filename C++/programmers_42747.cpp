#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //int max_num = *max_element(citations.begin(), citations.end());

    for (int i = 0; i <= 10000; i++) {

        int over = 0;
        int under = 0;

        for (auto it : citations) {
            if (it >= i) {
                over++;

            }
            if (it <= i) {
                under++;
            }
        }
        if (over >= i && under <= i) {
            answer = i;
            //break;
        }

    }

    return answer;
}