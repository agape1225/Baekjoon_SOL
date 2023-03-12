#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

string solution(string s) {
    string answer = "";

    if ('a' <= s[0] && s[0] <= 'z') {
        s[0] = s[0] - ('a' - 'A');
    }
    answer.push_back(s[0]);

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == ' ' && 'a' <= s[i + 1] && s[i + 1] <= 'z') {
            s[i + 1] = s[i + 1] - ('a' - 'A');
        }
        else if (s[i] != ' ' && 'A' <= s[i + 1] && s[i + 1] <= 'Z') {
            s[i + 1] = s[i + 1] + ('a' - 'A');
        }
        answer.push_back(s[i]);
    }
    answer.push_back(s[s.size() - 1]);

    return s;
}