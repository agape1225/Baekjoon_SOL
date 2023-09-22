#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int start, int mid, int end, int size) {
    if (size > 0) {
        hanoi(start, end, mid, size - 1);
        answer.push_back({ start, end });
        hanoi(mid, start, end, size - 1);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(1, 2, 3, n);
    return answer;
}