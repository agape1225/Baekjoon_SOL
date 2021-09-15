#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int format_time(string time) {

    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    int tmp = h * 60 + m;

    return tmp;
}

string format_str(int time) {
    string h = to_string((time / 60));
    time = time % 60;
    string m = to_string(time);

    if (h.size() == 1)
        h = '0' + h;

    if (m.size() == 1)
        m = '0' + m;

    return h + ':' + m;

}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ans = 0;

    sort(timetable.begin(), timetable.end());

    vector<int> bus_times;
    vector<int> crew_times;

    bus_times.push_back(540);

    for (int i = 1; i < n; i++) {
        bus_times.push_back(540 + (t * i));
    }

    for (auto it = timetable.begin(); it != timetable.end(); it++) {
        crew_times.push_back(format_time(*it));
    }

    int start = 0;
    for (auto it = bus_times.begin(); it != bus_times.end(); it++) {

        int count = 0;
        int index = start;

        while (index < crew_times.size() && crew_times[index] <= *it && count + 1 <= m) {
            count++;
            index++;
        }

        if (count >= m) {         //남는 자리가 없음

            ans = crew_times[index - 1] - 1;

        }
        else {                  //남는 자리 있음

            ans = *it;

        }

        start = index;
    }

    answer = format_str(ans);
    return answer;
}