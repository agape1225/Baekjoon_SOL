#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_ans(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    sort(arrayA.begin(), arrayA.end());

    int min = arrayA[0];
    int a;

    for (int i = 1; i < min; i++) {

        if (min % i == 0) {

            int tmp = min / i;
            bool dir = true;
            bool arrayB_dir = true;

            for (auto it : arrayA) {
                if (it % tmp != 0) {
                    dir = false;
                    break;
                }
            }

            if (dir) {

                for (auto it : arrayB) {
                    if (it % tmp == 0) {
                        arrayB_dir = false;
                        break;
                    }
                }

                if (arrayB_dir) {
                    answer = tmp;
                    break;
                }

            }
        }
    }
    return answer;
}

int solution(vector<int> arrayA, vector<int> arrayB) {


    return max(get_ans(arrayA, arrayB), get_ans(arrayB, arrayA));
}