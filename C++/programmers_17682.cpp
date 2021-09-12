#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    bool dir = false;

    vector<string> dart_points;
    int start = 0;
    int count = 1;
    for (int i = 0; i < dartResult.size() - 1; i++) {


        if (i == 0)
            continue;

        if ('0' <= dartResult[i] && dartResult[i] <= '9') {

            if ('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9') {

                dart_points.push_back(dartResult.substr(start, count));
                dir = false;
                start = i;
                count = 1;
                i++;
                count = 2;

            }
            else {
                if (count > 1) {
                    dart_points.push_back(dartResult.substr(start, count));
                    dir = false;
                    start = i;
                    count = 1;
                }
                else {
                    count++;
                }


            }


        }
        else
            count++;

        /*if ('0' <= dartResult[i] && dartResult[i] <= '9' && !('0' <= dartResult[i + 1] && dartResult[i + 1] <= '9')) {

            dart_points.push_back(dartResult.substr(start, count));
            dir = false;
            start = i;
            count = 1;


        }
        else
            count++;*/
    }

    dart_points.push_back(dartResult.substr(start, count + 1));

    stringstream ss;
    int past = 0;

    int ans[3];

    count = 0;
    for (auto it = dart_points.begin(); it != dart_points.end(); it++) {

        int num;
        string buff;

        ss.str(*it);
        ss >> num;

        //cout << num << ' ' << buff << endl;

        int index = 0;

        while ('0' <= (*it)[index] && (*it)[index] <= '9')
            index++;
        //cout << (*it) << ' ' << num << ' ' << index << endl;

        if ((*it)[index] == 'S') {



        }
        else if ((*it)[index] == 'D') {

            num = num * num;

        }
        else {

            num = num * num * num;

        }

        if (index != (*it).size() - 1) {

            if ((*it)[index + 1] == '*') {

                if (count > 0)
                    ans[count - 1] = ans[count - 1] * 2;
                num = num * 2;

            }
            else {
                num = num * -1;
            }

        }

        ans[count] = num;
        count++;

    }

    answer = ans[0] + ans[1] + ans[2];

    return answer;
}