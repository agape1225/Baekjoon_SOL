#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arrs;
    string buff = "";
    for (auto it : s) {
        if (it == ' ') {

            arrs.push_back(stoi(buff));
            buff = "";
        }
        else {
            buff += it;
        }
    }
    arrs.push_back(stoi(buff));

    sort(arrs.begin(), arrs.end());

    /*for(auto it : arrs){
        cout << it << ' ';
    }*/

    answer += to_string(*arrs.begin());
    answer += ' ';
    answer += to_string(*(arrs.end() - 1));

    return answer;
}