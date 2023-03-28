#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_lcm(int a, int b) {
    for (int i = max(a, b); i <= a * b; i++) {
        if (i % a == 0 && i % b == 0)
            return i;
    }
}

int solution(vector<int> arr) {
    int answer = 1;

    sort(arr.begin(), arr.end());

    answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        answer = get_lcm(answer, arr[i]);
    }

    return answer;
}