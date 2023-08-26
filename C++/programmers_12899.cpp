#include<iostream>
#include <string>
#include <vector>
using namespace std;

char arr[3] = { '4','1','2' };

string solution(int n) {
    string answer = "";
    int a;
    while (n != 0) {
        a = n % 3;
        n = n / 3;
        if (a == 0) n -= 1;
        answer = arr[a] + answer;
    }
    return answer;
}