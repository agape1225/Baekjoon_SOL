#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool comp(int x, int y) {
    return x > y;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), comp);

    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }


    return answer;
}