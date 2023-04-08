#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int>& arr1, vector<int>& arr2) {
    if (arr1[0] == arr2[0])
        return arr1[1] < arr2[1];
    return arr1[0] > arr2[0];
}

int ans = 0;
bool visited[8] = { 0 };

void get_ans(int k, vector<vector<int>> dun, int count) {
    for (int i = 0; i < dun.size(); i++) {
        if (!visited[i]) {
            if (dun[i][0] > k) {
                ans = max(ans, count);
            }
            else {
                visited[i] = true;
                get_ans(k - dun[i][1], dun, count + 1);
                visited[i] = false;
            }
        }
    }

    if (count == dun.size())
        ans = count;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    get_ans(k, dungeons, 0);

    return ans;
}