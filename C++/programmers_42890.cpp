#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool visited[8] = { 0 };
set<string> answers;
vector<vector<int>> keys;

bool find_str(string str) {
    for (auto key : answers) {
        int count = 0;
        for (auto it : key) {
            if (str.find(it) != string::npos)
                count++;
        }
        if (count == key.size())
            return false;
    }
    return true;
}

void get_cols(int max, int count, int start, int size) {
    if (count < max) {
        for (int i = start; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                get_cols(max, count + 1, i + 1, size);
                visited[i] = false;
            }
        }
    }
    else {
        vector<int> tmp;
        for (int i = 0; i < size; i++) {
            if (visited[i]) {
                tmp.push_back(i);
            }
        }
        keys.push_back(tmp);
    }
}

void is_key(vector<vector<string>> relation) {

    for (auto cols : keys) {
        set<string> all_key;
        bool dir = true;
        for (int row = 0; row < relation.size(); row++) {
            string tmp;
            for (int i = 0; i < cols.size(); i++) {
                tmp += relation[row][cols[i]];
            }
            if (all_key.find(tmp) == all_key.end()) {
                all_key.insert(tmp);
            }
            else {
                dir = false;
            }
        }
        if (dir) {
            string key_str;

            for (int i = 0; i < cols.size(); i++) {
                key_str += to_string(cols[i]);
            }

            if (find_str(key_str)) {
                answers.insert(key_str);
            }
        }
    }
}

int solution(vector<vector<string>> relation) {

    for (int i = 1; i <= relation[0].size(); i++) {

        for (int j = 0; j < 8; j++) {
            visited[j] = false;
        }
        keys.clear();

        get_cols(i, 0, 0, relation[0].size());
        is_key(relation);
    }
    return answers.size();
}