#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    if (a.first[a.second] != b.first[b.second])
        return a.first[a.second] < b.first[b.second];
    else
        return a.first[0] > b.first[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<pair<vector<int>, int>> new_arr;
    vector<int> tmp;

    for (auto it : data) {
        new_arr.push_back(make_pair(it, col - 1));
    }

    sort(new_arr.begin(), new_arr.end(), comp);

    for (int i = row_begin - 1; i < row_end; i++) {
        int tmp = 0;
        for (auto it : new_arr[i].first) {
            tmp += it % (i + 1);
        }
        answer ^= tmp;
    }

    return answer;
}