#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for (auto it : s) {
        if (it == '(') {
            st.push(it);
        }
        else {
            if (st.size() == 0 || st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    if (st.size() != 0)
        return false;

    return answer;
}