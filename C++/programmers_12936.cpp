#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool cache[21] = { 0 };

vector<int> get_combine(int n, long long k, vector<int> ans, long long start) {

    long long gap = n - ans.size() - 1;

    for (int i = 2; i < n - ans.size(); i++) {
        gap *= n - ans.size() - i;
    }

    if (gap == 0) {
        for (int i = 1; i <= n; i++) {
            if (!cache[i]) {
                ans.push_back(i);
                return ans;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cache[i]) {
            continue;
        }
        if (k <= start + gap - 1) {
            ans.push_back(i);
            cache[i] = true;
            break;
        }
        start += gap;
    }

    return get_combine(n, k, ans, start);

}

vector<int> solution(int n, long long k) {

    vector<int> answer;

    return get_combine(n, k, answer, 1);
}