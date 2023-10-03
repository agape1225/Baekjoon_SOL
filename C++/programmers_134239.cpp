#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> x;

    x.push_back(k);
    while (k != 1) {
        if (k % 2 == 0) {
            k /= 2;
            x.push_back(k);
        }
        else {
            k = 3 * k + 1;
            x.push_back(k);
        }
    }

    for (vector<int> range : ranges) {
        int a = range[0];
        int b = x.size() + range[1] - 1;

        if (b < a)
            answer.push_back(-1.0);
        else {
            double size = 0.0;
            for (int i = a; i < b; i++) {
                size += (x[i] + x[i + 1]) / 2;
            }
            answer.push_back(size);
        }
    }

    return answer;
}