#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> arr1, vector<int> arr2) {
    return arr1[0] < arr2[0];
}

vector<vector<int>> add_end_time(vector<vector<string>> book_time) {

    vector<vector<int>> result;

    for (auto it : book_time) {

        vector<int> tmp;

        tmp.push_back(stoi(it[0].substr(0, 2)) * 60 + stoi(it[0].substr(3, 2)));

        int time = stoi(it[1].substr(0, 2));
        int minute = stoi(it[1].substr(3, 2));

        minute += 10;

        tmp.push_back(time * 60 + minute);
        result.push_back(tmp);
    }
    return result;
}

int solution(vector<vector<string>> book_time) {
    
    int answer = 0;
    vector<int> room;
    vector<vector<int>> book_int;

    book_int = add_end_time(book_time);

    sort(book_int.begin(), book_int.end(), comp);

    room.push_back(book_int[0][1]);
    for (int i = 1; i < book_int.size(); i++) {
        int start_time = book_int[i][0];
        int end_time = book_int[i][1];
        bool dir = false;
        for (int j = 0; j < room.size(); j++) {
            if (room[j] <= start_time) {
                room[j] = end_time;
                dir = true;
                break;
            }
        }

        if (!dir) {
            room.push_back(end_time);
        }
    }
    answer = room.size();
    return answer;
}