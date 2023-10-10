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
    stack<int> s;

    stable_sort(plans.begin(), plans.end(), compare);

    // for(auto it : plans){
    //     cout << it[0] << ' ' << it[1] << endl;
    // }

    s.push(0);

    for (int i = 1; i < plans.size(); i++) {
        if (s.empty()) {
            s.push(i);
        }
        else {
            int index = s.top();
            int stack_min = get_mins(plans[index][1], plans[index][2]);
            int next_min = get_mins(plans[i][1], "0");
            cout << stack_min << ' ' << next_min << endl;
            while (stack_min <= next_min) {

                cout << i << ' ' << next_min << ' ' << get_mins(plans[index][1], "0") << ' ' << endl;

                plans[index][2] = to_string(stoi(plans[index][2]) - (next_min - get_mins(plans[index][1], "0")));

                answer.push_back(plans[index][0]);
                s.pop();

                if (!s.empty()) {
                    index = s.top();
                    stack_min = get_mins(plans[index][1], plans[index][2]);
                }
                else
                    break;

            }
            plans[index][2] = to_string(stoi(plans[index][2]) - (next_min - get_mins(plans[index][1], "0")));
            s.push(i);
        }
    }

    while (!s.empty()) {
        answer.push_back(plans[s.top()][0]);
        s.pop();
    }



    //cout << ("11:40" < "12:10");

    return answer;
}