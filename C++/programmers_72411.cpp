#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[15];
bool menus_index[10];
vector<pair<string, int>> ans;

void get_course_menu(int count, string order, int target_num, int start_num) {
    if (count < target_num) {
        for (int i = start_num; i < order.size(); i++) {
            if (!menus_index[i]) {
                menus_index[i] = true;
                get_course_menu(count + 1, order, target_num, i + 1);
                menus_index[i] = false;
            }
        }
    }
    else {
        string tmp = "";
        bool dir = false;
        for (int i = 0; i < order.size(); i++) {
            if (menus_index[i]) {
                tmp += order[i];
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].first == tmp) {
                ans[i].second = ans[i].second + 1;
                dir = true;
                break;
            }
        }

        if (!dir) {
            ans.push_back(make_pair(tmp, 1));
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (auto menu_num : course) {
        int max = 0;
        vector<string> course_ans;
        ans.clear();

        for (auto it : orders) {
            for (int i = 0; i < 15; i++) {
                visited[i] = false;
            }
            get_course_menu(0, it, menu_num, 0);
        }

        for (auto it : ans) {

            cout << '(' << it.first << ' ' << it.second << ')';
        }
        cout << endl;

        for (auto it : ans) {
            if (it.second > max)
                max = it.second;
        }

        if (max > 1) {
            for (auto it : ans) {
                if (it.second == max) {
                    answer.push_back(it.first);
                }

            }

        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}