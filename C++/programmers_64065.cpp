#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int cache[100001] = { 0 };

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;


    int buff = 0;

    for (auto it : s) {

        if ('0' <= it && it <= '9') {
            buff = (buff * 10) + it - '0';
        }
        else if ((it == ',' || it == '}') && buff > 0) {
            if (m.find(buff) != m.end()) {
                m[buff]++;

            }
            else {
                m.insert(make_pair(buff, 1));

            }
            buff = 0;
        }

    }


    for (auto it : m) {
        cout << it.first << ' ' << it.second << endl;
    }

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (auto it : v) {
        answer.push_back(it.first);
    }

    return answer;
}