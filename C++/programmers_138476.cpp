#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;


    for (auto num : tangerine) {
        if (m.find(num) == m.end()) {
            m.insert(make_pair(num, 1));
        }
        else {
            m[num]++;
        }
    }

    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    /*for(auto it : vec){
        cout << it.first << ' ' << it.second << endl;
    }*/

    int index = 0;

    while (k > 0) {
        answer++;
        k -= vec[index].second;
        index++;
    }



    return answer;
}