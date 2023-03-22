#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> tmp;
    int count = 1;
    string past = words[0];
    tmp.push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {
        string it = words[i];

        if (find(tmp.begin(), tmp.end(), it) == tmp.end()
            && past[past.size() - 1] == it[0]) {
            tmp.push_back(it);
            past = it;
        }
        else {

            break;
        }
        count++;
    }
    count++;


    cout << count;

    if (count == words.size() + 1) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }


    if (count % n == 0) {
        answer.push_back(n);
        answer.push_back((count / n));
    }
    else {
        cout << ceil(count / n);
        answer.push_back(count % n);
        answer.push_back(ceil((count + 0.0) / (n + 0.0)));
    }



    return answer;
}