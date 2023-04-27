#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    int index_count = 27;
    int size = msg.size();

    for (int i = 1; i < 27; i++) {
        string tmp(1, 'A' + i - 1);
        dic.insert(make_pair(tmp, i));
    }

    /*for(auto it : dic){
        cout << it.first << ' ' << it.second << endl;
    }*/

    for (int i = 0; i < msg.size(); ) {
        string tmp;
        int count_str = 1;

        //가장 긴 문자열 찾기
        while (i + count_str <= size && dic.find(msg.substr(i, count_str)) != dic.end()) {
            tmp = msg.substr(i, count_str);
            count_str++;
        }

        answer.push_back(dic[tmp]);
        dic.insert(make_pair(tmp + msg[i + count_str - 1], index_count++));
        i = i + count_str - 1;


    }
    return answer;
}