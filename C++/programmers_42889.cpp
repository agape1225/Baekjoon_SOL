#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int, float>& a, const pair<int, float>& b) {
    if (a.second == b.second) {

        return a.first < b.first;

    }
    else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> ans;

    sort(stages.begin(), stages.end());

    int max = stages.size();
    int index = 0;
    int standard = 1;

    //cout << max << endl << endl;

    while (standard <= N) {


        int count = 0;

        while (index < max && standard == stages[index]) {

            count++;
            index++;

        }

        double tmp = max - index + count;

        //cout << standard << ' ' << ' ' << count << ' ' << tmp << endl;

        if (tmp != 0)
            ans.push_back(make_pair(standard, count / tmp));
        else
            ans.push_back(make_pair(standard, 0.0));

        //cout << standard << ' ' << count / tmp << ' ' << index << endl;

        standard++;
        //index++;

    }

    sort(ans.begin(), ans.end(), compare);

    //cout << endl << endl;

    for (auto it = ans.begin(); it != ans.end(); it++) {

        answer.push_back((*it).first);
        //cout << (*it).first << ' ' << (*it).second << endl;

    }


    return answer;
}