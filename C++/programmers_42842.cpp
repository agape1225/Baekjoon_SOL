#include <string>
#include <vector>

using namespace std;

/*
    x * y - yellow = brown
    2x + 2(y - 2) = brown

    x = (brown + yellow) / y
    x = ((brown + 4) / 2) - y

*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int x, y;

    for (int i = 0; i < 5001; i++) {
        for (int j = 0; j < 5001; j++) {

            if (j * i - yellow == brown && 2 * j + 2 * (i - 2) == brown) {
                x = j;
                y = i;
                break;
            }
        }

    }

    answer.push_back(y);
    answer.push_back(x);

    return answer;
}