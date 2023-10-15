#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int get_mins(string time, string min) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    return (h * 60) + m + stoi(min);
}

vector<string> solution(vector<vector<string>> plans) {

    vector<string> answer;
    stack<pair<int, int>> s;

    stable_sort(plans.begin(), plans.end(), compare);
    for (int i = 0; i < plans.size() - 1; i++) {
        s.push(make_pair(i, stoi(plans[i][2])));
        int gap = get_mins(plans[i + 1][1], "0") - get_mins(plans[i][1], "0");

        while (!s.empty() && gap != 0) {
            int current_name = s.top().first;
            int current_time = s.top().second;

            s.pop();
            if (current_time <= gap) {

                gap -= current_time;
                answer.push_back(plans[current_name][0]);

                //current_name = s.top().first;
                //current_time = s.top().second;

            }
            else {
                s.push(make_pair(current_name, current_time - gap));
                gap = 0;
            }
        }

    }
    answer.push_back(plans[plans.size() - 1][0]);

    while (!s.empty()) {
        answer.push_back(plans[s.top().first][0]);
        s.pop();
    }
    return answer;
}