#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {

    if (s1 + s2 >= s2 + s1)
        return false;
    else
        return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;

    for (int i = 0; i < numbers.size(); i++) {
        strings.push_back(to_string(numbers[i]));
    }

    sort(strings.begin(), strings.end(), comp);

    for (int i = strings.size() - 1; i > -1; i--) {
        answer += strings[i];
    }


    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != '0')
            return answer;
    }

    return "0";
}