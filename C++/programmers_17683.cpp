#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> get_string_arr(string str) {
    string tmp = "";
    vector<string> ans;

    for (auto it : str) {
        if (it == ',') {

            ans.push_back(tmp);
            tmp = "";
        }
        else
            tmp += it;
    }

    ans.push_back(tmp);

    return ans;
}

int get_minute(string start, string end) {

    int start_h = stoi(start.substr(0, 2));
    int start_m = stoi(start.substr(3, 2));

    int end_h = stoi(end.substr(0, 2));
    int end_m = stoi(end.substr(3, 2));

    int sum_start = start_h * 60 + start_m;
    int sum_end = end_h * 60 + end_m;

    return sum_end - sum_start;
}

string get_hash_num(string str) {
    string hash[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    string tmp;
    int index;

    if (str[1] == '#') {
        tmp = str.substr(0, 2);
        index = 2;
    }
    else {
        tmp = str.substr(0, 1);
        index = 1;
    }
    string hash_arr = "";

    while (index < str.size()) {
        if (str[index] == '#') {
            tmp += str[index];
        }
        else {
            for (int j = 0; j < 12; j++) {
                if (hash[j] == tmp) {
                    if (j == 10) {
                        hash_arr += 'A';
                    }
                    else if (j == 11) {
                        hash_arr += 'B';
                    }
                    else
                        hash_arr += to_string(j);
                    break;
                }
            }
            tmp = str[index];
        }
        index++;
    }

    for (int j = 0; j < 12; j++) {
        if (hash[j] == tmp) {
            if (j == 10) {
                hash_arr += 'A';
            }
            else if (j == 11) {
                hash_arr += 'B';
            }
            else
                hash_arr += to_string(j);
            break;
        }
    }
    return hash_arr;

}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<pair<int, pair<string, string>>> dic;

    for (auto it : musicinfos) {
        vector<string> infos = get_string_arr(it);
        int play_time = get_minute(infos[0], infos[1]);
        string music_arr = "";
        string info = get_hash_num(infos[3]);

        for (int i = 0; i < (play_time / info.size()); i++) {
            music_arr += info;
        }
        music_arr += info.substr(0, (play_time % info.size()));
        cout << info << ' ' << music_arr << endl;
        dic.push_back(make_pair(play_time, make_pair(infos[2], music_arr)));
    }

    string hash_m = get_hash_num(m);
    int time = 0;
    cout << hash_m << endl;

    for (auto it : dic) {
        if (it.second.second.find(hash_m) != string::npos && time < it.second.second.size()) {
            answer = it.second.first;
            time = it.second.second.size();
        }
    }

    if (answer.empty())
        answer = "(None)";

    return answer;
}