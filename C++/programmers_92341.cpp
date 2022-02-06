#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

int change_to_minute(string str) {
    int ans = 0;

    ans += (stoi(str.substr(0, 2))) * 60;
    ans += stoi(str.substr(3, 2));

    return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<int> answer;
    map<string, int> ans;                           // 차량 번호와 시간이 저장되어 있음
    map<string, int> m;                             // 계산시 사용하는 버퍼

    for (auto it = records.begin(); it != records.end(); it++) {

        vector<string> buff = split((*it), ' ');

        if (buff[2] == "IN") {

            m.insert(make_pair(buff[1], change_to_minute(buff[0])));

        }
        else {

            int out_time = change_to_minute(buff[0]);
            int in_time = (*m.find(buff[1])).second;
            m.erase(buff[1]);
            
            int time = out_time - in_time;
            
            if (ans.find(buff[1]) == ans.end()) {       // 존재하지 않으면

                ans.insert(make_pair(buff[1], time));

            }
            else {                                      // 존재하면

                int tmp = (*ans.find(buff[1])).second;
                ans.erase(buff[1]);

                ans.insert(make_pair(buff[1], time + tmp));
            }
        }
    }
    
    int last_time = change_to_minute("23:59");
    
    for(auto it = m.begin(); it != m.end(); it++){
        
        int in_time = (*it).second;
        int final_time = last_time - in_time;
        
        if (ans.find((*it).first) == ans.end()) {       // 존재하지 않으면

                ans.insert(make_pair((*it).first, final_time));

            }
            else {                                      // 존재하면

                int tmp = (*ans.find((*it).first)).second;
                ans.erase((*it).first);

                ans.insert(make_pair((*it).first, final_time + tmp));
            }
    }

    for (auto it = ans.begin(); it != ans.end(); it++) {
        
        int cost;
        
        cout << (*it).second << endl;
        
        if ((*it).second <= fees[0]) {                      //기본시간 이하
            cost = fees[1];
        }
        else {                                      //기본시간 이상
            cost = fees[1] + ceil(((*it).second - fees[0]) / (fees[2] * 1.0)) * fees[3];
        }
        answer.push_back(cost);
    }

    return answer;
}
