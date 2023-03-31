#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check_str(string str, int start_index) {
    stack<char> s;
    int size = str.size();
    int index;
    char it;

    for (int i = 0; i < str.size(); i++) {

        index = (start_index + i) % size;
        it = str[index];

        if (it == '[' || it == '{' || it == '(') {
            s.push(it);
        }
        else if (it == ')') {
            if (s.top() != '(') {
                return false;
            }
            else {
                s.pop();
            }
        }
        else if (it == '}') {
            if (s.top() != '{') {
                return false;
            }
            else {
                s.pop();
            }
        }
        else if (it == ']') {
            if (s.top() != '[') {
                return false;
            }
            else {
                s.pop();
            }
        }

    }



    if (s.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        if (check_str(s, i))
            answer++;
    }


    return answer;
}