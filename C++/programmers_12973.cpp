
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;

    st.push(*s.begin());

    for (int i = 1; i < s.size(); i++) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }


    if (st.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }


    return answer;
}