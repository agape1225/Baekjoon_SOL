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

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    if (st.size() != 0)
        return false;

    return answer;
}