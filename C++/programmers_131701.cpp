
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int size = elements.size();

    for (int i = 1; i < size; i++) {
        //1ºÎÅÍ size±îÁö µ¼


        int tmp = 0;

        for (int j = 0; j < i; j++) {
            tmp += elements[j];
        }

        s.insert(tmp);

        //cout << tmp << ' ';

        int left = 0;
        int right = left + i;
        int count = 1;

        while (count < size) {

            tmp = tmp - elements[left] + elements[right];
            s.insert(tmp);
            //cout << tmp << ' ';
            left = (left + 1) % size;
            right = (right + 1) % size;
            count++;


        }

        //cout << endl;

    }

    int tmp = 0;
    for (auto it : elements) {

        tmp += it;
    }


    s.insert(tmp);

    answer = s.size();

    return answer;
}