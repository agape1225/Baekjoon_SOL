#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int get_stress(int pick, string mineral) {
    if (pick == 1) {
        if (mineral == "diamond")
            return 5;
    }
    else if(pick == 2) {
        if (mineral == "diamond")
            return 25;
        else if (mineral == "iron")
            return 5;
    }
    return 1;
}

bool check_pick(vector<int> pick) {
    for (int i = 0; i < 3; i++) {
        if (pick[i] > 0)
            return false;
    }
    return true;
}

int solution(vector<int> picks, vector<string> minerals) {

    int answer = 50 * 25;
    queue<pair<vector<int>, pair<int, int>>> q;

    q.push(
        make_pair(picks,
        make_pair(0, 0)
        )
    );

    while (!q.empty()) {

        vector<int> pick = q.front().first;
        int index = q.front().second.first;
        int count = q.front().second.second;

        q.pop();

        if (index == minerals.size() || check_pick(pick))
            answer = min(count, answer);
        
        for (int i = 0; i < 3; i++) {
            if (pick[i] > 0) {

                int tmp_count = count;
                vector<int> tmp_picks = pick;
                int j;

                for (j = 0; j < 5 && (index + j) < minerals.size(); j++)
                    tmp_count += get_stress(i, minerals[index + j]);
                
                tmp_picks[i]--;
                q.push(make_pair(tmp_picks, make_pair(index + j, tmp_count)));

            }
        }
    }

    return answer;
}