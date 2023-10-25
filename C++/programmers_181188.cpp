#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    int end_position;

    sort(targets.begin(), targets.end(), compare);

    end_position = targets[0][1];

    for (int i = 1; i < targets.size(); i++) {
        if (end_position <= targets[i][0]) {
            end_position = targets[i][1];
            answer++;
        }
    }
    return answer;
}