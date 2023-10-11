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

    //할만 하다
    s.push(0);

    for (int i = 0; i < plans.size(); i++) {
        int current_index = s.top();
        int next_index = i;

        int current_min = get_mins(plans[current_index][1], plans[current_index][2]);
        int next_min = get_mins(plans[next_index][1], "0");

        //시작시간이 더 크면 -> 이부분이 잘 해결되어야함
        if (current_min <= next_min) {
            //top의 시작시간 부터 끝시간까지가 남은 시간
            int remain_time = get_mins(plans[current_index][1], "0") - current_min;
            int taken_time = stoi(plans[current_index][2]);

            while (remain_time - taken_time >= 0) {
                answer.push_back(plans[current_index][0]);
                s.pop();

                if (!s.empty())
                    break;

                current_index = s.top();
                remain_time -= taken_time;
                taken_time = stoi(plans[current_index][2]);
            }

            if (!s.empty()) {
                plans[current_index][2] = to_string(taken_time - remain_time);
            }

            s.push(next_index);

        }
        //시작시간이 더 작으면
        else {
            //지금까지 진행된 시간을 작업량에서 빼준다.
            int gap = next_min - get_mins(plans[current_index][1], "0");
            plans[current_index][2] = to_string(
                stoi(plans[current_index][2]) - gap

            );
            s.push(next_index);

        }



    }

    return answer;
}