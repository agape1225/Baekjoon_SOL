#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

#include <iostream>

using namespace std;

map<string, vector<int>> scores; // 각 query에 대한 코딩테스트 점수를 담은 객체

// 각 info에 대해 가능한 모든 query에 코딩테스트 점수 저장
void storeScore(vector<vector<string>>& tmp, int score) {
    string c1, c2, c3, c4;

    for (int i = 0; i < 2; i++) {
        c1 = tmp[0][i];
        for (int j = 0; j < 2; j++) {
            c2 = tmp[1][j];
            for (int k = 0; k < 2; k++) {
                c3 = tmp[2][k];
                for (int l = 0; l < 2; l++) {
                    c4 = tmp[3][l];
                    scores[c1 + c2 + c3 + c4].push_back(score);
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> tmp(4, vector<string>(2, "-"));

    for (int i = 0; i < info.size(); i++) {
        string s;
        int idx = 0, score = 0;

        stringstream ss(info[i]);

        while (ss >> s) {
            if (idx < 4) tmp[idx++][0] = s;
            else score = stoi(s);
        }

        for (auto it : tmp) {
            for (auto jt : it) {
                cout << jt << ' ';
            }
            cout << endl;
        }



        storeScore(tmp, score);
    }

    // 코딩테스트 점수 오름차순 정렬
    for (auto it : scores) {
        sort(scores[it.first].begin(), scores[it.first].end());
    }

    for (string q : query) {
        string s, key = "";
        int idx = 0, score = 0;

        stringstream ss(q);

        while (ss >> s) {
            if (s == "and") continue;

            if (idx < 4) {
                key += s;
                idx++;
            }
            else {
                score = stoi(s);
            }
        }

        auto it = lower_bound(scores[key].begin(), scores[key].end(), score);
        answer.push_back(scores[key].size() - (it - scores[key].begin()));
    }

    return answer;
}

int main(void) {
    solution(
        { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" },
        { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" });
}